import React, {Component} from 'react';
import {
    View, StyleSheet, ActivityIndicator, Text, Dimensions, Button
} from 'react-native';
import {Card} from 'react-native-elements';
import Carousel from 'react-native-snap-carousel';

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
                imageStyle={{height: 200}}
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