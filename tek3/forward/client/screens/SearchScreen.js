import React, {Component} from 'react';
import {View, Text, StyleSheet, Platform} from "react-native";
import {Ionicons} from "@expo/vector-icons";
import {SearchBar} from "react-native-elements";

export default class SearchScreen extends Component {
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
        this.state = {
            search: ""
        };
        this.updateSearch = this.updateSearch.bind(this);
    }

    updateSearch(search) {
        this.setState({ search });
    };

    render() {
        return (
            <View style={styles.container}>
                <SearchBar
                    placeholder=""
                    onChangeText={this.updateSearch}
                    value={this.state.search}
                    lightTheme={true}
                />
                <Text> Je suppose que tu t'intéresses à {this.state.search} </Text>
            </View>
        );
    }
}

const styles = StyleSheet.create({
    container: {
        flex: 1
    },
});
