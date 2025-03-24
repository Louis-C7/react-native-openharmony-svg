/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#pragma once

#include "SvgGroup.h"
#include "SvgText.h"
#include <native_drawing/drawing_text_typography.h>
#include "utils/GlyphContext.h"
#include "properties/Font.h"
#include "TextBase.h"

namespace rnoh {
namespace svg {

class SvgTextPath : public SvgGroup, public TextBase {
public:
    SvgTextPath() {
        hrefFill_ = true;
        hrefRender_ = true;
        passStyle_ = true;
        inheritStyle_ = true;
        drawTraversed_ = true;
    }
    ~SvgTextPath() override = default;

    void OnDraw(OH_Drawing_Canvas *canvas) override;

    void SetContext(std::shared_ptr<GlyphContext> context) { glyphCtx_ = context; }

    drawing::Path getTextPath();

    TextPathMidLine getMidLine() const { return midLine_; }

    TextPathSide getSide() const { return side_; }

    double getStartOffset() const { return startOffset_; }

    TextPathSide side_{TextPathSide::left};
    TextPathMidLine midLine_{TextPathMidLine::sharp};
    TextPathMethod method_{TextPathMethod::align};
    TextPathSpacing spacing_{TextPathSpacing::Exact};
    double startOffset_;
    std::string href_;
};

} // namespace svg
} // namespace rnoh