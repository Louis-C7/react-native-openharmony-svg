#include "RNSVGTSpanComponentInstance.h"
#include "SvgTSpan.h"

namespace rnoh {
namespace svg {

RNSVGTSpanComponentInstance::RNSVGTSpanComponentInstance(Context context)
    : RNSVGBaseComponentInstance(std::move(context)) {
    SetSvgNode(m_svgTSpan);
}

void RNSVGTSpanComponentInstance::UpdateElementProps() {
    m_svgTSpan->UpdateCommonProps(m_props);
    m_svgTSpan->content_ = m_props->content;
    m_svgTSpan->UpdateFontProps(m_props);
    m_svgTSpan->UpdateTextProps(m_props);
}

} // namespace svg
} // namespace rnoh
