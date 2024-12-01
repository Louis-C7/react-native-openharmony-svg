#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgCircle.h"

namespace rnoh {
namespace svg {

class RNSVGCircleComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGCircleShadowNode> {
public:
    RNSVGCircleComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgCircle> m_svgCircle = std::make_shared<SvgCircle>();
};

} // namespace svg
} // namespace rnoh