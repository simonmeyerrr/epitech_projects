import React, {Component} from 'react';
import {
    View, StyleSheet, ActivityIndicator, Text, Dimensions, Button
} from 'react-native';
import {Card, ListItem} from 'react-native-elements';

export class Rate extends Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <ListItem
                title={this.props.name}
                subtitle={
                    <View style={styles.subtitleView}>
                        <Text style={styles.ratingText}> {this.props.comment} </Text>
                    </View>
                }
                bottomDivider
            />
        );
    }
}

export default class Rates extends Component {
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
                            <Rate
                                key={i}
                                name={u.username}
                                comment={u.comment}
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
        paddingLeft: 10,
        paddingTop: 5
    },
    ratingImage: {
        height: 19.21,
        width: 100
    },
    ratingText: {
        paddingLeft: 10,
        color: 'grey'
    }
});