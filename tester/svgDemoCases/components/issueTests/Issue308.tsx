import React, {Component} from 'react';
import {View, StyleSheet} from 'react-native';
import {SvgXml} from 'react-native-svg';

const textIcon = `<?xml version="1.0" encoding="UTF-8"?>
<svg width="21px" height="21px" viewBox="0 0 21 21" version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
    <title>cfa-acct-overview-open-step-e-1</title>
    <g id="1" stroke="none" stroke-width="1" fill="none" fill-rule="evenodd">
        <g id="2" transform="translate(-457.000000, -1989.000000)" fill="#1E53A4" fill-rule="nonzero">
            <g id="3" transform="translate(457.510121, 1989.846731)">
                <rect id="4" opacity="0.15" x="0" y="0" width="20" height="20" rx="10"></rect>
                <g id="5" transform="translate(7.552000, 1.166667)" font-family="PingFangSC-Regular, PingFang SC" font-size="12" font-weight="normal">
                    <text>
                        <tspan x="0" y="13">1</tspan>
                    </text>
                </g>
            </g>
        </g>
    </g>
</svg>`;

export default class Issue308 extends Component {
  render() {
    return (
      <View style={styles.container}>
        <SvgXml xml={textIcon} width={100} height={100} />
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: 'white',
    justifyContent: 'center',
    alignItems: 'center',
  },
});
