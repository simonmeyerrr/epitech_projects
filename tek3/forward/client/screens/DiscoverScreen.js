import React from 'react';
import {Ionicons} from "@expo/vector-icons";
import {
    StyleSheet, Text, Platform, ScrollView, SafeAreaView
} from 'react-native';

import MyCarousel from "../components/MyCarousel";

import images from "../assets";

const styles = StyleSheet.create({
    container: {
        flex: 1
    }
});

const list_reco = [
    {
        id: 0,
        image: images.dernier_casse
    },
    {
        id: 3,
        image: images.el_professor
    },
    {
        id: 1,
        image: images.bunker
    },
    {
        id: 4,
        image: images.yakuza
    },
    {
        id: 2,
        image: images.ghost
    }
];

const list_near = [
    {
        id: 0,
        image: images.red_door
    },
    {
        id: 1,
        image: images.closed_escape
    }
];

export default class DiscoverScreen extends React.Component {
  static navigationOptions = ({ navigation }) => {
      return {
          headerTitle: () => <Text style={{fontSize: 20}}> Découvrir </Text>,
          headerRight: () => (
              <Ionicons
                  name={Platform.OS === 'ios' ? 'ios-search' : 'md-search'}
                  size={26}
                  style={{marginRight: 20}}
                  onPress={() => {navigation.push('Search')}}
              />
          ),
      };
  };

  render() {
    return (
        <SafeAreaView style={styles.container}>
            <ScrollView style={styles.scrollView}>
                <MyCarousel title={"Recommandé pour vous"} navigate={(index) => {this.props.navigation.push('EscapeRoom', {id: index})}} list={list_reco}/>
                <MyCarousel title={"Proche de vous"} navigate={(index) => {this.props.navigation.push('EscapeGame', {id: index})}} list={list_near}/>
                <MyCarousel title={"Sponsorisé"} loading navigate={() => {}} list={[]}/>
            </ScrollView>
        </SafeAreaView>
    )
  }
}
