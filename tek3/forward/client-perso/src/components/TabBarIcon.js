import React from 'react';
import { Ionicons } from '@expo/vector-icons';

export default class TabBarIcon extends React.Component {
  render() {
    return (
      <Ionicons
        name={this.props.name}
        size={26}
        style={{ marginBottom: -3 }}
        color={this.props.focused ? "rgb(0, 122, 255)" : "black"}
      />
    );
  }
}