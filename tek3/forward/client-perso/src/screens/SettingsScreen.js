import React from 'react';
import {Button, Platform, ScrollView, StyleSheet, Text} from 'react-native';
import {Ionicons} from "@expo/vector-icons";
import Actions from "../actions";
import {connect} from "react-redux";

export class SettingsScreen extends React.Component {
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
          <Button title={"Se déconnecter"} onPress={this.props.logout}/>
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

const mapStateToProps = (state) => ({
});

const mapDispatchToProps = (dispatch) => ({
  logout: () => {
    dispatch(Actions.Auth.logout())
  }
});

export default connect(mapStateToProps, mapDispatchToProps)(SettingsScreen);