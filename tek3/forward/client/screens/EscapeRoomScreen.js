import React, {Component} from 'react';
import {View, Text, StyleSheet, Platform, Image, ScrollView, SafeAreaView} from "react-native";
import {Ionicons} from "@expo/vector-icons";
import ScrollableTabView, {DefaultTabBar, ScrollableTabBar} from 'react-native-scrollable-tab-view-forked';
import Rates from "../components/Rates";
import Scores from "../components/Scores";
import images from "../assets";
import InfosER from "../components/InfosER";

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
        ],
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
        image: images.dernier_casse,
        scores: scores,
        rates: [
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            },
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            }
        ],
        infos: {
            description: "Vous infiltrez la Royal Bank pour y dérober le butin. Dans un premier temps vous agirez en deux groupes, l’un dans les égouts et l’autre dans la salle de vidéo-surveillance. Récupérez un maximum de lingots avant que la police n’arrive !",
            eg_name: "The Little Red Door",
            eg_id: 0,
            min: 4,
            max: 8,
            time: '1h',
            link: 'https://thelittlereddoor.fr/salles/le-dernier-casse'
        }
    },
    {
        name: "Bunker B-57",
        image: images.bunker,
        scores: scores,
        rates: [
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            },
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            }
        ],
        infos: {
            description: "Année 2052. depuis l’explosion nucléaire de 1960 l’humanité vit retranchée dans des abris souterrains alimentés par du Plutonium. New Atlanta en est à cours, la situation est critique. Votre équipe part en expédition dans un bunker abandonné afin de récupérer du Plutonium pour sauver la ville !",
            eg_name: "The Little Red Door",
            eg_id: 0,
            min: 2,
            max: 5,
            time: '1h',
            link: 'https://thelittlereddoor.fr/salles/bunker-b-57-expedition-plutonium/'
        }
    },
    {
        name: "GHOST: Chasseurs de fantômes",
        image: images.ghost,
        scores: scores,
        rates: [
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            },
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            }
        ],
        infos: {
            description: "Il y a de nombreuses années un funeste événement est survenu au manoir des Van Emberg. La demeure est depuis hantée par un fantôme… Les nouveaux propriétaires ont donc décidé de faire appel à votre équipe de chasseurs de fantômes. Vous avez une heure pour capturer l’esprit qui hante les lieux.",
            eg_name: "The Little Red Door",
            eg_id: 0,
            min: 2,
            max: 5,
            time: '1h',
            link: 'https://thelittlereddoor.fr/salles/bunker-b-57-expedition-plutonium/'
        }
    },
    {
        name: "El professor",
        image: images.el_professor,
        scores: scores,
        rates: [
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            },
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            }
        ],
        infos: {
            description: "Braquez la fabrique de monnaie et imprimez le plus de billets possible avant que la police n'intervienne. Inquiets...? Aucun problème, le professeur vous guidera pas à pas...",
            eg_name: "Closed Escape",
            eg_id: 1,
            min: 2,
            max: 5,
            time: '1h',
            link: 'https://closed-escapegame.com/reservation-strasbourg'
        }
    },
    {
        name: "Yakuza",
        image: images.yakuza,
        scores: scores,
        rates: [
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            },
            {
                username: "Anonyme",
                comment: "oui c'est cool"
            }
        ],
        infos: {
            description: "Retrouvez le comptable disparu de l'organisation et sauvez les données cryptées avant que la police ou un gang rival ne mette la main dessus...",
            eg_name: "Closed Escape",
            eg_id: 1,
            min: 2,
            max: 5,
            time: '1h',
            link: 'https://closed-escapegame.com/reservation-strasbourg'
        }
    }
];

export default class EscapeRoomScreen extends Component {
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
                        <InfosER key={'1'} tabLabel={'À propos'} info={infos.infos} seeEG={() => this.props.navigation.push('EscapeGame', {id: infos.infos.eg_id})}/>
                        <Scores key={'2'} tabLabel={'Scores'} navigate={() => {}} list={infos.scores}/>
                        <Rates key={'3'} tabLabel={'Avis'} list={infos.rates}/>
                    </ScrollableTabView>
                </ScrollView>
            </SafeAreaView>
        );
    }
}

const styles = StyleSheet.create({
    container: {
        flex: 1
    },
    image: {
        width: 150,
        height: 200,
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