#include "RNSVGImageComponentInstance.h"
#include "SvgImage.h"

namespace rnoh {
namespace svg {

RNSVGImageComponentInstance::RNSVGImageComponentInstance(Context context)
    : RNSVGBaseComponentInstance(std::move(context)) {
    SetSvgNode(std::make_shared<SvgImage>());
}

void RNSVGImageComponentInstance::UpdateElementProps(SharedConcreteProps const &props) {
    auto svgImage = std::dynamic_pointer_cast<SvgImage>(GetSvgNode());
    if (m_deps != nullptr && !m_deps->rnInstance.expired()) {
        auto rnInstance = m_deps->rnInstance.lock();
        if (rnInstance != nullptr) {
            auto nativeResourceManager = rnInstance->getNativeResourceManager();
            svgImage->setNativeResourceManager(nativeResourceManager);
        }
    }
    svgImage->UpdateCommonProps(props);
    svgImage->SetX(props->x);
    svgImage->SetY(props->y);
    svgImage->SetWidth(props->width);
    svgImage->SetHeight(props->height);
    svgImage->SetAlign(props->align);
    svgImage->SetMeetOrSlice(props->meetOrSlice);
    svgImage->SetImageSource(props->src);
    svgImage->setBundlePath(getBundlePath());
}

std::string RNSVGImageComponentInstance::getBundlePath() {
    if (!m_deps) {
        return "";
    }
    auto rnInstance = m_deps->rnInstance.lock();
    if (!rnInstance) {
        return "";
    }
    auto internalInstance = std::dynamic_pointer_cast<RNInstanceInternal>(rnInstance);
    if (!internalInstance) {
        return "";
    }
    std::string bundlePath = internalInstance->getBundlePath();
    if (bundlePath.empty()) {
        return "";
    }
    return bundlePath;
}

} // namespace svg
} // namespace rnoh
