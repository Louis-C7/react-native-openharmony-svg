#include "RNSVGTextPathComponentInstance.h"
#include "SvgTSpan.h"

namespace rnoh {
namespace svg {

RNSVGTextPathComponentInstance::RNSVGTextPathComponentInstance(Context context)
    : RNSVGBaseComponentInstance(std::move(context)) {
    SetSvgNode(m_svgTP);
}

void RNSVGTextPathComponentInstance::UpdateElementProps() {
    m_svgTP->UpdateCommonProps(m_props);
    m_svgTP->UpdateFontProps(m_props);
    m_svgTP->UpdateTextProps(m_props);
    m_svgTP->href_ = m_props->href;
    m_svgTP->startOffset_ = StringUtils::FromString(m_props->startOffset).ConvertToPx(m_layoutMetrics.pointScaleFactor);
    m_svgTP->spacing_ = textPathSpacingFromStr(m_props->spacing);
    m_svgTP->midLine_ = textPathMidLineFromStr(m_props->midLine);
    m_svgTP->side_ = textPathSideFromStr(m_props->side);
    m_svgTP->method_ = textPathMethodFromStr(m_props->method);
}
} // namespace svg
} // namespace rnoh
