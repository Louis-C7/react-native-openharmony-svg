import type {RNPackageContext, RNPackage} from '@rnoh/react-native-openharmony/ts';
import {SvgPackage} from '@louisc7/react-native-oh-svg/ts';

export function createRNPackages(ctx: RNPackageContext): RNPackage[] {
  return [new SvgPackage(ctx)];
}