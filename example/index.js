/**
 * @format
 */

import {AppRegistry} from 'react-native';
import App from './App';
import SVGDemo from './SVGDemo/SVGViewDemo';
import {name as appName} from './app.json';
import SvgDemoCases from './svgDemoCases/App'
import TestExamples from './apps/test-examples/App'
import Examples from './apps/examples/App'

// AppRegistry.registerComponent(appName, () => App);
AppRegistry.registerComponent(appName, () => SVGDemo);
AppRegistry.registerComponent(appName, () => SvgDemoCases);
AppRegistry.registerComponent(appName, () => TestExamples);
AppRegistry.registerComponent(appName, () => Examples);