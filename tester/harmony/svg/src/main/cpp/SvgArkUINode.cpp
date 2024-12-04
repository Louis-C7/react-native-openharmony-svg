/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include "arkui/native_interface.h"
#include "arkui/native_node.h"
#include "arkui/native_type.h"
#include "RNOH/arkui/NativeNodeApi.h"
#include "SvgArkUINode.h"
#include <native_drawing/drawing_canvas.h>
#include <native_drawing/drawing_path.h>
#include <native_drawing/drawing_pen.h>
#include <native_drawing/drawing_types.h>
#include <sstream>
#include <functional>
#include "SvgViewManager.h"

namespace rnoh {
namespace svg {

// 对应SVGArkUINode
SvgArkUINode::SvgArkUINode() : ArkUINode(NativeNodeApi::getInstance()->createNode(ArkUI_NodeType::ARKUI_NODE_CUSTOM)) {
    userCallback_ = new UserCallback();
    // 设置自定义回调。注册onDraw
    userCallback_->callback = [this](ArkUI_NodeCustomEvent *event) {
        auto type = OH_ArkUI_NodeCustomEvent_GetEventType(event);
        switch (type) {
        case ARKUI_NODE_CUSTOM_EVENT_ON_DRAW:
            OnDraw(event);
            break;
        default:
            break;
        }
    };
    eventReceiver = [](ArkUI_NodeCustomEvent *event) {
        if (OH_ArkUI_NodeCustomEvent_GetEventTargetId(event) == 77) {
            auto *userData = reinterpret_cast<UserCallback *>(OH_ArkUI_NodeCustomEvent_GetUserData(event));
            if (userData != nullptr && userData->callback != nullptr) {
                userData->callback(event);
            }
        }
    };
    maybeThrow(NativeNodeApi::getInstance()->addNodeCustomEventReceiver(m_nodeHandle, eventReceiver));
    maybeThrow(NativeNodeApi::getInstance()->registerNodeCustomEvent(m_nodeHandle, ARKUI_NODE_CUSTOM_EVENT_ON_DRAW, 77,
                                                                     userCallback_));
}

SvgArkUINode::~SvgArkUINode() {
    NativeNodeApi::getInstance()->removeNodeCustomEventReceiver(m_nodeHandle, eventReceiver);
    NativeNodeApi::getInstance()->unregisterNodeCustomEvent(m_nodeHandle, ARKUI_NODE_CUSTOM_EVENT_ON_DRAW);
    delete userCallback_;
    userCallback_ = nullptr;
}

void SvgArkUINode::OnDraw(ArkUI_NodeCustomEvent *event) {
    auto *drawContext = OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw(event);
    auto *drawingHandle = reinterpret_cast<OH_Drawing_Canvas *>(OH_ArkUI_DrawContext_GetCanvas(drawContext));
    DLOG(INFO) << "[svg] <SVGArkUINode> CanvasGetHeight: " << OH_Drawing_CanvasGetHeight(drawingHandle);
    DLOG(INFO) << "[svg] <SVGArkUINode> CanvasGetWidth: " << OH_Drawing_CanvasGetWidth(drawingHandle);
    auto root = root_.lock();
    CHECK_NULL_VOID(root);
    if (root->GetContext()) {
        // reset the idMap
        root->GetContext()->ClearIdMap();
    }
    root->ContextTraversal();
    root->InitStyle({});
    root->Draw(drawingHandle);
}

} // namespace svg
} // namespace rnoh
