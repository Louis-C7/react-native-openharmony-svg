#pragma once
#include "RNSVGBaseComponentInstance.h"
#include "SvgText.h"

namespace rnoh {
namespace svg {

class RNSVGTextComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGTextShadowNode> {
public:
    RNSVGTextComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgText> m_svgText = std::make_shared<SvgText>();
};

} // namespace svg
} // namespace rnoh