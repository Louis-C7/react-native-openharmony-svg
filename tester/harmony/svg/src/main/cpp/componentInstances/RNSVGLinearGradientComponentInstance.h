#pragma once

#include "RNSVGBaseComponentInstance.h"

namespace rnoh {
namespace svg {
class RNSVGLinearGradientComponentInstance
    : public RNSVGBaseComponentInstance<facebook::react::RNSVGLinearGradientShadowNode> {

public:
    RNSVGLinearGradientComponentInstance(Context context);

    void UpdateElementProps(SharedConcreteProps const &props) override;

    void onChildRemoved(ComponentInstance::Shared const &childComponentInstance) override {
        OnChildRemoveCommon(std::dynamic_pointer_cast<SvgHost>(childComponentInstance));
    }
};

} // namespace svg
} // namespace rnoh