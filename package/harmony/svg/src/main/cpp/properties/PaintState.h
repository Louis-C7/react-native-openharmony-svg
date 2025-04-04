/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 *
 * This file incorporates from the OpenHarmony project, licensed under
 * the Apache License, Version 2.0. Specifically:
 * - [OpenHarmony/arkui_ace_engine] (https://gitee.com/openharmony/arkui_ace_engine)
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy
 * of the License at:
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

// from ArkUI "frameworks/core/components/common/properties/paint_state.h"
#pragma once

#include "properties/Color.h"
#include "utils/SvgUtils.h"


namespace rnoh {
namespace svg {

struct BezierCurveParam {
    double cp1x = 0.0; // first bezier point x
    double cp1y = 0.0; // first bezier point y
    double cp2x = 0.0; // second bezier point x
    double cp2y = 0.0; // second bezier point y
    double x = 0.0;    // end point x
    double y = 0.0;    // end point y
};

struct QuadraticCurveParam {
    double cpx = 0.0; // bezier point x
    double cpy = 0.0; // bezier point y
    double x = 0.0;   // end point x
    double y = 0.0;   // end point y
};

struct ArcParam {
    double x = 0.0;             // point x of the circle
    double y = 0.0;             // point y of the circle
    double radius = 0.0;        // radius of the circle
    double startAngle = 0.0;    // start angle of the circle
    double endAngle = 0.0;      // end angle of the circle
    bool anticlockwise = false; // is draw clock wise or not
};

struct ArcToParam {
    double x1 = 0.0;     // start point x
    double y1 = 0.0;     // start point y
    double x2 = 0.0;     // end point x
    double y2 = 0.0;     // end point y
    double radius = 0.0; // radius of the circle
};

struct EllipseParam {
    double x = 0.0;             // point x of the ellipse
    double y = 0.0;             // point y of the ellipse
    double radiusX = 0.0;       // x axis radius of the ellipse
    double radiusY = 0.0;       // y axis radius of the ellipse
    double rotation = 0.0;      // rotation angle of the ellipse
    double startAngle = 0.0;    // start angle of the ellipse
    double endAngle = 0.0;      // end angle of the ellipse
    bool anticlockwise = false; // is draw clock wise or not
};

struct TransformParam {
    double scaleX = 0.0;
    double skewX = 0.0;
    double skewY = 0.0;
    double scaleY = 0.0;
    double translateX = 0.0;
    double translateY = 0.0;
};

struct LineDashParam {
    std::vector<double> lineDash;
    double dashOffset = 0.0;
};

struct CanvasImage {
    int32_t flag = 0;
    double sx = 0.0;
    double sy = 0.0;
    double sWidth = 0.0;
    double sHeight = 0.0;
    double dx = 0.0;
    double dy = 0.0;
    double dWidth = 0.0;
    double dHeight = 0.0;
    std::string src;
    int32_t instanceId = 0;
};

struct TextMetrics {
    double width = 0;
    double height = 0;
    double actualBoundingBoxLeft = 0;
    double actualBoundingBoxRight = 0;
    double actualBoundingBoxAscent = 0;
    double actualBoundingBoxDescent = 0;
    double alphabeticBaseline = 0;
    double emHeightAscent = 0;
    double emHeightDescent = 0;
    double fontBoundingBoxAscent = 0;
    double fontBoundingBoxDescent = 0;
    double hangingBaseline = 0;
    double ideographicBaseline = 0;
};

enum class ContextType {
    RENDER_2D,
    RENDER_3D,
};

enum class CanvasUnit {
    DEFAULT = 0,
    PX,
};

// following the definition of FillType in skPath
enum class CanvasFillRule {
    NONZERO = 0,
    EVENODD,
};

// following the definition in skPaint
enum class LineCapStyle {
    BUTT = 0,
    ROUND,
    SQUARE,
};

enum class LineJoinStyle {
    MITER = 0,
    ROUND,
    BEVEL,
};

enum class CompositeOperation {
    SOURCE_OVER = 0,
    SOURCE_ATOP,
    SOURCE_IN,
    SOURCE_OUT,
    DESTINATION_OVER,
    DESTINATION_ATOP,
    DESTINATION_IN,
    DESTINATION_OUT,
    LIGHTER,
    COPY,
    XOR,
};

enum class PaintStyle { NONE = 0, Color, Gradient, ImagePattern };

class PaintState {
public:
    const Color &GetColor() const { return color_; }

    void SetColor(const Color &color) {
        paintStyle_ = PaintStyle::Color;
        color_ = color;
    }

    int32_t GetId() const { return id_; }

    void SetId(int32_t id) { id_ = id; }

    PaintStyle GetPaintStyle() const { return paintStyle_; }

protected:
    Color color_ = Color::BLACK;
    int32_t id_ = 0;
    PaintStyle paintStyle_ = PaintStyle::Color;
};

class StrokePaintState : public PaintState {
public:
    LineCapStyle GetLineCap() const { return lineCap_; }

    void SetLineCap(LineCapStyle lineCap) { lineCap_ = lineCap; }

    LineJoinStyle GetLineJoin() const { return lineJoin_; }

    void SetLineJoin(LineJoinStyle lineJoin) { lineJoin_ = lineJoin; }

    double GetLineWidth() const { return lineWidth_; }

    void SetLineWidth(double lineWidth) { lineWidth_ = lineWidth; }

    double GetMiterLimit() const { return miterLimit_; }

    void SetMiterLimit(double miterLimit) { miterLimit_ = miterLimit; }

    LineDashParam GetLineDash() const { return lineDash_; }

    void SetLineDash(const LineDashParam &lineDash) { lineDash_ = lineDash; }

    void SetLineDashOffset(double offset) { lineDash_.dashOffset = offset; }

    void SetLineDash(const std::vector<double> &segments) { lineDash_.lineDash = segments; }

private:
    LineCapStyle lineCap_ = LineCapStyle::BUTT;
    LineJoinStyle lineJoin_ = LineJoinStyle::MITER;

    double lineWidth_ = 1.0; // default lineWidth

    double miterLimit_ = 10.0; // default miterLimit
    LineDashParam lineDash_;
};

class GlobalPaintState {
public:
    double GetAlpha() const { return alpha_; }

    void SetAlpha(double alpha) { alpha_ = alpha; }

    CompositeOperation GetType() const { return type_; }

    void SetType(CompositeOperation type) { type_ = type; }

    bool HasGlobalAlpha() const { return !NearEqual(alpha_, -1.0); }

private:
    double alpha_ = -1.0;
    CompositeOperation type_ = CompositeOperation::SOURCE_OVER;
};

} // namespace svg
} // namespace rnoh
