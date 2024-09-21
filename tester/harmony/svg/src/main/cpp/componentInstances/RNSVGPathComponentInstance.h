#pragma once
#include "RNSVGBaseComponentInstance.h"

namespace rnoh {
namespace svg {

class RNSVGPathComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGPathShadowNode> {

public:
    RNSVGPathComponentInstance(Context context);

    void UpdateElementProps(SharedConcreteProps const &props) override;
};

} // namespace svg
} // namespace rnoh