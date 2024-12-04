/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include "RoundRect.h"

namespace rnoh {
namespace drawing {

RoundRect::RoundRect(Rect rect, float rx, float ry)
    : rect_(std::move(rect)),
      roundRect_(UniqueNativeRoundRect(OH_Drawing_RoundRectCreate(rect_.get(), rx, ry), &OH_Drawing_RoundRectDestroy)) {
}
void RoundRect::SetCorner(CornerPos pos, CornerRadii radii) {
    OH_Drawing_RoundRectSetCorner(roundRect_.get(), pos, radii);
}
RoundRect::CornerRadii RoundRect::GetCorner(CornerPos pos) {
    return OH_Drawing_RoundRectGetCorner(roundRect_.get(), pos);
}

} // namespace drawing
} // namespace rnoh