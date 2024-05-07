#pragma once

#include "RNOH/CppComponentInstance.h"
#include <folly/dynamic.h>
#include "SvgArkUINode.h"
#include "ShadowNodes.h"
#include "SvgGroup.h"

namespace rnoh {
class RNSVGGroupComponentInstance : public CppComponentInstance<facebook::react::RNSVGGroupShadowNode>, public SvgHost {

private:
    SvgArkUINode m_svgArkUINode;

public:
    RNSVGGroupComponentInstance(Context context);
    
    void onChildInserted(ComponentInstance::Shared const &childComponentInstance, std::size_t index) override{
        auto childSvgHost = std::dynamic_pointer_cast<SvgHost>(childComponentInstance);
        if (childSvgHost) {
            GetSvgNode()->AppendChild(childSvgHost->GetSvgNode());
        }
    }
    
    void onChildRemoved(ComponentInstance::Shared const &childComponentInstance) override{
        
    }
    
    SvgArkUINode &getLocalRootArkUINode() override;
    
    void onPropsChanged(SharedConcreteProps const &props) override;
};
} // namespace rnoh