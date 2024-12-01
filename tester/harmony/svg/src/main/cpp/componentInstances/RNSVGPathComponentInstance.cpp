#include "RNSVGPathComponentInstance.h"

namespace rnoh {
namespace svg {

RNSVGPathComponentInstance::RNSVGPathComponentInstance(Context context)
    : RNSVGBaseComponentInstance(std::move(context)) {
    SetSvgNode(m_svgPath);
}

void RNSVGPathComponentInstance::UpdateElementProps() {
    DLOG(INFO) << "[RNSVGPathCI] d: " << m_props->d;
    DLOG(INFO) << "[RNSVGPathCI] pointScaleFactor: " << m_layoutMetrics.pointScaleFactor;
    m_svgPath->UpdateCommonProps(m_props);
    if (m_cacheD.empty() || m_cacheD != m_props->d) {
        m_svgPath->setD(m_props->d);
        m_cacheD = m_props->d;
    }
}

} // namespace svg
} // namespace rnoh
