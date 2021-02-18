import React from "react";
import "./Home.css"
import PauseButton from "../components/PauseButton.js"
import Logo from "../assets/pause.svg";

class Home extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
        };
    }

    render() {
        return(
            <div className="home--container">
                <div className="home--go-in main-font black-color">GO TO</div>
                <img src={Logo} onMouseUp={this.onMouseUp} className="select-none button main-logo" onMouseDown={this.onMouseDown} alt="Logo"/>
                <PauseButton/>
            </div>
        )
    }
}

export default Home;