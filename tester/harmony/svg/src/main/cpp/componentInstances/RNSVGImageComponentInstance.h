#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "svgImage/RNSVGImageShadowNode.h"
#include "SvgImage.h"

namespace rnoh {
namespace svg {

class RNSVGImageComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGImageShadowNode> {
public:
    RNSVGImageComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgImage> m_svgImage = std::make_shared<SvgImage>();
};

} // namespace svg
} // namespace rnoh