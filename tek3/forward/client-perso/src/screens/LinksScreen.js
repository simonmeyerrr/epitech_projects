import React from 'react';
import { ScrollView, StyleSheet, Button } from 'react-native';
import Actions from "../actions";
import {connect} from "react-redux";

class LinksScreen extends React.Component {
  static navigationOptions = {
    title: null,
  };

  render() {
    return (
      <ScrollView style={styles.container}>
        <Button title={"deco"} onPress={this.props.logout}/>
      </ScrollView>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: 15,
    backgroundColor: '#fff',
  },
});

const mapStateToProps = (state) => ({
});

const mapDispatchToProps = (dispatch) => ({
  logout: () => {
    dispatch(Actions.Auth.logout())
  }
});

export default connect(mapStateToProps, mapDispatchToProps)(LinksScreen);