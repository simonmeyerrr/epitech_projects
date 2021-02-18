import React from 'react';
import {
    StyleSheet,
    View, Text,
    Button, Platform, ScrollView, SafeAreaView
} from 'react-native';
import {Ionicons} from "@expo/vector-icons";
import MyCarousel from "../components/MyCarousel";
import images from "../../assets/images";

const styles = StyleSheet.create({
    container: {
        flex: 1
    }
});

const list = [
    {
        id: 0,
        image: images.red_door
    },
    {
        id: 0,
        image: images.red_door
    },
    {
        id: 0,
        image: images.red_door
    }
];

export default class HomeScreen extends React.Component {
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
                <MyCarousel title={"Recommandé pour vous"} navigate={(index) => {this.props.navigation.push('EscapeGame', {id: index})}} list={list}/>
                <MyCarousel title={"Sponsorisé"} loading navigate={() => {}} list={list}/>
                <MyCarousel title={"Proche de vous"} error={"Erreur du serveur"} navigate={() => {}} list={list}/>
            </ScrollView>
        </SafeAreaView>
    )
  }
}
