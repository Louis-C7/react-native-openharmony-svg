
#pragma once

#include <ReactCommon/TurboModule.h>
#include <react/bridging/Bridging.h>
#include "RNOH/ArkTSTurboModule.h"
#include "SvgViewManager.h"
#include "utils/StringUtils.h"
#include "native_drawing/drawing_canvas.h"
#include <optional>

using namespace facebook;

namespace rnoh {
namespace svg {

class JSI_EXPORT RNSVGSvgViewModule : public ArkTSTurboModule {
    using Object = std::optional<jsi::Object>;
    using Int32_t = std::optional<int32_t>;
    using Callback = std::optional<std::function<void(std::string)>>;

public:
    RNSVGSvgViewModule(const ArkTSTurboModule::Context ctx, const std::string name);

    void toDataURL(jsi::Runtime &rt, Int32_t tag, Object object, Callback &&callback);
};

} // namespace svg
} // namespace rnoh
