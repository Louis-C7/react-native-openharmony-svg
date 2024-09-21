#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgTSpan.h"

namespace rnoh {
namespace svg {

class RNSVGTSpanComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGTSpanShadowNode> {

    std::shared_ptr<SvgTSpan> m_svgTSpan = std::make_shared<SvgTSpan>();

public:
    RNSVGTSpanComponentInstance(Context context);

    void UpdateElementProps(SharedConcreteProps const &props) override;
};

} // namespace svg
} // namespace rnoh