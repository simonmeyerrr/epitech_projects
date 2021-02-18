import React from "react";
import Login from "./Login";
import Register from "./Register";
import "./SignNaviguation.css"
import * as Config from "../utils/Config";


class SignNaviguator extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            isLoginOpen: true,
            isRegisterOpen: false
        };
    }

    showLogin = () => {
        this.setState({isLoginOpen: true, isRegisterOpen: false});
    };

    showRegister = () => {
        this.setState({isRegisterOpen: true, isLoginOpen: false});
    };

    render() {
        let classes = "centerBody centerHori main-color--back";

        if (Config.ENVIRONMENT === "web")
            classes += " centerVert";
        else
            classes += " box-margin-container";

        return (
            <div className={ classes }>
                <div className="centerIconNav">
                    <img src="/static/media/pause.fd08a111.svg" class="select-none button main-logo centerIconNav" alt="Logo"></img>
                </div>
                <div className="box-controller title-size-Nav">
                    <div className={"controller " + (this.state.isLoginOpen ? "selected-controller" : "") + "select-none button main-font title-Seperation"} onClick={this.showLogin}>
                        Login
                    </div>
                    <div className={"controller " + (this.state.isRegisterOpen ? "selected-controller" : "") + "select-none button main-font title-Seperation"} onClick={this.showRegister}>
                        Register
                    </div>
                </div>
                <div className="box-container">
                    {this.state.isLoginOpen && <Login changePage={ (id) => { this.props.changePage(id) } }/>}
                    {this.state.isRegisterOpen && <Register changePage={ (id) => { this.props.changePage(id) } }/>}
                </div>
            </div>
        );
    }
}

export default SignNaviguator;