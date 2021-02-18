import React, {Component} from 'react';
import {connect} from 'react-redux';
import PropTypes from 'prop-types';
import Actions from '../actions';
import RegisterForm from "../components/RegisterForm";
import styles from "../../assets/StyleSheet"
import {View, Text} from "react-native";

export class RegisterScreen extends Component {
  constructor(props) {
    super(props);
  }

  componentWillUnmount() {
  }

  componentWillMount() {
  }

  render() {
    const loading = !!(this.props.registerStatus && !this.props.registerStatus.hasOwnProperty("status"));
    const error = (this.props.registerStatus && this.props.registerStatus.hasOwnProperty("error") ? this.props.registerStatus.error : null);
    return (
        <View style={styles.container}>
          {error ? <Text style={styles.error}> {error} </Text> : null}
          <RegisterForm submit={this.props.register} loading={loading}/>
          <Text onPress={this.props.switch}> J'ai déjà un compte </Text>
        </View>
    );
  }

}

RegisterScreen.propTypes = {
  switch: PropTypes.func.isRequired,
  register: PropTypes.func.isRequired,
  registerStatus: PropTypes.shape({
    status: PropTypes.bool,
    error: PropTypes.string
  })
};

const mapStateToProps = (state) => ({
  registerStatus: state.auth.registerStatus
});

const mapDispatchToProps = (dispatch) => ({
  register: (username, password) => {
    dispatch(Actions.Auth.register(username, password))
  }
});

export default connect(mapStateToProps, mapDispatchToProps)(RegisterScreen);
