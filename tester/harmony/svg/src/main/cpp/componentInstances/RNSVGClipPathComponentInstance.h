#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgClipPath.h"

namespace rnoh {
namespace svg {

class RNSVGClipPathComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGClipPathShadowNode> {
public:
    RNSVGClipPathComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgClipPath> m_svgClipPath = std::make_shared<SvgClipPath>();
};

} // namespace svg
} // namespace rnoh