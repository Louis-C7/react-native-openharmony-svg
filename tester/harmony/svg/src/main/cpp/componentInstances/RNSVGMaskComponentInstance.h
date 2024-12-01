#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgMask.h"

namespace rnoh {
namespace svg {

class RNSVGMaskComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGMaskShadowNode> {
public:
    RNSVGMaskComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgMask> m_svgMask = std::make_shared<SvgMask>();
};

} // namespace svg
} // namespace rnoh