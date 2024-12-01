#include "RNSVGDefsComponentInstance.h"
#include "SvgDefs.h"

namespace rnoh {
namespace svg {

RNSVGDefsComponentInstance::RNSVGDefsComponentInstance(Context context)
    : RNSVGBaseComponentInstance(std::move(context)) {
    SetSvgNode(m_svgDefs);
}

void RNSVGDefsComponentInstance::UpdateElementProps() { m_svgDefs->UpdateHrefRenderProps(m_props); }

} // namespace svg
} // namespace rnoh
