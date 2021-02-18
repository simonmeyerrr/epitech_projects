import Login from './loginActions';
import Token from './tokenActions';
import Logout from './logoutActions';
import Register from './registerActions';
import ForgotPassword from './forgotPasswordActions';

export default {
	...Login,
	...Token,
	...Logout,
	...Register,
	...ForgotPassword
};
