/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include "SvgMarker.h"
#include "properties/Rect.h"
#include "properties/ViewBox.h"
#include <string>
#include <cstdlib>
#include <vector>

namespace rnoh {
namespace svg {

void SvgMarker::renderMarker(OH_Drawing_Canvas *canvas, const SvgMarkerPosition &position, float strokeWidth) {
    const auto count = OH_Drawing_CanvasGetSaveCount(canvas);
    saveAndSetupCanvas(canvas, cTM_);

    if (markerTransform.get() != nullptr) {
        markerTransform.Reset();
    }
    Point origin = position.origin;
    markerTransform.Translate(origin.x, origin.y);
    double markerAngle = (markerAttribute_.orient == "auto") ? -1 : std::atof(markerAttribute_.orient.c_str());
    float degrees = 180 + (markerAngle == -1 ? position.angle : static_cast<float>(markerAngle));
    // fix me? float rad = deg2rad(angle); this code only in ios
    markerTransform.PreRotate(degrees, 0, 0);

    if (markerAttribute_.markerUnits == "strokeWidth") {
        markerTransform.PreScale(strokeWidth / scale_, strokeWidth / scale_, 0, 0);
    }
    if (!markerAttribute_.align.empty()) {
        double width = relativeOnWidth(markerAttribute_.markerWidth) / scale_;
        double height = relativeOnHeight(markerAttribute_.markerHeight) / scale_;
        Rect eRect(0, 0, width, height);
        Rect vbRect(markerAttribute_.minX.ConvertToPx(scale_), markerAttribute_.minY.ConvertToPx(scale_),
                    markerAttribute_.minX.ConvertToPx(scale_) + markerAttribute_.vbWidth.ConvertToPx(scale_),
                    markerAttribute_.minY.ConvertToPx(scale_) + markerAttribute_.vbHeight.ConvertToPx(scale_));
        if (vbRect.IsValid()) {
            drawing::Matrix viewBoxMatrix =
                ViewBox::getTransform(vbRect, eRect, markerAttribute_.align, markerAttribute_.meetOrSlice);
            float sx = viewBoxMatrix.GetValue(0);
            float sy = viewBoxMatrix.GetValue(4);
            markerTransform.PreScale(sx, sy, 0, 0);
        }
    }

    double x = relativeOnWidth(markerAttribute_.refX);
    double y = relativeOnHeight(markerAttribute_.refY);
    markerTransform.PreTranslate(-x, -y);
    OH_Drawing_CanvasConcatMatrix(canvas, markerTransform.get());

    OnDrawTraversed(canvas);

    OH_Drawing_CanvasRestoreToCount(canvas, count);
}

} // namespace svg
} // namespace rnoh