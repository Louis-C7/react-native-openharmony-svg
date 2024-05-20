#include "RNSVGCircleComponentInstance.h"
#include "Props.h"
#include <react/renderer/core/ConcreteState.h>
#include <sstream>

namespace rnoh {
namespace svg {

RNSVGCircleComponentInstance::RNSVGCircleComponentInstance(Context context) : RNSVGBaseComponentInstance(std::move(context)) {
    SetSvgNode(std::make_shared<SvgCircle>());
}

void RNSVGCircleComponentInstance::UpdateElementProps(SharedConcreteProps const &props) {
    LOG(INFO) << "[RNSVGCircleComponentInstance] cx: " << props->cx;
    LOG(INFO) << "[RNSVGCircleComponentInstance] cy: " << props->cy;
    LOG(INFO) << "[RNSVGCircleComponentInstance] r: " << props->r;
    LOG(INFO) << "[RNSVGCircleComponentInstance] opacity: " << props->opacity;
    LOG(INFO) << "[RNSVGCircleComponentInstance] fill.payload: " << (uint32_t)*props->fill.payload;
    LOG(INFO) << "[RNSVGCircleComponentInstance] mask: " << props->mask;
    LOG(INFO) << "[SVG] <RNSVGCircleComponentInstance> propList size = " << props->propList.size();
    for (auto prop : props->propList) {
        LOG(INFO) << "[SVG] <RNSVGCircleComponentInstance> prop: " << prop;
    }
    
    // set attribute to svgCircle.
    auto svgCircle = std::dynamic_pointer_cast<SvgCircle>(GetSvgNode());
    svgCircle->SetX(props->cx);
    svgCircle->SetY(props->cy);
    svgCircle->SetR(props->r);
}
} // namespace svg
} // namespace rnoh
