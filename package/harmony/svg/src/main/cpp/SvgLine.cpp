/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include "SvgLine.h"

namespace rnoh {
namespace svg {

drawing::Path SvgLine::AsPath() {
    drawing::Path path;
    double x1 = relativeOnWidth(lineAttribute_.x1);
    double y1 = relativeOnHeight(lineAttribute_.y1);
    double x2 = relativeOnWidth(lineAttribute_.x2);
    double y2 = relativeOnHeight(lineAttribute_.y2);

    path.MoveTo(x1, y1);
    path.LineTo(x2, y2);

    elements_ = {PathElement(ElementType::kCGPathElementMoveToPoint, {Point(x1, y1)}),
                 PathElement(ElementType::kCGPathElementAddLineToPoint, {Point(x2, y2)})};
    return path;
};

} // namespace svg
} // namespace rnoh