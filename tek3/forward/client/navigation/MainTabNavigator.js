import React from 'react';
import { Platform } from 'react-native';
import { createStackNavigator } from 'react-navigation-stack';
import { createBottomTabNavigator } from 'react-navigation-tabs';

import TabBarIcon from "../components/TabBarIcon";

import DiscoverScreen from "../screens/DiscoverScreen";
import SearchScreen from "../screens/SearchScreen";
import EscapeGameScreen from "../screens/EscapeGameScreen";
import EscapeRoomScreen from "../screens/EscapeRoomScreen";
import SettingsScreen from "../screens/SettingsScreen";
import ProfileScreen from "../screens/ProfileScreen";

const DiscoverStack = createStackNavigator({
  Discover: DiscoverScreen,
  Search: SearchScreen,
  EscapeGame: EscapeGameScreen,
  EscapeRoom: EscapeRoomScreen
});

DiscoverStack.navigationOptions = {
  tabBarLabel: 'Découvrir',
  tabBarIcon: ({ focused }) => (
    <TabBarIcon
      focused={focused}
      name={Platform.OS === 'ios' ? `ios-compass` : 'md-compass'}
    />
  ),
};

const ProfileStack = createStackNavigator({
  Profile: ProfileScreen,
  Settings: SettingsScreen,
});

ProfileStack.navigationOptions = {
  tabBarLabel: 'Profil',
  tabBarIcon: ({ focused }) => (
    <TabBarIcon
      focused={focused}
      name={Platform.OS === 'ios' ? 'ios-person' : 'md-person'}
    />
  ),
};

export default createBottomTabNavigator({
  DiscoverStack,
  ProfileStack
});
