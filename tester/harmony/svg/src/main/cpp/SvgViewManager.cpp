#include "SvgViewManager.h"

namespace rnoh {
namespace svg {
void SvgViewManager::setSvgView(int tag, std::weak_ptr<SvgSvg> svg) {
    mTagToSvgViewMap.insert(std::make_pair(tag, svg));
}

std::weak_ptr<SvgSvg> SvgViewManager::getSvgViewByTag(int tag) {
    std::weak_ptr<SvgSvg> svgSvg;
    auto it = mTagToSvgViewMap.find(tag);
    if (it != mTagToSvgViewMap.end()) {
        svgSvg = it->second;
    }
    return svgSvg;
}

void SvgViewManager::onDropView(int tag) {
    // 将svgview从容器中删除
    mTagToSvgViewMap.erase(tag);
}

SvgViewManager::~SvgViewManager() {
    if (mTagToSvgViewMap.empty() == false) {
        mTagToSvgViewMap.clear();
    }
}

} // namespace svg
} // namespace rnoh