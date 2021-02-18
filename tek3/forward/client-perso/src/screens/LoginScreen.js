import React, {Component} from 'react';
import {connect} from 'react-redux';
import PropTypes from 'prop-types';
import Actions from '../actions';
import LoginForm from "../components/LoginForm";
import styles from "../../assets/StyleSheet"
import {View, Text} from "react-native";

export class LoginScreen extends Component {
  constructor(props) {
    super(props);
  }

  componentWillUnmount() {
  }

  componentWillMount() {
  }

  render() {
    const loading = !!(this.props.loginStatus && !this.props.loginStatus.hasOwnProperty("status"));
    const error = (this.props.loginStatus && this.props.loginStatus.hasOwnProperty("error") ? this.props.loginStatus.error : null);
    return (
        <View style={styles.container}>
          {error ? <Text style={styles.error}> {error} </Text> : null}
          <LoginForm submit={this.props.login} loading={loading}/>
          <Text onPress={this.props.switch}> Je n'ai pas encore de compte </Text>
        </View>
    );
  }
}

LoginScreen.propTypes = {
  switch: PropTypes.func.isRequired,
  login: PropTypes.func.isRequired,
  loginStatus: PropTypes.shape({
    status: PropTypes.bool,
    error: PropTypes.string
  })
};

const mapStateToProps = (state) => ({
  loginStatus: state.auth.loginStatus
});

const mapDispatchToProps = (dispatch) => ({
  login: (username, password) => {
    dispatch(Actions.Auth.login(username, password))
  }
});

export default connect(mapStateToProps, mapDispatchToProps)(LoginScreen);
