#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "svgImage/RNSVGImageShadowNode.h"

namespace rnoh {
namespace svg {

class RNSVGImageComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGImageShadowNode> {

public:
    RNSVGImageComponentInstance(Context context);

    void UpdateElementProps(SharedConcreteProps const &props) override;
};

} // namespace svg
} // namespace rnoh