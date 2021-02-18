import {AsyncStorage} from 'react-native';

export function getItem(item) {
  return AsyncStorage.getItem(item)
    .then(data => JSON.parse(data))
    .catch(error => Error(error))

}

export function setItem(item, value) {
  return AsyncStorage.setItem(item, JSON.stringify(value))
    .then()
    .catch()
}

export function removeItem(item) {
  return AsyncStorage.removeItem(item)
    .then()
    .catch()
}

export function unsetToken() {
  removeItem('token');
}

export function getToken() {
  return AsyncStorage.getItem('token')
    .then(data => JSON.parse(data))
    .catch(error => Error(error))
}

export function setToken(token) {
  return AsyncStorage.setItem('token', JSON.stringify(token))
    .then()
    .catch()
}