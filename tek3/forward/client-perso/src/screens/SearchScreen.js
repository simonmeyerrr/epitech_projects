import React, {Component} from 'react';
import {connect} from 'react-redux';
import {View, Text, StyleSheet, Platform} from "react-native";
import {Ionicons} from "@expo/vector-icons";

export class SearchScreen extends Component {
    static navigationOptions = ({ navigation }) => {
        return {
            headerTitle: () => <Text style={{fontSize: 20}}> Recherche </Text>,
            headerLeft: () => (
                <Ionicons
                    name={Platform.OS === 'ios' ? 'ios-arrow-round-back' : 'md-arrow-round-back'}
                    size={26}
                    style={{marginLeft: 20}}
                    onPress={() => {navigation.goBack()}}
                />
            ),
        };
    };

    constructor(props) {
        super(props);
    }

    componentWillUnmount() {
    }

    componentWillMount() {
    }

    render() {
        return (
            <View style={styles.container}>
                <Text> SEARCH </Text>
            </View>
        );
    }
}

SearchScreen.propTypes = {
};

const mapStateToProps = (state) => ({
});

const mapDispatchToProps = (dispatch) => ({
});

export default connect(mapStateToProps, mapDispatchToProps)(SearchScreen);