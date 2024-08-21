#include "SvgUse.h"

namespace rnoh {
namespace svg {

void SvgUse::OnDraw(OH_Drawing_Canvas *canvas) {
    DLOG(INFO) << "[SvgUse::OnDraw] : start";
    auto svgContext = GetContext();
    if (!svgContext) {
        DLOG(INFO) << "[SvgUse::OnDraw] : svgContext is a null ptr";
        return;
    }

    auto refSvgNode = svgContext->GetSvgNodeById(href);
    if (!refSvgNode) {
        DLOG(INFO) << "[SvgUse::OnDraw] : refSvgNode is a null ptr";
        return;
    }

    if (x != 0 || y != 0) {
        OH_Drawing_CanvasTranslate(canvas, vpToPx(x), vpToPx(y));
    }

    AttributeScope scope(refSvgNode);
    std::shared_ptr<SvgSymbol> svgSymbol = std::dynamic_pointer_cast<SvgSymbol>(refSvgNode);

    refSvgNode->InheritUseAttr(attributes_);
    if (svgSymbol != nullptr) {
        svgSymbol->drawSymbol(canvas, width, height);
    } else {
        DLOG(INFO) << "[SvgUse::OnDraw] : normal component";
        refSvgNode->Draw(canvas);
    }

    return;
}

drawing::Path SvgUse::AsPath() {
    drawing::Path path;
    auto svgContext = GetContext();
    if (!svgContext) {
        return path;
    }
    auto refSvgNode = svgContext->GetSvgNodeById(href);
    if (!refSvgNode) {
        return path;
    }
    path = refSvgNode->AsPath();
    return path;
}

SvgUse::AttributeScope::AttributeScope(const std::shared_ptr<SvgNode> &node) : node_(node) {
    auto nodeAttr = node->GetBaseAttributes();
    attributes_ = nodeAttr;
}

SvgUse::AttributeScope::~AttributeScope() {
    // TODO : check null ptr
    node_->SetBaseAttributes(attributes_);
}

} // namespace svg
} // namespace rnoh