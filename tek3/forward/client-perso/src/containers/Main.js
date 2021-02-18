import React, {Component} from 'react';
import {connect} from 'react-redux';
import PropTypes from 'prop-types';

import AppNavigator from '../navigation/AppNavigator';
import LoginScreen from "../screens/LoginScreen";
import RegisterScreen from "../screens/RegisterScreen";

export class Main extends Component {
  constructor(props) {
    super(props);
    this.state = {
      login: true
    };
    this.switchConnection = this.switchConnection.bind(this);
  }

  switchConnection() {
    this.setState({login: !this.state.login});
  }

  render() {
    if (this.props.token && this.props.token !== "") {
      return (<AppNavigator/>);
    } else if (this.state.login) {
      return (<LoginScreen switch={this.switchConnection}/>);
    } else {
      return (<RegisterScreen switch={this.switchConnection}/>);
    }
  }
}

Main.propTypes = {
  token: PropTypes.string,
};

const mapStateToProps = (state) => ({
  token: state.auth.token
});

const mapDispatchToProps = (dispatch) => ({
});

export default connect(mapStateToProps, mapDispatchToProps)(Main);