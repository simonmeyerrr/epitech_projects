import { combineReducers } from 'redux';
import token from './tokenReducer';
import registerStatus from './registerReducer';
import loginStatus from './loginReducer';
import recoverStatus from './recoverReducer';

export default combineReducers({
  token,
  registerStatus,
  loginStatus,
  recoverStatus
});
