import React, {Component} from 'react';
import {
    View, StyleSheet, ActivityIndicator, Text, Dimensions, Button, Image
} from 'react-native';

import {Card, ListItem} from 'react-native-elements';
import Expandable from 'react-native-expandable';

export class Score extends Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <ListItem
                title={<View style={{height: 0}}/>}
                subtitle={
                    <View>
                    <Expandable title={<Text style={styles.title}> {this.props.place} {"\t"} {this.props.name} </Text>} collapsed={true}>
                        {
                            this.props.members.map((u, i) => {
                                return (
                                    <Text key={i}>
                                        {u}
                                    </Text>
                                );
                            })
                        }
                    </Expandable>
                    <Text style={styles.footer}> Score: {this.props.score} {"      "} Temps: {this.props.time} </Text>
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

const styles = StyleSheet.create({
    title: {
        fontSize: 20,
    },
    footer: {
        paddingTop: 20,
        textAlign: 'center',
        width: '100%',
        fontSize: 20
    }
});