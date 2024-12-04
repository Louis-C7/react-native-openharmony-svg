#pragma once

#include "RNOH/CppComponentInstance.h"
#include <folly/dynamic.h>
#include "SvgArkUINode.h"
#include <react/renderer/components/react_native_svg/ShadowNodes.h>
#include "SvgViewManager.h"
#include "SvgSvg.h"

namespace rnoh {
namespace svg {

class RNSVGSvgViewComponentInstance : public CppComponentInstance<facebook::react::RNSVGSvgViewShadowNode>,
                                      public SvgHost {
public:
    RNSVGSvgViewComponentInstance(Context context);
    ~RNSVGSvgViewComponentInstance();

    void onFinalizeUpdates() override;

    // get SvgNode from childComponentInstance and set it to root_
    void onChildInserted(ComponentInstance::Shared const &childComponentInstance, std::size_t index) override;

    void onChildRemoved(ComponentInstance::Shared const &childComponentInstance) override;

    SvgArkUINode &getLocalRootArkUINode() override;

    // since we can't get color correctly from props
    std::optional<std::string> getColorFromDynamic(folly::dynamic value);

    bool canHandleTouch() const override;

    bool canChildrenHandleTouch() const override;

private:
    SvgArkUINode m_svgArkUINode;
    std::shared_ptr<SvgSvg> m_svgSvg = std::make_shared<SvgSvg>();
};

} // namespace svg
} // namespace rnoh