
#include "RNSVGSvgViewModule.h"

using namespace facebook;
using namespace react;

namespace rnoh {
namespace svg {

using Object = std::optional<jsi::Object>;

void RNSVGSvgViewModule::toDataURL(jsi::Runtime &rt, Int32_t tag, Object object, Callback &&callback) {
    DLOG(INFO) << "[SVGTurboModule] toDataUrl IN!";
    // 获取图片的bitmap并将其转化为base64
    std::string base64 = "";
    auto SvgSvgNode = SvgViewManager::getInstance().getSvgViewByTag(*tag);
    if (SvgSvgNode != nullptr) {
        OH_Drawing_Bitmap *bitmap = OH_Drawing_BitmapCreate();
        OH_Drawing_BitmapFormat format = {COLOR_FORMAT_BGRA_8888, ALPHA_FORMAT_OPAQUE};
        auto size = SvgSvgNode->GetSize();
        OH_Drawing_BitmapBuild(bitmap, size.Width(), size.Height(), &format);
        OH_Drawing_Canvas *canvas = OH_Drawing_CanvasCreate();
        OH_Drawing_CanvasBind(canvas, bitmap);
        // 设置SvgNode节点相关信息
        if (SvgSvgNode->GetContext()) {
            SvgSvgNode->GetContext()->ClearIdMap();
        }
        SvgSvgNode->ContextTraversal();
        SvgSvgNode->InitStyle({});
        SvgSvgNode->Draw(canvas);
        base64 = StringUtils::bitmapToBase64(bitmap);
        // 销毁bitmap和canvas
        OH_Drawing_CanvasDestroy(canvas);
        // 销毁bitmap对象
        OH_Drawing_BitmapDestroy(bitmap);
    }
    jsInvoker_->invokeAsync([base64, endCallback = std::move(*callback)] { endCallback(base64); });
    return;
}

static jsi::Value __hostFunction_RNSVGSvgViewModule_toDataURL(jsi::Runtime &rt, react::TurboModule &turboModule,
                                                              const jsi::Value *args, size_t count) {
    auto newNum = args[0].isNull() || args[0].isUndefined() ? std::nullopt : std::make_optional(args[0].asNumber());
    auto newObject = args[1].isNull() || args[1].isUndefined() ? std::nullopt : std::make_optional(args[1].asObject(rt));
    auto self = static_cast<RNSVGSvgViewModule *>(&turboModule);
    if (args[2].isObject()) {
        auto callback = std::make_shared<jsi::Function>(std::move(args[2].getObject(rt).getFunction(rt)));
        auto endCallback = [&rt, callback = std::move(callback)](std::string base64) {
            //             auto result = jsi::Object(rt);
            auto base64Value = jsi::String::createFromUtf8(rt, base64);
            //             result.setProperty(rt, "base64", base64Value);
            callback->call(rt, {std::move(base64Value)});
        };
        static_cast<RNSVGSvgViewModule *>(&turboModule)
            ->toDataURL(rt, newNum, std::move(newObject), std::move(endCallback));
        return jsi::Value::undefined();
    }
    static_cast<RNSVGSvgViewModule *>(&turboModule)
        ->toDataURL(rt, newNum, std::move(newObject), [self, &rt](std::string base64) {});
    return jsi::Value::undefined();
}

RNSVGSvgViewModule::RNSVGSvgViewModule(const ArkTSTurboModule::Context ctx, const std::string name)
    : ArkTSTurboModule(ctx, name) {
    { methodMap_["toDataURL"] = MethodMetadata{1, __hostFunction_RNSVGSvgViewModule_toDataURL}; };
}

} // namespace svg
} // namespace rnoh
