import React, {Component} from 'react';
import {
    View, StyleSheet, ActivityIndicator, Text, Dimensions, Button, Linking, Platform
} from 'react-native';
import {ListItem} from "react-native-elements";
import {Ionicons} from "@expo/vector-icons";

class Info extends Component {
    render() {
        return (
            <ListItem
                onPress={() => {this.props.onPress()}}
                title={<View style={{height: 0}}/>}
                subtitle={
                    this.props.children
                }
                bottomDivider
            />
        );
    }
}

export default class InfosEG extends Component {
    constructor(props) {
        super(props);

        this.state = {
        };
    }

    render() {
        return (
            <View>
                <Info>
                    <Text>{this.props.info.description}</Text>
                </Info>
                <Info>
                    <View>
                        <Text style={{fontSize: 18, textAlign: 'center', margin: 5}}> {this.props.info.nb_room} aventures</Text>
                        <Text style={{fontSize: 18, textAlign: 'center', margin: 5, paddingBottom: 10}}> Jusqu'à {this.props.info.max} joueurs simultanés</Text>
                        <Button title={'Voir le site'} onPress={() => {Linking.openURL(this.props.info.link)}}/>
                    </View>
                </Info>
            </View>
        );
    }
}

const styles = StyleSheet.create({
    description: {
        fontSize: 15,
        margin: 20,
        alignSelf: "center"
    }
});