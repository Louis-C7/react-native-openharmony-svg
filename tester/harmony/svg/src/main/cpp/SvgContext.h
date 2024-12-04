/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include "properties/Rect.h"
#include "properties/Size.h"
#include "properties/Color.h"

namespace rnoh {
namespace svg {

using AttrMap = std::unordered_map<std::string, std::string>;
using ClassStyleMap = std::unordered_map<std::string, AttrMap>;
class SvgNode;
class SvgContext {
public:
    void Push(const std::string &value, const std::shared_ptr<SvgNode> &svgNode) { idMapper_.emplace(value, svgNode); }

    std::shared_ptr<SvgNode> GetSvgNodeById(const std::string &id) const;

    void PushStyle(const std::string &styleName, const std::pair<std::string, std::string> &attrPair);

    const AttrMap &GetAttrMap(const std::string &key) const;

    void SetRootViewBox(const Rect &viewBox) { rootViewBox_ = viewBox; }

    const Rect &GetRootViewBox() const;

    void SetSvgSize(const Size &size) { svgSize_ = size; }

    const Size &GetSvgSize() const { return svgSize_; }

    void SetSvgColor(const Color &svgColor) { svgColor_ = svgColor; }

    const Color &GetSvgColor() { return svgColor_; }

    void SetCanvasBounds(const Rect &canvasClipBounds) { canvasClipBounds_ = canvasClipBounds; }

    const Rect getCanvasBounds() { return canvasClipBounds_; }

    void SetCanvasScale(const double &canvasScaleX, const double &canvasScaleY) {
        canvasScaleX_ = canvasScaleX;
        canvasScaleY_ = canvasScaleY;
    }

    const double getCanvasScaleX() { return canvasScaleX_; }

    const double getCanvasScaleY() { return canvasScaleY_; }

    void ClearIdMap() { idMapper_.clear(); }

private:
    std::unordered_map<std::string, std::weak_ptr<SvgNode>> idMapper_;
    ClassStyleMap styleMap_;
    Rect rootViewBox_;
    Size svgSize_;
    Color svgColor_;
    Rect canvasClipBounds_;
    double canvasScaleX_ = 1;
    double canvasScaleY_ = 1;
};

} // namespace svg
} // namespace rnoh