#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgPath.h"

namespace rnoh {
namespace svg {

class RNSVGPathComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGPathShadowNode> {
public:
    RNSVGPathComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgPath> m_svgPath = std::make_shared<SvgPath>();
    std::string m_cacheD;
};

} // namespace svg
} // namespace rnoh