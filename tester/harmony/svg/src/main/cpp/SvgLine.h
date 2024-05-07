#pragma once

#include "SvgGraphic.h"
#include <native_drawing/drawing_point.h>
#include <native_drawing/drawing_rect.h>

namespace rnoh {

class SvgLine : public SvgGraphic {
public:
    using Float = facebook::react::Float;
    SvgLine() = default;
    ~SvgLine() override = default;
    Float x1;
    Float y1;
    Float x2;
    Float y2;

    OH_Drawing_Path *AsPath() override {
        LOG(INFO) << "[SvgLine] AsPath";
        OH_Drawing_PathMoveTo(path_, vpToPx(x1), vpToPx(y1));
        OH_Drawing_PathLineTo(path_, vpToPx(x2), vpToPx(y2));
        return path_;
    };
};

} // namespace rnoh