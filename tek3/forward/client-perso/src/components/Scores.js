import React, {Component} from 'react';
import PropTypes from "prop-types";
import {
    View, StyleSheet, ActivityIndicator, Text, Dimensions, Button, Image
} from 'react-native';
import {Card, ListItem} from 'react-native-elements';

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

export class Score extends Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <ListItem
                subtitle={
                    <View style={myStyles.subtitleView}>
                        <View style={{width: 30, paddingHorizontal: 2}}>
                            <Text style={myStyles.title}> {this.props.place} </Text>
                        </View>
                        <View style={{width: "auto", paddingHorizontal: 2}}>
                            <Text style={myStyles.title}> {this.props.name} </Text>
                        </View>
                        <View style={{width: 50, paddingHorizontal: 2}}>
                            <Text style={myStyles.title}> {this.props.score} </Text>
                        </View>
                        <View style={{width: 50, paddingHorizontal: 2}}>
                            <Text style={myStyles.title}> {this.props.time} </Text>
                        </View>
                    </View>
                }
                bottomDivider
            />
        );
    }
}

export default class Scores extends Component {
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
                            <Score
                                key={i}
                                place={u.place}
                                name={u.name}
                                members={u.members}
                                score={u.score}
                                time={u.time}
                            />
                        );
                    })
                }
            </View>
        );
    }
}

Scores.propTypes = {
};