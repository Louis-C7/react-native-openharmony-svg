#include "RNSVGImageComponentInstance.h"

namespace rnoh {
namespace svg {

RNSVGImageComponentInstance::RNSVGImageComponentInstance(Context context)
    : RNSVGBaseComponentInstance(std::move(context)) {
    SetSvgNode(m_svgImage);
}

void RNSVGImageComponentInstance::UpdateElementProps() {
    if (m_deps != nullptr && !m_deps->rnInstance.expired()) {
        auto rnInstance = m_deps->rnInstance.lock();
        if (rnInstance != nullptr) {
            auto nativeResourceManager = rnInstance->getNativeResourceManager();
            m_svgImage->setNativeResourceManager(nativeResourceManager);
        }
    }
    m_svgImage->UpdateCommonProps(m_props);
    m_svgImage->SetX(m_props->x);
    m_svgImage->SetY(m_props->y);
    m_svgImage->SetWidth(m_props->width);
    m_svgImage->SetHeight(m_props->height);
    m_svgImage->SetAlign(m_props->align);
    m_svgImage->SetMeetOrSlice(m_props->meetOrSlice);
    m_svgImage->SetImageSource(m_props->src);
}

} // namespace svg
} // namespace rnoh
