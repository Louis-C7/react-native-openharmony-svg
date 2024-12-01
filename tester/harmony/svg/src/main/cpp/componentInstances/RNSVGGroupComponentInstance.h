#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgGroup.h"

namespace rnoh {
namespace svg {

class RNSVGGroupComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGGroupShadowNode> {
public:
    RNSVGGroupComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgGroup> m_svgGroup = std::make_shared<SvgGroup>();
};

} // namespace svg
} // namespace rnoh