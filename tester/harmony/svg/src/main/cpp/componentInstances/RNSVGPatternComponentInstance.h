#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgPattern.h"

namespace rnoh {
namespace svg {

class RNSVGPatternComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGPatternShadowNode> {
public:
    RNSVGPatternComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgPattern> m_svgPattern = std::make_shared<SvgPattern>();
};

} // namespace svg
} // namespace rnoh