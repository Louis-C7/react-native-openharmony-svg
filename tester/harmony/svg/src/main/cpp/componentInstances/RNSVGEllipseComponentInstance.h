#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgEllipse.h"

namespace rnoh {
namespace svg {

class RNSVGEllipseComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGEllipseShadowNode> {
public:
    RNSVGEllipseComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgEllipse> m_svgEllipse = std::make_shared<SvgEllipse>();
};

} // namespace svg
} // namespace rnoh