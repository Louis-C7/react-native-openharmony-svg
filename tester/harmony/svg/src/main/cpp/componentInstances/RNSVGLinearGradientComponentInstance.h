#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgGradient.h"

namespace rnoh {
namespace svg {

class RNSVGLinearGradientComponentInstance
    : public RNSVGBaseComponentInstance<facebook::react::RNSVGLinearGradientShadowNode> {
public:
    RNSVGLinearGradientComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgGradient> m_svgLinearGradient = std::make_shared<SvgGradient>(GradientType::LINEAR);
};

} // namespace svg
} // namespace rnoh