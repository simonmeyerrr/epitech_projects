import {put, call, all} from 'redux-saga/effects';
import API from '../../api';
import Constants from '../../constants';
import {setToken} from "../../common/localStorage";

export default function* registerSaga({ username, password}) {
  try {
    yield put({ type: Constants.REGISTER_REQUEST_LOADING });
    const res = yield call(API.Auth.register, username, password);
    if (res.success && res.hasOwnProperty("data") && res.data.hasOwnProperty("token")) {
      setToken(res.data.token);
      yield all([
        put({type: Constants.REGISTER_REQUEST_SUCCESS}),
        put({type: Constants.GET_USER_TOKEN}),
      ]);
    } else if (res.success && res.hasOwnProperty("data") && res.data.hasOwnProperty("error"))
      throw Error(res.data.error);
    else
      throw Error("Error with request");
  } catch (error) {
    yield put({ type: Constants.REGISTER_REQUEST_ERROR, error: error.message });
  }
}
