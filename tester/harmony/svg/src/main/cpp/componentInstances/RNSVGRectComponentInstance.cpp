#include "RNSVGRectComponentInstance.h"
#include "Props.h"
#include <react/renderer/core/ConcreteState.h>
#include <sstream>

namespace rnoh {

RNSVGRectComponentInstance::RNSVGRectComponentInstance(Context context) : CppComponentInstance(std::move(context)) {
    SetSvgNode(std::make_shared<SvgRect>());
}

void RNSVGRectComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
     CppComponentInstance::onPropsChanged(props);
    LOG(INFO) << "[RNSVGRectComponentInstance] Props->fill.payload: " << (uint32_t)*props->fill.payload;
    LOG(INFO) << "[RNSVGRectComponentInstance] Props->stroke.payload: " << (uint32_t)*props->stroke.payload;
    LOG(INFO) << "[RNSVGRectComponentInstance] Props->strokeWidth: " << props->strokeWidth;
    LOG(INFO) << "[RNSVGRectComponentInstance] Props->rx: " << props->rx;
    LOG(INFO) << "[RNSVGRectComponentInstance] Props->ry: " << props->ry;
    LOG(INFO) << "[RNSVGRectComponentInstance] Props->propList size: " << props->propList.size();
    for (auto &prop : props->propList) {
        LOG(INFO) << "[RNSVGRectComponentInstance] Props->propList: " << prop;
    }
    auto svgRect = std::dynamic_pointer_cast<SvgRect>(GetSvgNode());
    svgRect->x = std::stod(props->x);
    svgRect->y = std::stod(props->y);
    svgRect->width = std::stod(props->width);
    svgRect->height = std::stod(props->height);
    if (props->rx.size() != 0) {
        // TODO fix: use std::stod cpp crash
        svgRect->rx = std::stof(props->rx);
    }
    if (props->ry.size() != 0) {
        // TODO fix: use std::stod cpp crash
        svgRect->ry = std::stof(props->ry);
    }
    svgRect->setBrushColor((uint32_t)*props->fill.payload);
    svgRect->setBrushOpacity(props->fillOpacity);
    svgRect->setStrokeColor((uint32_t)*props->stroke.payload);
    svgRect->setStrokeOpacity(props->strokeOpacity);
    svgRect->setStrokeLineWith(props->strokeWidth);
    svgRect->setStrokeDasharray(props->strokeDasharray);
    svgRect->setStrokeDashoffset(props->strokeDashoffset);
    svgRect->setStrokeLineCap(props->strokeLinecap);
    svgRect->setStrokeLineJoin(props->strokeLinejoin);
    svgRect->setStrokeMiterlimit(props->strokeMiterlimit);
    svgRect->setStrokeOpacity(props->strokeOpacity);
}

SvgArkUINode &RNSVGRectComponentInstance::getLocalRootArkUINode() { return m_svgArkUINode; }

} // namespace rnoh
