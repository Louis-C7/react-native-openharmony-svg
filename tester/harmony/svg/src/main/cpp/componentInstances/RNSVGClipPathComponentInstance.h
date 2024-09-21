#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgShadowNodes.h"

namespace rnoh {
namespace svg {

class RNSVGClipPathComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGClipPathShadowNode> {
public:
    RNSVGClipPathComponentInstance(Context context);

    void UpdateElementProps(SharedConcreteProps const &props) override;

    void onChildRemoved(ComponentInstance::Shared const &childComponentInstance) override {
        OnChildRemoveCommon(std::dynamic_pointer_cast<SvgHost>(childComponentInstance));
    }
};

} // namespace svg
} // namespace rnoh