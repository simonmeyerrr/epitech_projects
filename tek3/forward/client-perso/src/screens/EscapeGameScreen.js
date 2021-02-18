import React, {Component} from 'react';
import {connect} from 'react-redux';
import {View, Text, StyleSheet, Platform, Image, ScrollView, SafeAreaView} from "react-native";
import {Ionicons} from "@expo/vector-icons";
import ScrollableTabView, {DefaultTabBar, ScrollableTabBar} from 'react-native-scrollable-tab-view-forked';
import Aventures from "../components/Aventures";
import Rates from "../components/Rates";
import images from "../../assets/images";

const escapeGames = [
    {
        name: "The Little Red Door",
        description: "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.",
        image: images.red_door,
        rooms: [
            {
                name: "Le dernier casse",
                description: "OLALA LE BRAKAGE",
                image: images.dernier_casse
            },
            {
                name: "Le dernier casse",
                description: "OLALA LE BRAKAGE",
                image: images.dernier_casse
            },
            {
                name: "Le dernier casse",
                description: "OLALA LE BRAKAGE",
                image: images.dernier_casse
            }
        ],
        rates: [
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            },
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            },
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            },
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            },
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            },
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            }
        ]
    }
];

const myStyles = StyleSheet.create({
    image: {
        width: 150,
        height: 150,
        marginVertical: 20,
        alignSelf: "center"
    },
    title: {
        fontSize: 30,
        marginVertical: 10,
        alignSelf: "center"
    },
    description: {
        fontSize: 13,
        marginHorizontal: 30,
        alignSelf: "center"
    },
    tabStyle: {},
    scrollStyle: {
        backgroundColor: 'white',
        // justifyContent: 'center',
    },
    tabBarTextStyle: {
        fontSize: 18,
    },
    underlineStyle: {
        height: 3,
        backgroundColor: 'blue',
        borderRadius: 3,
        width: 15,
    },
});

export class EscapeGameScreen extends Component {
    static navigationOptions = ({navigation}) => {
        return {
            headerTitle: () => <Text style={{fontSize: 20}}> Escape Game </Text>,
            headerLeft: () => (
                <Ionicons
                    name={Platform.OS === 'ios' ? 'ios-arrow-round-back' : 'md-arrow-round-back'}
                    size={26}
                    style={{marginLeft: 20}}
                    onPress={() => {
                        navigation.goBack()
                    }}
                />
            ),
        };
    };

    constructor(props) {
        super(props);
        this.state = {};
    }

    componentWillUnmount() {
    }

    componentWillMount() {
    }

    render() {
        const infos = escapeGames[this.props.navigation.getParam('id')];
        return (
            <SafeAreaView style={styles.container}>
                <ScrollView>
                    <Image source={infos.image} style={myStyles.image}/>
                    <Text style={myStyles.title}> {infos.name} </Text>
                    <Text style={myStyles.description}> {infos.description} </Text>
                    <ScrollableTabView
                        renderTabBar={() => (
                            <ScrollableTabBar
                                style={myStyles.scrollStyle}
                                tabStyle={myStyles.tabStyle}
                            />
                        )}
                        tabBarTextStyle={myStyles.tabBarTextStyle}
                        tabBarInactiveTextColor={'black'}
                        tabBarActiveTextColor={'blue'}
                        tabBarUnderlineStyle={myStyles.underlineStyle}
                        initialPage={0}
                    >

                        <Aventures key={'1'} tabLabel={'Aventures'} navigate={(index) => {this.props.navigation.push('EscapeRoom', {id: index})}} list={infos.rooms}/>
                        <Rates key={'2'} tabLabel={'Avis'} list={infos.rates}/>
                    </ScrollableTabView>
                </ScrollView>
            </SafeAreaView>
        );
    }
}

EscapeGameScreen.propTypes = {};

const mapStateToProps = (state) => ({});

const mapDispatchToProps = (dispatch) => ({});

export default connect(mapStateToProps, mapDispatchToProps)(EscapeGameScreen);