#include "RNSVGLineComponentInstance.h"

namespace rnoh {
namespace svg {

RNSVGLineComponentInstance::RNSVGLineComponentInstance(Context context)
    : RNSVGBaseComponentInstance(std::move(context)) {
    SetSvgNode(m_svgLine);
}

void RNSVGLineComponentInstance::UpdateElementProps() {
    m_svgLine->UpdateCommonProps(m_props);
    m_svgLine->SetX1(m_props->x1);
    m_svgLine->SetY1(m_props->y1);
    m_svgLine->SetX2(m_props->x2);
    m_svgLine->SetY2(m_props->y2);
}

} // namespace svg
} // namespace rnoh
