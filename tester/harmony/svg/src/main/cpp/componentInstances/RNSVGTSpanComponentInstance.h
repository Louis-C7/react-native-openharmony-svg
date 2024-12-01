#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgTSpan.h"

namespace rnoh {
namespace svg {

class RNSVGTSpanComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGTSpanShadowNode> {
public:
    RNSVGTSpanComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgTSpan> m_svgTSpan = std::make_shared<SvgTSpan>();
};

} // namespace svg
} // namespace rnoh