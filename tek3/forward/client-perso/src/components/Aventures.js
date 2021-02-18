import React, {Component} from 'react';
import PropTypes from "prop-types";
import {
    View, StyleSheet, ActivityIndicator, Text, Dimensions, Button, Image
} from 'react-native';
import {Card, ListItem} from 'react-native-elements';

const data = [
    {
        image: require('../../assets/images/le-dernier-casse.jpg'),
        name: "Le dernier casse",
        description: "Oui c'est cool lol"
    },
    {
        image: require('../../assets/images/le-dernier-casse.jpg'),
        name: "Le dernier casse",
        description: "Oui c'est cool lol"
    },
    {
        image: require('../../assets/images/le-dernier-casse.jpg'),
        name: "Le dernier casse",
        description: "Oui c'est cool lol"
    },
];

const myStyles = StyleSheet.create({
    subtitleView: {
        flexDirection: 'row',
    },
    ratingImage: {
        maxWidth: 100,
        maxHeight: 160
    },
    ratingText: {
        paddingLeft: 10,
        color: 'grey'
    },
    title: {
        fontSize: 20
    }
});

export class Aventure extends Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <ListItem
                subtitle={
                    <View style={myStyles.subtitleView}>
                        <Image source={this.props.image} style={myStyles.ratingImage}/>
                        <View>
                            <Text style={myStyles.title}> {this.props.name} </Text>
                            <Text style={myStyles.ratingText}> {this.props.description} </Text>
                        </View>
                    </View>
                }
                bottomDivider
                onPress={() => {this.props.navigate(1)}}
            />
        );
    }
}

export default class Aventures extends Component {
    constructor(props) {
        super(props);

        this.state = {
        };
    }

    render() {
        return (
            <View>
                {
                    this.props.list.map((u, i) => {
                        return (
                            <Aventure
                                key={i}
                                name={u.name}
                                description={u.description}
                                image={u.image}
                                navigate={(index) => {this.props.navigate(index)}}
                            />
                        );
                    })
                }
            </View>
        );
    }
}

Aventures.propTypes = {
};