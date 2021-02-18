import Constants from '../../constants';

export default (state=null, action) => {
  console.log("reducer register");
  switch (action.type) {
    case Constants.REGISTER_REQUEST_SUCCESS:
      return { status: true };
    case Constants.REGISTER_REQUEST_ERROR:
      return { status: false, error: action.error };
    case Constants.REGISTER_REQUEST_LOADING:
      return {};
    case Constants.REGISTER_REQUEST_CLEAR:
    case Constants.REGISTER_REQUEST:
      return null;
    default:
      return state;
  }
};
