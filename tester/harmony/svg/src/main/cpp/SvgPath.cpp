/*
 * Copyright (c) 2022-2024 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "SvgPath.h"
#include "utils/PathParserUtils.h"
#include <native_drawing/drawing_matrix.h>
#include "utils/PathParserUtils.h"

namespace rnoh {
namespace svg {

void SvgPath::setD(const std::string &d) {
    d_ = d;
    PathParserUtils parser;
    parser.mScale = scale_;
    path_ = std::move(parser.parse(d.c_str()));
    elements_ = parser.elements;
    for (PathElement &elem : elements_) {
        for (Point &point : elem.points) {
            point.x *= scale_;
            point.y *= scale_;
        }
    }
}

drawing::Path SvgPath::AsPath() {
    if (path_.get()) {
        return path_;
    }
    return drawing::Path();
}

} // namespace svg
} // namespace rnoh
