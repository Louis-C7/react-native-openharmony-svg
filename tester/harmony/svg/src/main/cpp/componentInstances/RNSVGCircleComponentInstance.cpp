#include "RNSVGCircleComponentInstance.h"

namespace rnoh {
namespace svg {

RNSVGCircleComponentInstance::RNSVGCircleComponentInstance(Context context)
    : RNSVGBaseComponentInstance(std::move(context)) {
    SetSvgNode(m_svgCircle);
}

void RNSVGCircleComponentInstance::UpdateElementProps() {
    // set attribute to svgCircle.
    m_svgCircle->UpdateCommonProps(m_props);
    m_svgCircle->SetX(m_props->cx);
    m_svgCircle->SetY(m_props->cy);
    m_svgCircle->SetR(m_props->r);
}

} // namespace svg
} // namespace rnoh
