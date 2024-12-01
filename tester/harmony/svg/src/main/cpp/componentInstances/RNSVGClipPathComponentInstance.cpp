#include "RNSVGClipPathComponentInstance.h"

namespace rnoh {
namespace svg {

RNSVGClipPathComponentInstance::RNSVGClipPathComponentInstance(Context context)
    : RNSVGBaseComponentInstance(std::move(context)) {
    SetSvgNode(m_svgClipPath);
}

void RNSVGClipPathComponentInstance::UpdateElementProps() { m_svgClipPath->UpdateCommonProps(m_props); }

} // namespace svg
} // namespace rnoh
