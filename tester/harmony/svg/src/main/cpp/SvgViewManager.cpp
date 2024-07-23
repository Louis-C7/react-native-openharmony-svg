//
// Created on 2024/7/11.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "SvgViewManager.h"

namespace rnoh{
namespace svg{
void SvgViewManager::setSvgView(int tag, std::shared_ptr<SvgSvg> svg){
    mTagToSvgViewMap.insert(std::make_pair(tag,svg));
}

std::shared_ptr<SvgSvg> SvgViewManager::getSvgViewByTag(int tag){
    std::shared_ptr<SvgSvg> svgSvg = nullptr;
    auto it = mTagToSvgViewMap.find(tag);
    if (it != mTagToSvgViewMap.end()){
        svgSvg = it->second;
    }
    return svgSvg;
}

void SvgViewManager::onDropView(int tag){
    // 将svgview从容器中删除
    mTagToSvgViewMap.erase(tag);
}

}
}