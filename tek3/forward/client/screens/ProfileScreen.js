import React from 'react';
import {Platform, Text} from 'react-native';
import {Ionicons} from "@expo/vector-icons";

export default class ProfileScreen extends React.Component {
    static navigationOptions = ({ navigation }) => {
        return {
            headerTitle: () => <Text style={{fontSize: 20}}> Profil </Text>,
            headerRight: () => (
                <Ionicons
                    name={Platform.OS === 'ios' ? 'ios-settings' : 'md-settings'}
                    size={26}
                    style={{marginRight: 20}}
                    onPress={() => {navigation.push('Settings')}}
                />
            ),
        };
    };

    render() {
        return <Text style={{fontSize: 20, textAlign: 'center', marginTop: 40}}> Ici il y a toute les informations de ton compte, mais vu que tu n'as pas de compte, bah il n'y a rien... </Text>;
    }
}
