import React, {Component} from 'react';
import {
    View, StyleSheet, ActivityIndicator, Text, Dimensions, Button, Platform, Linking
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

export default class InfosER extends Component {
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
                        <Text style={{fontSize: 18, textAlign: 'center', margin: 5}}> Temps de jeu: {this.props.info.time}</Text>
                        <Text style={{fontSize: 18, textAlign: 'center', margin: 5, paddingBottom: 10}}> De {this.props.info.min} à {this.props.info.max} joueurs</Text>
                        <Button title={'Réserver'} onPress={() => {Linking.openURL(this.props.info.link)}}/>
                    </View>
                </Info>
                <Info onPress={this.props.seeEG}>
                    <View style={{flex: 1, flexDirection: 'row', alignItems: "flex-start", justifyContent: 'space-between'}}>
                        <View>
                            <Text style={{width: 300, fontSize: 18, textAlign: "center"}}>Cet Escape Room est proposé par {this.props.info.eg_name}.</Text>
                        </View>
                        <View>
                        <Ionicons
                            name={Platform.OS === 'ios' ? 'ios-arrow-forward' : 'md-arrow-forward'}
                            size={30}
                            color="black"
                        />
                        </View>
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