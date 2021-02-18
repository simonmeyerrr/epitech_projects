import { createStore, applyMiddleware, compose } from 'redux';
import createSagaMiddleware from 'redux-saga';

import rootReducer from '../reducers';
import rootSaga from '../sagas';
import initialState from './initialState';

export default () => {
  const sagaMiddleware = createSagaMiddleware();
  const composeEnhancers = compose;
  const middlewares = applyMiddleware(sagaMiddleware);

  return {
    ...createStore(
      rootReducer,
      initialState,
      composeEnhancers(middlewares)
    ),
    runSaga: sagaMiddleware.run(rootSaga)
  };
};