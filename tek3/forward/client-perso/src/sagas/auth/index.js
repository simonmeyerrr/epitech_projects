import { takeLatest } from 'redux-saga/effects';
import LoginSaga from './loginSaga';
import GetUserTokenSaga from './getUserTokenSaga';
import LogoutSaga from './logoutSaga';
import CleanUserTokenSaga from './cleanUserTokenSaga';
import RegisterSaga from './registerSaga';
import RecoverPasswordSaga from './recoverPasswordSaga';
import Constants from '../../constants';

export function* watchGetLogin() {
  yield takeLatest(Constants.LOGIN_REQUEST, LoginSaga);
}

export function* watchGetToken() {
  yield takeLatest(Constants.GET_USER_TOKEN, GetUserTokenSaga);
}

export function* watchGetLogout() {
  yield takeLatest(Constants.LOGOUT_REQUEST, LogoutSaga);
  yield takeLatest(Constants.GET_USER_TOKEN_ERROR, LogoutSaga);
}

export function* watchCleanToken() {
  yield takeLatest(Constants.CLEAN_USER_TOKEN, CleanUserTokenSaga);
}

export function* watchRegister() {
  yield takeLatest(Constants.REGISTER_REQUEST, RegisterSaga);
}

export function* watchRecoverPassword() {
  yield takeLatest(Constants.RECOVER_PASSWORD_REQUEST, RecoverPasswordSaga);
}
