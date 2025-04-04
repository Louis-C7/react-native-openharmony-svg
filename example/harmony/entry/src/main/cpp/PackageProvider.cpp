#include "RNOH/PackageProvider.h"
#include "ReanimatedPackage.h"
#include "SVGPackage.h"

using namespace rnoh;

std::vector<std::shared_ptr<Package>> PackageProvider::getPackages(Package::Context ctx) {
    return {std::make_shared<SVGPackage>(ctx), std::make_shared<ReanimatedPackage>(ctx)};
}