/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include "RNSVGRenderableModule.h"

using namespace facebook;
using namespace react;

namespace rnoh {
namespace svg {

bool RNSVGRenderableModule::isPointInFill(facebook::jsi::Runtime &rt, int32_t tag, std::optional<jsi::Object> options) {
    return false;
}
bool RNSVGRenderableModule::isPointInStroke(facebook::jsi::Runtime &rt, int32_t tag,
                                            std::optional<jsi::Object> options) {
    return false;
}
double RNSVGRenderableModule::getTotalLength(jsi::Runtime &rt, int32_t tag) { return 0; }
jsi::Object RNSVGRenderableModule::getPointAtLength(jsi::Runtime &rt, int32_t tag, std::optional<jsi::Object> options) {
    return jsi::Object(rt);
};
jsi::Object RNSVGRenderableModule::getBBox(jsi::Runtime &rt, int32_t tag, std::optional<jsi::Object> options) {
    return jsi::Object(rt);
};
jsi::Object RNSVGRenderableModule::getCTM(jsi::Runtime &rt, int32_t tag) { return jsi::Object(rt); };
jsi::Object RNSVGRenderableModule::getScreenCTM(jsi::Runtime &rt, int32_t tag) { return jsi::Object(rt); };
jsi::Value RNSVGRenderableModule::getRawResource(jsi::Runtime &rt, jsi::String name) { return jsi::Object(rt); };

static jsi::Value __hostFunction_RNSVGRenderableModule_isPointInFill(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                     const jsi::Value *args, size_t count) {
    return static_cast<RNSVGRenderableModule *>(&turboModule)
        ->isPointInFill(
            rt, args[0].isNull() || args[0].isUndefined() ? 0 : std::make_optional(args[0].asNumber()).value(),
            count <= 1 || args[1].isNull() || args[1].isUndefined() ? std::nullopt
                                                                    : std::make_optional(args[1].asObject(rt)));
}

static jsi::Value __hostFunction_RNSVGRenderableModule_isPointInStroke(jsi::Runtime &rt,
                                                                       react::TurboModule &turboModule,
                                                                       const jsi::Value *args, size_t count) {
    return static_cast<RNSVGRenderableModule *>(&turboModule)
        ->isPointInStroke(
            rt, args[0].isNull() || args[0].isUndefined() ? 0 : std::make_optional(args[0].asNumber()).value(),
            count <= 1 || args[1].isNull() || args[1].isUndefined() ? std::nullopt
                                                                    : std::make_optional(args[1].asObject(rt)));
}
static jsi::Value __hostFunction_RNSVGRenderableModule_getTotalLength(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                      const jsi::Value *args, size_t count) {
    return static_cast<RNSVGRenderableModule *>(&turboModule)
        ->getTotalLength(
            rt, args[0].isNull() || args[0].isUndefined() ? 0 : std::make_optional(args[0].asNumber()).value());
}
static jsi::Value __hostFunction_RNSVGRenderableModule_getPointAtLength(jsi::Runtime &rt,
                                                                        react::TurboModule &turboModule,
                                                                        const jsi::Value *args, size_t count) {
    return static_cast<RNSVGRenderableModule *>(&turboModule)
        ->getPointAtLength(
            rt, args[0].isNull() || args[0].isUndefined() ? 0 : std::make_optional(args[0].asNumber()).value(),
            count <= 1 || args[1].isNull() || args[1].isUndefined() ? std::nullopt
                                                                    : std::make_optional(args[1].asObject(rt)));
}
static jsi::Value __hostFunction_RNSVGRenderableModule_getBBox(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                               const jsi::Value *args, size_t count) {
    return static_cast<RNSVGRenderableModule *>(&turboModule)
        ->getBBox(rt, args[0].isNull() || args[0].isUndefined() ? 0 : std::make_optional(args[0].asNumber()).value(),
                  count <= 1 || args[1].isNull() || args[1].isUndefined() ? std::nullopt
                                                                          : std::make_optional(args[1].asObject(rt)));
}
static jsi::Value __hostFunction_RNSVGRenderableModule_getCTM(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                              const jsi::Value *args, size_t count) {
    return static_cast<RNSVGRenderableModule *>(&turboModule)
        ->getCTM(rt, args[0].isNull() || args[0].isUndefined() ? 0 : std::make_optional(args[0].asNumber()).value());
}
static jsi::Value __hostFunction_RNSVGRenderableModule_getScreenCTM(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                    const jsi::Value *args, size_t count) {
    return static_cast<RNSVGRenderableModule *>(&turboModule)
        ->getScreenCTM(rt,
                       args[0].isNull() || args[0].isUndefined() ? 0 : std::make_optional(args[0].asNumber()).value());
}
static jsi::Value __hostFunction_RNSVGRenderableModule_getRawResource(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                                      const jsi::Value *args, size_t count) {
    return static_cast<RNSVGRenderableModule *>(&turboModule)->getRawResource(rt, args[0].asString(rt));
}

RNSVGRenderableModule::RNSVGRenderableModule(const ArkTSTurboModule::Context ctx, const std::string name)
    : ArkTSTurboModule(ctx, name) {
    methodMap_["isPointInFill"] = MethodMetadata{2, __hostFunction_RNSVGRenderableModule_isPointInFill};
    methodMap_["isPointInStroke"] = MethodMetadata{2, __hostFunction_RNSVGRenderableModule_isPointInStroke};
    methodMap_["getTotalLength"] = MethodMetadata{1, __hostFunction_RNSVGRenderableModule_getTotalLength};
    methodMap_["getPointAtLength"] = MethodMetadata{2, __hostFunction_RNSVGRenderableModule_getPointAtLength};
    methodMap_["getBBox"] = MethodMetadata{2, __hostFunction_RNSVGRenderableModule_getBBox};
    methodMap_["getCTM"] = MethodMetadata{1, __hostFunction_RNSVGRenderableModule_getCTM};
    methodMap_["getScreenCTM"] = MethodMetadata{1, __hostFunction_RNSVGRenderableModule_getScreenCTM};
    methodMap_["getRawResource"] = MethodMetadata{1, __hostFunction_RNSVGRenderableModule_getRawResource};
}
} // namespace svg
} // namespace rnoh