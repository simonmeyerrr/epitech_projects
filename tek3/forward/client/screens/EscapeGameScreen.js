import React, {Component} from 'react';
import {View, Text, StyleSheet, Platform, Image, ScrollView, SafeAreaView} from "react-native";
import {Ionicons} from "@expo/vector-icons";
import ScrollableTabView, {DefaultTabBar, ScrollableTabBar} from 'react-native-scrollable-tab-view-forked';
import Aventures from "../components/Aventures";
import Rates from "../components/Rates";
import images from "../assets";
import InfosEG from "../components/InfosEG";

const escapeGames = [
    {
        name: "The Little Red Door",
        image: images.red_door,
        infos: {
            description: "Avec des escape rooms accueillant jusqu'à 8 personnes vous allez pouvoir inviter tous vos amis pour vous immerger dans les salles obscures de The Little Red Door au coeur de Strasbourg...",
            nb_room: 3,
            max: 20,
            link: 'https://thelittlereddoor.fr'
        },
        rooms: [
            {
                id: 0,
                name: "Le dernier casse",
                description: "OLALA LE BRAKAGE",
                image: images.dernier_casse
            },
            {
                id: 1,
                name: "Bunker B-57",
                description: "RADIOACTIVE",
                image: images.bunker
            },
            {
                id: 2,
                name: "Ghost",
                description: "Casper calme toi",
                image: images.ghost
            }
        ],
        rates: [
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            }
        ]
    },
    {
        name: "Closed Escape",
        image: images.closed_escape,
        infos: {
            description: "C'est au cœur de Strasbourg que Daniel et son équipe vous accueillent pour une heure d'aventure ! Closed escape game vous ouvre les portes tous les jours de 9h à 22H",
            nb_room: 2,
            max: 12,
            link: 'https://closed-escapegame.com/strasbourg'
        },
        rooms: [
            {
                id: 3,
                name: "El professor",
                description: "BELLA CIAO",
                image: images.el_professor
            },
            {
                id: 4,
                name: "Yakuza",
                description: "ching chong",
                image: images.yakuza
            }
        ],
        rates: [
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            }
        ]
    }
];

export default class EscapeGameScreen extends Component {
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

    render() {
        const infos = escapeGames[this.props.navigation.getParam('id')];
        return (
            <SafeAreaView style={styles.container}>
                <ScrollView>
                    <Image source={infos.image} style={styles.image}/>
                    <Text style={styles.title}> {infos.name} </Text>
                    <ScrollableTabView
                        renderTabBar={() => (
                            <ScrollableTabBar
                                style={styles.scrollStyle}
                                tabStyle={styles.tabStyle}
                            />
                        )}
                        tabBarTextStyle={styles.tabBarTextStyle}
                        tabBarInactiveTextColor={'black'}
                        tabBarActiveTextColor={'blue'}
                        tabBarUnderlineStyle={styles.underlineStyle}
                        initialPage={0}
                    >
                        <InfosEG key={'1'} tabLabel={'À propos'} info={infos.infos}/>
                        <Aventures key={'2'} tabLabel={'Aventures'} navigate={(id) => {this.props.navigation.push('EscapeRoom', {id: id})}} list={infos.rooms}/>
                        <Rates key={'3'} tabLabel={'Avis'} list={infos.rates}/>
                    </ScrollableTabView>
                </ScrollView>
            </SafeAreaView>
        );
    }
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
    },
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
        backgroundColor: 'white',
        borderRadius: 3,
        width: 15,
    },
});