#include "RNSVGEllipseComponentInstance.h"

namespace rnoh {
namespace svg {

RNSVGEllipseComponentInstance::RNSVGEllipseComponentInstance(Context context)
    : RNSVGBaseComponentInstance(std::move(context)) {
    SetSvgNode(m_svgEllipse);
}

void RNSVGEllipseComponentInstance::UpdateElementProps() {
    m_svgEllipse->UpdateCommonProps(m_props);
    m_svgEllipse->SetCX(m_props->cx);
    m_svgEllipse->SetCY(m_props->cy);
    m_svgEllipse->SetRX(m_props->rx);
    m_svgEllipse->SetRY(m_props->ry);
}

} // namespace svg
} // namespace rnoh
