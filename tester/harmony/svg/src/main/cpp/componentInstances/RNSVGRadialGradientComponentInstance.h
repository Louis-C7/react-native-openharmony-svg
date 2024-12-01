#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgGradient.h"

namespace rnoh {
namespace svg {

class RNSVGRadialGradientComponentInstance
    : public RNSVGBaseComponentInstance<facebook::react::RNSVGRadialGradientShadowNode> {
public:
    RNSVGRadialGradientComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgGradient> m_svgRadialGradient = std::make_shared<SvgGradient>(GradientType::RADIAL);
};

} // namespace svg
} // namespace rnoh