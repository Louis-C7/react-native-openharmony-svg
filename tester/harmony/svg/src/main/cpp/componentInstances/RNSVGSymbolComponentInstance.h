#pragma once

#include "RNSVGBaseComponentInstance.h"
#include "SvgSymbol.h"

namespace rnoh {
namespace svg {

class RNSVGSymbolComponentInstance : public RNSVGBaseComponentInstance<facebook::react::RNSVGSymbolShadowNode> {
public:
    RNSVGSymbolComponentInstance(Context context);

protected:
    void UpdateElementProps() override;

private:
    std::shared_ptr<SvgSymbol> m_svgSymbol = std::make_shared<SvgSymbol>();
};

} // namespace svg
} // namespace rnoh