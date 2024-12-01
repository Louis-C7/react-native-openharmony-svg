#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgDefs.h"

namespace rnoh {
namespace svg {

class RNSVGDefsComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGDefsShadowNode> {

public:
    RNSVGDefsComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgDefs> m_svgDefs = std::make_shared<SvgDefs>();
};

} // namespace svg
} // namespace rnoh