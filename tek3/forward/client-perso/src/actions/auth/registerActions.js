import Constants from '../../constants';

export default {
  register: (username, password) => ({
		type: Constants.REGISTER_REQUEST,
		username,
		password
	}),
  clearRegister: () => ({
	  type: Constants.REGISTER_CLEAR
  })
};
