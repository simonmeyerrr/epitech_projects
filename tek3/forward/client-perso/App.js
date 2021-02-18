import React from 'react';
import {Platform, StatusBar, StyleSheet, View} from 'react-native';
import { AppLoading } from 'expo';
import { Asset } from 'expo-asset';
import * as Font from 'expo-font';
import { Ionicons } from '@expo/vector-icons';
import Main from './src/containers/Main';
import Constants from './src/constants';
import {Provider} from 'react-redux';
import createStore from './src/store';

const store = createStore();

store.dispatch({type: Constants.GET_USER_TOKEN});

export default class App extends React.Component {
  render() {
    return (
        <Provider store={store}>
          <View style={styles.container}>
            {Platform.OS === 'ios' && <StatusBar barStyle="dark-content"/>}
            <ExpoLoader/>
          </View>
        </Provider>
    );
  }
}

class ExpoLoader extends React.Component {
  state = {
    isLoadingComplete: false,
  };

  render() {
    return this.state.isLoadingComplete ?
        <Main/> :
        <AppLoading
            startAsync={this._loadResourcesAsync}
            onError={this._handleLoadingError}
            onFinish={this._handleFinishLoading}
        />
  }

  _loadResourcesAsync = async () => {
    return Promise.all([
      Asset.loadAsync([
        require('./assets/images/little-red-door.png'),
        require('./assets/images/le-dernier-casse.jpg')
      ]),
      Font.loadAsync({
        ...Ionicons.font,
      }),
    ]);
  };

  _handleLoadingError = error => {
    console.warn(error);
  };

  _handleFinishLoading = () => {
    this.setState({isLoadingComplete: true});
  };
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
  },
});
