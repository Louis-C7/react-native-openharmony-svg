/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include "SvgSymbol.h"

namespace rnoh {
namespace svg {

void SvgSymbol::drawSymbol(OH_Drawing_Canvas *canvas, float width, float height) {
    if (!mAlign.empty()) {
        Rect vbRect(vpToPx(mMinX), vpToPx(mMinY), vpToPx(mMinX + mVbWidth), vpToPx(mMinY + mVbHeight));
        Rect eRect(0, 0, vpToPx(width), vpToPx(height));
        if (vbRect.IsValid()) {
            drawing::Matrix viewBoxMatrix = ViewBox::getTransform(vbRect, eRect, mAlign, mMeetOrSlice);
            OH_Drawing_CanvasConcatMatrix(canvas, viewBoxMatrix.get());
        }
        Draw(canvas);
    }
}

} // namespace svg
} // namespace rnoh