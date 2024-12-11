/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "svgImage/RNSVGImageShadowNode.h"
#include "SvgImage.h"

namespace rnoh {
namespace svg {

class RNSVGImageComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGImageShadowNode> {
public:
    explicit RNSVGImageComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgImage> m_svgImage = std::make_shared<SvgImage>();
};

} // namespace svg
} // namespace rnoh