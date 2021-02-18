import {Dimensions, StyleSheet} from "react-native";

const DEVICE_WIDTH = Dimensions.get('window').width;
const DEVICE_HEIGHT = Dimensions.get('window').height;

export default styles = StyleSheet.create({
    container: {
        flex: 1,
        alignItems: 'center',
        backgroundColor: 'transparent',
        justifyContent: 'center',
    },
    error: {
        backgroundColor: 'red',
        color: 'white',
        width: '90%',
        padding: 10,
        margin: 10,
        textAlign: 'center'
    },
});
