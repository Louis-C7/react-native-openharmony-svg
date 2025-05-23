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

// from ArkUI  "frameworks/base/geometry/offset.h"
#pragma once

#include <cmath>
#include <limits>

#include "properties/Size.h"
#include "utils/SvgUtils.h"

namespace rnoh {
namespace svg {

class Offset {
public:
    Offset() = default;
    ~Offset() = default;
    Offset(double deltaX, double deltaY) : deltaX_(deltaX), deltaY_(deltaY) {}

    void Reset() {
        deltaX_ = 0.0;
        deltaY_ = 0.0;
    }

    static Offset Zero() { return Offset(); }

    static Offset ErrorOffset() {
        return Offset((std::numeric_limits<double>::max)(), (std::numeric_limits<double>::max)());
    }

    bool IsZero() const { return operator==(Offset()); }

    bool IsErrorOffset() const { return operator==(ErrorOffset()); }

    double GetX() const { return deltaX_; }

    double GetY() const { return deltaY_; }

    void SetX(double x) { deltaX_ = x; }

    void SetY(double y) { deltaY_ = y; }

    void AddX(double x) { deltaX_ += x; }

    void AddY(double y) { deltaY_ += y; }

    double GetDistance() const { return std::sqrt((deltaX_ * deltaX_) + (deltaY_ * deltaY_)); }

    Offset operator+(const Offset &offset) const { return Offset(deltaX_ + offset.deltaX_, deltaY_ + offset.deltaY_); }

    Offset operator+(const Size &size) const { return Offset(deltaX_ + size.Width(), deltaY_ + size.Height()); }

    Offset operator-(const Offset &offset) const { return Offset(deltaX_ - offset.deltaX_, deltaY_ - offset.deltaY_); }

    Offset operator-(const Size &size) const { return Offset(deltaX_ - size.Width(), deltaY_ - size.Height()); }

    Offset operator*(double value) const { return Offset(deltaX_ * value, deltaY_ * value); }

    Offset operator/(double value) const {
        if (NearZero(value)) {
            return ErrorOffset();
        }
        return Offset(deltaX_ / value, deltaY_ / value);
    }

    Offset &operator+=(const Offset &offset) {
        deltaX_ += offset.deltaX_;
        deltaY_ += offset.deltaY_;
        return *this;
    }

    Offset &operator-=(const Offset &offset) {
        deltaX_ -= offset.deltaX_;
        deltaY_ -= offset.deltaY_;
        return *this;
    }

    bool operator==(const Offset &offset) const {
        return NearEqual(deltaX_, offset.deltaX_) && NearEqual(deltaY_, offset.deltaY_);
    }

    bool operator!=(const Offset &offset) const { return !operator==(offset); }

    std::string ToString() const {
        std::stringstream ss;
        ss << "Offset (" << std::fixed << std::setprecision(2) << deltaX_ << ", " << deltaY_ << ")";
        std::string output = ss.str();
        return output;
    }

    bool IsPositiveOffset() const { return deltaX_ >= 0 && deltaY_ >= 0; }

private:
    double deltaX_ = 0.0;
    double deltaY_ = 0.0;
};

} // namespace svg
} // namespace rnoh
