#include "RNSVGGroupComponentInstance.h"

namespace rnoh {
namespace svg {

RNSVGGroupComponentInstance::RNSVGGroupComponentInstance(Context context)
    : RNSVGBaseComponentInstance(std::move(context)) {
    SetSvgNode(m_svgGroup);
}

void RNSVGGroupComponentInstance::UpdateElementProps() {
    m_svgGroup->UpdateCommonProps(m_props);
    m_svgGroup->UpdateFontProps(m_props);
}

} // namespace svg
} // namespace rnoh