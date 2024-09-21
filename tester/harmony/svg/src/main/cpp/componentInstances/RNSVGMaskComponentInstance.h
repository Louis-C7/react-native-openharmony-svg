#pragma once
#include "RNSVGBaseComponentInstance.h"

namespace rnoh {
namespace svg {

class RNSVGMaskComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGMaskShadowNode> {

public:
    RNSVGMaskComponentInstance(Context context);
    void UpdateElementProps(SharedConcreteProps const &props) override;
    void onChildRemoved(ComponentInstance::Shared const &childComponentInstance) override {
        OnChildRemoveCommon(std::dynamic_pointer_cast<SvgHost>(childComponentInstance));
    }
};

} // namespace svg
} // namespace rnoh