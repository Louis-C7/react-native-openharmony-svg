#include "RNSVGPathComponentInstance.h"
#include "Props.h"
#include <react/renderer/core/ConcreteState.h>
#include <sstream>

namespace rnoh {
namespace svg {

RNSVGPathComponentInstance::RNSVGPathComponentInstance(Context context) : CppComponentInstance(std::move(context)) {
    SetSvgNode(std::make_shared<SvgPath>());
}

void RNSVGPathComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
     CppComponentInstance::onPropsChanged(props);
    LOG(INFO) << "[RNSVGPathComponentInstance] d: " << props->d;
    LOG(INFO) << "[RNSVGPathComponentInstance] Props->fill.payload: " << (uint32_t)*props->fill.payload;
    LOG(INFO) << "[RNSVGPathComponentInstance] Props->fill.type: " << props->fill.type;
    LOG(INFO) << "[RNSVGPathComponentInstance] Props->fill.payload meaningful: "
              << facebook::react::isColorMeaningful(props->fill.payload);
    auto svgPath = std::dynamic_pointer_cast<SvgPath>(GetSvgNode());
    svgPath->setD(props->d);

    svgPath->UpdateCommonProps(props);
}


SvgArkUINode &RNSVGPathComponentInstance::getLocalRootArkUINode() { return m_svgArkUINode; }

} // namespace svg
} // namespace rnoh
