#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgMarker.h"

namespace rnoh {
namespace svg {

class RNSVGMarkerComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGMarkerShadowNode> {
public:
    RNSVGMarkerComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgMarker> m_svgMarker = std::make_shared<SvgMarker>();
};

} // namespace svg
} // namespace rnoh