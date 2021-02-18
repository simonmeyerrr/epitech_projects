import React from 'react';
import { Platform } from 'react-native';
import { createStackNavigator } from 'react-navigation-stack';
import { createBottomTabNavigator } from 'react-navigation-tabs';

import TabBarIcon from '../components/TabBarIcon';
import HomeScreen from '../screens/HomeScreen';
import LinksScreen from '../screens/LinksScreen';
import SettingsScreen from '../screens/SettingsScreen';
import EscapeGameScreen from "../screens/EscapeGameScreen";
import SearchScreen from "../screens/SearchScreen";
import ProfilScreen from "../screens/ProfilScreen";
import EscapeRoomScreen from "../screens/EscapeRoomScreen";

const HomeStack = createStackNavigator({
  Home: HomeScreen,
  Search: SearchScreen,
  EscapeGame: EscapeGameScreen,
  EscapeRoom: EscapeRoomScreen
});

HomeStack.navigationOptions = {
  tabBarLabel: 'Découvrir',
  tabBarIcon: ({ focused }) => (
    <TabBarIcon
      focused={focused}
      name={
        Platform.OS === 'ios'
          ? `ios-compass`
          : 'md-compass'
      }
    />
  ),
};

const ProfilStack = createStackNavigator({
  Profil: ProfilScreen,
  Settings: SettingsScreen,
});

ProfilStack.navigationOptions = {
  tabBarLabel: 'Profil',
  tabBarIcon: ({ focused }) => (
    <TabBarIcon
      focused={focused}
      name={Platform.OS === 'ios' ? 'ios-person' : 'md-person'}
    />
  ),
};

export default createBottomTabNavigator({
  HomeStack,
  ProfilStack
});
