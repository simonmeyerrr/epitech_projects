import React from 'react';
import { StyleSheet, StatusBar, View } from 'react-native';
import AppNavigator from './navigation/AppNavigator';

export default function App() {
  return (
      <View style={styles.container}>
        {Platform.OS === 'ios' && <StatusBar barStyle="dark-content"/>}
        <AppNavigator/>
      </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
});
