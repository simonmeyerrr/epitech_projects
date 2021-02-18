import React, {Component} from 'react';
import PropTypes from "prop-types";
import {
    AppRegistry,
    ScrollView,
    View,
    SafeAreaView,
    Platform, StyleSheet,
} from 'react-native';
import {
    TextField,
    FilledTextField,
    OutlinedTextField,
} from 'react-native-material-textfield';
import {RaisedTextButton} from 'react-native-material-buttons';
import MaterialIcon from 'react-native-vector-icons/MaterialIcons';

const styles = StyleSheet.create({
    form: {
        backgroundColor: '#cccccc',
        padding: 50,
        margin: 20,
        width: '90%',
        borderRadius: 30
    },
    formContainer: {
        margin: 20
    },

});

export default class LoginForm extends Component {
    constructor(props) {
        super(props);

        this.onFocus = this.onFocus.bind(this);
        this.onSubmit = this.onSubmit.bind(this);
        this.onChangeText = this.onChangeText.bind(this);
        this.onSubmitUsername = this.onSubmitUsername.bind(this);
        this.onSubmitPassword = this.onSubmitPassword.bind(this);
        this.onAccessoryPress = this.onAccessoryPress.bind(this);

        this.usernameRef = this.updateRef.bind(this, 'username');
        this.passwordRef = this.updateRef.bind(this, 'password');

        this.renderPasswordAccessory = this.renderPasswordAccessory.bind(this);

        this.state = {
            secureTextEntry: true,
            username: '',
            password: ''
        };
    }

    onFocus() {
        let {errors = {}} = this.state;

        for (let name in errors) {
            let ref = this[name];

            if (ref && ref.isFocused()) {
                delete errors[name];
            }
        }

        this.setState({errors});
    }

    onChangeText(text) {
        ['username', 'password']
            .map((name) => ({name, ref: this[name]}))
            .forEach(({name, ref}) => {
                if (ref.isFocused()) {
                    this.setState({[name]: text});
                }
            });
    }

    onAccessoryPress() {
        this.setState(({secureTextEntry}) => ({secureTextEntry: !secureTextEntry}));
    }

    onSubmit() {
        const {username, password} = this.state;

        this.props.submit(username, password);
    }

    onSubmitUsername() {
        this.password.focus();
    }

    onSubmitPassword() {
        this.password.blur();
        this.onSubmit();
    }

    updateRef(name, ref) {
        this[name] = ref;
    }

    renderPasswordAccessory() {
        let {secureTextEntry} = this.state;

        let name = secureTextEntry ?
            'visibility' :
            'visibility-off';

        return (
            <MaterialIcon
                size={24}
                name={name}
                color={TextField.defaultProps.baseColor}
                onPress={this.onAccessoryPress}
                suppressHighlighting={true}
            />
        );
    }

    render() {
        let {errors = {}, secureTextEntry} = this.state;
        return (
            <View style={styles.form}>
                <View style={styles.formContainer}>
                    <View style={styles.input}>
                    <TextField
                        ref={this.usernameRef}
                        enablesReturnKeyAutomatically={true}
                        onFocus={this.onFocus}
                        onChangeText={this.onChangeText}
                        onSubmitEditing={this.onSubmitUsername}
                        returnKeyType='next'
                        label="Nom d'utilisateur"
                        error={errors.username}
                        autoCapitalize='none'
                    />
                    </View>

                    <View style={styles.input}>
                    <TextField
                        ref={this.passwordRef}
                        secureTextEntry={secureTextEntry}
                        enablesReturnKeyAutomatically={true}
                        clearTextOnFocus={true}
                        autoCorrect={false}
                        onFocus={this.onFocus}
                        onChangeText={this.onChangeText}
                        onSubmitEditing={this.onSubmitPassword}
                        returnKeyType='done'
                        label='Mot de passe'
                        error={errors.password}
                        renderRightAccessory={this.renderPasswordAccessory}
                    />
                    </View>
                </View>
                <View style={styles.formContainer}>
                    <RaisedTextButton
                        onPress={this.onSubmit}
                        title='Se connecter'
                        color={TextField.defaultProps.tintColor}
                        titleColor='white'
                        disabled={this.props.loading}
                    />
                </View>
            </View>
        );
    }
}

LoginForm.propTypes = {
    submit: PropTypes.func.isRequired,
    loading: PropTypes.bool.isRequired
};