#pragma once
#include <future>
#include "SvgSvg.h"
#include <native_drawing/drawing_bitmap.h>

namespace rnoh {
namespace svg {

class SvgViewManager {
public:
    static SvgViewManager &getInstance() {
        // 单例模式
        static SvgViewManager instance;
        return instance;
    }
    void setSvgView(int tag, std::weak_ptr<SvgSvg> svg);

    std::weak_ptr<SvgSvg> getSvgViewByTag(int tag);

    void onDropView(int tag);

private:
    SvgViewManager() {}
    SvgViewManager(const SvgViewManager &) = delete;
    SvgViewManager &operator=(const SvgViewManager &) = delete;
    ~SvgViewManager();
    std::map<int, std::weak_ptr<SvgSvg>> mTagToSvgViewMap;
};
} // namespace svg
} // namespace rnoh
