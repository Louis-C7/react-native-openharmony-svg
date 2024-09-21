#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgShadowNodes.h"

namespace rnoh {
namespace svg {

class RNSVGCircleComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGCircleShadowNode> {

public:
    RNSVGCircleComponentInstance(Context context);
    void UpdateElementProps(SharedConcreteProps const &props) override;
};

} // namespace svg
} // namespace rnoh