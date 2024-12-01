#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgTextPath.h"

namespace rnoh {
namespace svg {

class RNSVGTextPathComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGTextPathShadowNode> {
public:
    RNSVGTextPathComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgTextPath> m_svgTP = std::make_shared<SvgTextPath>();
};

} // namespace svg
} // namespace rnoh