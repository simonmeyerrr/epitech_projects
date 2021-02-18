import Constants from '../../constants';

export default {
  recover: (username) => ({
    type: Constants.RECOVER_PASSWORD_REQUEST,
    username
  }),
  clearRecover: () => ({
    type: Constants.RECOVER_PASSWORD_CLEAR
  }),
};
