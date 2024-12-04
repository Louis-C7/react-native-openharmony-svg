/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 *
 * This file incorporates code from another team within Huawei Device Co., Ltd, licensed under
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

// from ArkUI "frameworks/core/components/common/properties/decoration.cpp"
#pragma once

#include "Decoration.h"

namespace rnoh {
namespace svg {

void Gradient::AddColor(const GradientColor& color)
{
    colors_.push_back(color);
}

void Gradient::ClearColors()
{
    colors_.clear();
}

} // namespace svg
} // namespace rnoh
