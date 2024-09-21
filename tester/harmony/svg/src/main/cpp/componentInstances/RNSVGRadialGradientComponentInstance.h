#pragma once
#include "RNSVGBaseComponentInstance.h"

namespace rnoh {
namespace svg {
class RNSVGRadialGradientComponentInstance
    : public RNSVGBaseComponentInstance<facebook::react::RNSVGRadialGradientShadowNode> {

public:
    RNSVGRadialGradientComponentInstance(Context context);

    void UpdateElementProps(SharedConcreteProps const &props) override;
};

} // namespace svg
} // namespace rnoh