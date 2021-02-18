import React from 'react';
import {Button, Platform, ScrollView, StyleSheet, Text, Alert} from 'react-native';
import {Ionicons} from "@expo/vector-icons";

export default class SettingsScreen extends React.Component {
  static navigationOptions = ({ navigation }) => {
    return {
      headerTitle: () => <Text style={{fontSize: 20}}> Réglages </Text>,
      headerLeft: () => (
          <Ionicons
              name={Platform.OS === 'ios' ? 'ios-arrow-round-back' : 'md-arrow-round-back'}
              size={26}
              style={{marginLeft: 20}}
              onPress={() => {navigation.goBack()}}
          />
      ),
    };
  };

  render() {
    return (
        <ScrollView style={styles.container}>
          <Button title={"Se déconnecter"} onPress={() => {
            Alert.alert(
                "T'as pas de compte donc tu ne peux pas te déconnecter."
            )
          }}/>
        </ScrollView>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: 15,
  },
});
