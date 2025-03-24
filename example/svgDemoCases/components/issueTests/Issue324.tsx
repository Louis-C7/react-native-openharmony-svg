import React from 'react';
import {View} from 'react-native';
import Svg, {Rect, G, ClipPath, Defs} from 'react-native-svg';

const Issue324 = () => {
  return (
    <View>
      <Svg width="300" height="150" viewBox="0 0 100 150">
        <Defs>
          <ClipPath id="clip-rect">
            <Rect x="10" y="10" width="100" height="100" />
          </ClipPath>
        </Defs>

        {/* 应用ClipPath到Group元素，同时加上位移 */}
        <G x="10" y="10" clipPath="url(#clip-rect)">
          <Rect x="0" y="0" width="100" height="100" fill="red"/>
          <Rect x="100" y="0" width="100" height="100" fill="green" />
          <Rect x="0" y="100" width="100" height="100" fill="blue" />
          <Rect x="100" y="100" width="100" height="100" fill="yellow" />
        </G>
      </Svg>
    </View>
  );
};

export default Issue324;
