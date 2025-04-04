import type { RNPackageContext, RNPackage } from '@rnoh/react-native-openharmony/ts';
import { SvgPackage } from '@louisc7/react-native-oh-svg/ts';
import { ReanimatedPackage } from '@react-native-oh-tpl/react-native-reanimated/ts';

export function createRNPackages(ctx: RNPackageContext): RNPackage[] {
  return [
    new SvgPackage(ctx),
    new ReanimatedPackage(ctx),
  ];
}