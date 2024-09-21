#pragma once

#include "RNSVGBaseComponentInstance.h"

namespace rnoh {
namespace svg {

class RNSVGMarkerComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGMarkerShadowNode> {
    
public:
    RNSVGMarkerComponentInstance(Context context);
    void UpdateElementProps(SharedConcreteProps const &props) override;
};

} // namespace svg
} // namespace rnoh