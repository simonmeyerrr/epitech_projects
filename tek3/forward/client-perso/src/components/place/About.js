import React from 'react';
import PropTypes from "prop-types";
import {View, Text, StyleSheet, Dimensions} from "react-native";
import styles from '../../../assets/StyleSheet'

const { width, height } = Dimensions.get('window');

class About extends React.Component {
    render () {
        return (
            <View style={{alignItems: 'center', marginTop: 150}}>
                <Text>{this.props.description}</Text>
                <Text>{this.props.phone}</Text>
                <Text>{this.props.website}</Text>
                <Text>{this.props.address}</Text>
            </View>
        );
    }
}

About.propTypes = {
    description: PropTypes.string.isRequired,
    phone: PropTypes.string.isRequired,
    website: PropTypes.string.isRequired,
    address: PropTypes.string.isRequired
};

export default About;