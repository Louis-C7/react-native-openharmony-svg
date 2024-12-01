#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgRect.h"

namespace rnoh {
namespace svg {

class RNSVGRectComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGRectShadowNode> {
public:
    RNSVGRectComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgRect> m_svgRect = std::make_shared<SvgRect>();
};

} // namespace svg
} // namespace rnoh