#pragma once

#include "RNSVGBaseComponentInstance.h"

namespace rnoh {
namespace svg {

class RNSVGEllipseComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGEllipseShadowNode> {
public:
    RNSVGEllipseComponentInstance(Context context);

    void UpdateElementProps(SharedConcreteProps const &props) override;
};

} // namespace svg
} // namespace rnoh