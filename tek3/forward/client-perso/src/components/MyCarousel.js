import React, {Component} from 'react';
import PropTypes from "prop-types";
import {
    View, StyleSheet, ActivityIndicator, Text, Dimensions, Button
} from 'react-native';
import {Card} from 'react-native-elements';
import Carousel from 'react-native-snap-carousel';

const styles = StyleSheet.create({
    container: {
        width: "100%",
        marginVertical: 10
    },
    title: {
        fontSize: 20,
        marginLeft: 10
    },
    content: {
        marginVertical: 10,
        justifyContent: 'center'
    }
});

const data = [
    {
        image: require('./little-red-door.png'),
        title: "oui",
    },
    {
        image: require('./little-red-door.png'),
        title: "non"
    }
];

export default class MyCarousel extends Component {
    constructor(props) {
        super(props);

        this.state = {
        };
        this.renderItem = this.renderItem.bind(this);
    }

    renderItem({item}) {
        return (
            <Card
                image={item.image}
            >
                <Button
                    buttonStyle={{borderRadius: 0, marginLeft: 0, marginRight: 0, marginBottom: 0}}
                    title='En savoir plus'
                    onPress={() => {this.props.navigate(item.id)}}
                />
            </Card>
        );
    }

    render() {
        const content = this.props.loading ? <ActivityIndicator/> :
                          this.props.error ? <Text> {this.props.error} </Text> :
                              <Carousel
                                  data={this.props.list}
                                  renderItem={this.renderItem}
                                  sliderWidth={Dimensions.get('window').width}
                                  itemWidth={200}
                              />;
        return (
            <View style={styles.container}>
                <Text style={styles.title}> {this.props.title} </Text>
                <View style={styles.content}>
                    {content}
                </View>
            </View>
        );
    }
}

MyCarousel.propTypes = {
    title: PropTypes.string.isRequired,
    loading: PropTypes.bool,
    error: PropTypes.string,
    navigate: PropTypes.func.isRequired,
    list: PropTypes.arrayOf(PropTypes.shape({
        id: PropTypes.number.isRequired
    })).isRequired
};