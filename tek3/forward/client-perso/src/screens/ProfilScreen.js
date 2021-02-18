import React from 'react';
import {Platform, Text} from 'react-native';
import {Ionicons} from "@expo/vector-icons";

export default class ProfilScreen extends React.Component {
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
        return <Text> Profil Oui </Text>;
    }
}
