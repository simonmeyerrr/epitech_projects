import React, {Component} from 'react';
import PropTypes from "prop-types";
import {
    View, StyleSheet, ActivityIndicator, Text, Dimensions, Button, Image
} from 'react-native';
import {Card, ListItem} from 'react-native-elements';

export class Aventure extends Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <ListItem
                subtitle={
                    <View style={styles.subtitleView}>
                        <Image source={this.props.image} style={styles.ratingImage}/>
                        <View>
                            <Text style={styles.title}> {this.props.name} </Text>
                            <Text style={styles.ratingText}> {this.props.description} </Text>
                        </View>
                    </View>
                }
                bottomDivider
                onPress={() => {this.props.navigate(this.props.id)}}
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
                                id={u.id}
                                navigate={(index) => {this.props.navigate(index)}}
                            />
                        );
                    })
                }
            </View>
        );
    }
}

const styles = StyleSheet.create({
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