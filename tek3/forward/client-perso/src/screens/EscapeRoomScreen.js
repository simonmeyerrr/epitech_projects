import React, {Component} from 'react';
import {connect} from 'react-redux';
import {View, Text, StyleSheet, Platform, Image, ScrollView, SafeAreaView} from "react-native";
import {Ionicons} from "@expo/vector-icons";
import ScrollableTabView, {DefaultTabBar, ScrollableTabBar} from 'react-native-scrollable-tab-view-forked';
import Aventures from "../components/Aventures";
import Rates from "../components/Rates";
import Scores from "../components/Scores";

const scores = [
    {
        place: 1,
        name: 'Les BG',
        score: 750,
        time: '50:30',
        members: [
            "simon",
            "oui",
            "non"
        ]
    },
    {
        place: 2,
        name: 'Les tryhardeurs',
        score: 730,
        time: '52:20',
        members: [
            "simon",
            "oui",
            "non"
        ]
    },
    {
        place: 3,
        name: 'Les oui',
        score: 680,
        time: '56:30',
        members: [
            "simon",
            "oui",
            "non"
        ]
    },
    {
        place: 4,
        name: 'Blabla',
        score: 750,
        time: '57:30',
        members: [
            "simon",
            "oui",
            "non"
        ]
    },
    {
        place: 5,
        name: 'Et ca fait',
        score: 40,
        time: '58:30',
        members: [
            "bim",
            "bam",
            "boom"
        ]
    }
];

const escapeGames = [
    {
        name: "Le dernier casse",
        description: "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.",
        image: require('../../assets/images/le-dernier-casse.jpg'),
        scores: scores,
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
        ],
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

export class EscapeRoomScreen extends Component {
    static navigationOptions = ({navigation}) => {
        return {
            headerTitle: () => <Text style={{fontSize: 20}}> Escape Room </Text>,
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
        const infos = escapeGames[0];
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

                        <Scores key={'1'} tabLabel={'Scores'} navigate={() => {}} list={infos.scores}/>
                        <Rates key={'2'} tabLabel={'Avis'} list={infos.rates}/>
                    </ScrollableTabView>
                </ScrollView>
            </SafeAreaView>
        );
    }
}

EscapeRoomScreen.propTypes = {};

const mapStateToProps = (state) => ({});

const mapDispatchToProps = (dispatch) => ({});

export default connect(mapStateToProps, mapDispatchToProps)(EscapeRoomScreen);