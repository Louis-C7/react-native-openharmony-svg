#pragma once
#include "RNSVGBaseComponentInstance.h"
#include "SvgText.h"

namespace rnoh {
namespace svg {

class RNSVGTextComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGTextShadowNode> {


    std::shared_ptr<SvgText> m_svgText = std::make_shared<SvgText>();

public:
    RNSVGTextComponentInstance(Context context);

    void UpdateElementProps(SharedConcreteProps const &props) override;
};

} // namespace svg
} // namespace rnoh