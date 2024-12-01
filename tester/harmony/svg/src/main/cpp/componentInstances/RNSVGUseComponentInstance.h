#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgUse.h"

namespace rnoh {
namespace svg {

class RNSVGUseComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGUseShadowNode> {
public:
    RNSVGUseComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

    void onChildInserted(ComponentInstance::Shared const &childComponentInstance, std::size_t index) override {
        CppComponentInstance::onChildInserted(childComponentInstance, index);
        // svgUse don't draw children elements
    }

private:
    std::shared_ptr<SvgUse> m_svgUse = std::make_shared<SvgUse>();
};

} // namespace svg
} // namespace rnoh