import { call } from './misc.js';

export const login = (username, password) => {
  return call('/login', 'POST', {username, password});
};

export const register = (username, password) => {
  return call('/register', 'POST', {username, password});
};

export const recoverPassword = (username) => {
  return call('/recover-password', 'POST', {username});
};
