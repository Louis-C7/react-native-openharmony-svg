// 
// Created on 2024/7/11.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef HARMONY_SVGVIEWMANAGER_H
#define HARMONY_SVGVIEWMANAGER_H

#include <future>
#include "SvgSvg.h"
#include <native_drawing/drawing_bitmap.h>

namespace rnoh{
namespace svg{

class SvgViewManager {
public:
    static SvgViewManager &getInstance(){
        // 单例模式
        static SvgViewManager instance;
        return instance;
    }
    
    void setSvgView(int tag, std::shared_ptr<SvgSvg> svg);
    
    std::shared_ptr<SvgSvg> getSvgViewByTag(int tag);
    
    void onDropView(int tag);
private:
    SvgViewManager() {}
    SvgViewManager(const SvgViewManager &) = delete;
    SvgViewManager &operator=(const SvgViewManager &) = delete;
    
    std::map<int, std::shared_ptr<SvgSvg>> mTagToSvgViewMap;
};
}
}

#endif //HARMONY_SVGVIEWMANAGER_H
