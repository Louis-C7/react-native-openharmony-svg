#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgLine.h"

namespace rnoh {
namespace svg {

class RNSVGLineComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGLineShadowNode> {
public:
    RNSVGLineComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgLine> m_svgLine = std::make_shared<SvgLine>();
};

} // namespace svg
} // namespace rnoh