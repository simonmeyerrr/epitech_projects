import React from "react";
import APIConfig from "../utils/APIConfig"
import Play from "../assets/play.svg";

class Login extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            username: "",
            password: "",
            error: ""
        };
    }

    setError = (error) => {
        this.setState({
            error: "Error: " + error
        });
    };

    submitLogin = () => {
        if (!this.state.username || this.state.username.length === 0 ||
            !this.state.password || this.state.password.length === 0) {
            this.setError("Missing fields.");
            return;
        }

        APIConfig.login(this.state.username, this.state.password).then((response) => {
            localStorage.setItem("token", response.data.token);

            this.props.changePage(1);
        }).catch((error) => {
            console.log(error);
            this.setError("Invalid credentials.")
        });
    };

    onUsernameChange = (e) => {
        this.setState({username: e.target.value});
    };

    onPasswordChange = (e) => {
        this.setState({password: e.target.value});
    };

    render() {
        return (
            <div className="inner-container">
                <div class="black-color second-font login-title">Connection</div>
                <div className="box">
                    <div className="input-group">
                        <input
                            type="text"
                            name="username"
                            className="white-color--back  black-color--border orga--text-box main-font black-color"
                            placeholder="Username"
                            onChange={this.onUsernameChange}/>
                    </div>
                    <div className="input-group">
                        <input
                            type="password"
                            name="password"
                            className="white-color--back  black-color--border orga--text-box main-font black-color"
                            placeholder="Password"
                            onChange={this.onPasswordChange}/>
                    </div>
                    <div className="input-group centerBody">
                        <button className="button-size-Nav select-none button orga--add-button main-font black-color " onClick={ this.submitLogin }>
                            <img src={Play} className="select-none button centerIconNav sizeImg" alt="Logo"></img>
                        </button>
                    </div>
                    <p className="error">
                        { this.state.error }
                    </p>
                </div>
            </div>
        );
    }
}

export default Login;