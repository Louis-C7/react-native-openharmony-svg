import type {RNPackageContext, RNPackage} from '@rnoh/react-native-openharmony/ts';
import {SvgPackage} from '@react-native-oh-tpl/react-native-svg/ts';

export function createRNPackages(ctx: RNPackageContext): RNPackage[] {
  return [new SvgPackage(ctx)];
}