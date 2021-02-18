import React from "react";
import ButtonSVG from "../assets/button.svg";
import "./PauseButton.css"
import anime from 'animejs/lib/anime.es.js';
import APIConfig from "../utils/APIConfig";

class PauseButton extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            min: 0,
            size: 0,
            hover: false

        };
        this.click = false;
        this.space = false;
        this.nb = 0;
        this.t = undefined;
        this.s = undefined;
        this.start = 200;
        this.inc = 1;
        this.target = React.createRef();
    }

    onMouseDown = (e) => {
        this.repeat();
        this.sizeUp();
    };

    sizeUp = () => {
        if (!this.click && !this.space) {
            this.reset();
            return;
        }
        if (this.state.size >= 25)
            return;
        this.setState({size: this.state.size + 1});
        this.s = setTimeout(this.sizeUp, this.start);
        anime({
            targets: this.target.current,
            height: 35 + this.state.size / 2 + "vh",
            marginTop: 4  - (this.state.size / 8) + "vh",
            easing: 'easeInSine',
            duration: this.start,
        })
    };

    repeat = () => {
        if (!this.click && !this.space) {
            this.reset();
            return;
        }
        this.increment();
        this.t = setTimeout(this.repeat, this.start);
    };

    increment = () => {
        if (this.state.min >= 20)
            this.inc = 5;
        else if (this.state.min >= 10)
            this.inc = 2;
        this.nb += this.inc;
        this.setState({
            min: this.nb >= 60 ? 60 : Math.floor(this.nb % 60),
        });
    };

    // STOP
    onMouseUp = (e) => {
        APIConfig.createPause(this.nb).then((response) => {
            console.log("Pause sent");
        }).catch((error) => {
            console.log("Cannot send pause");
        });
        clearTimeout(this.t);
        clearTimeout(this.s);
        this.reset();
    };

    reset = () => {
        this.nb = 0;
        this.inc = 1;
        this.setState({
            min: 0,
            size: 0,
        });
        anime({
            targets: this.target.current,
            height: "35vh",
            marginTop: "4vh",
            easing: 'easeOutBounce',
            duration: 1000,
        })
    };

    enter = (e) => {
        this.click = true;
        anime({
            targets: this.target.current,
            height: "36vh",
            marginTop: "3.5vh",
            easing: 'easeInExpo',
            duration: 300,
        })
    };

    leave = (e) => {
        this.click = false;
        anime({
            targets: this.target.current,
            height: "35vh",
            marginTop: "4vh",
            easing: 'easeOutExpo',
            duration: 300,
        })
    };

    handleKeyPress = (event) => {
        if (event.key === ' ' && !this.space){
            this.space = true;
            this.onMouseDown();
        }
    };
    handleKeyUp= (event) => {
        if (event.key === ' '){
            this.space = false;
            this.onMouseUp();
        }
    };

    render() {
        return (
            <div className="pause-button--container">
                <div className="second-font pause-button--number black-color">{this.state.min}</div>
                <div className="second-font pause-button--minute black-color">min.</div>
                <button className="pause-button-container" onTouchStart={this.onMouseDown} onTouchMove={this.leave} onTouchEnd={this.onMouseUp} onMouseUp={this.onMouseUp} onMouseDown={this.onMouseDown} onMouseEnter={this.enter} onMouseLeave={this.leave}
                onFocus={this.enter}
                onBlur={this.leave}>
                    <img ref={this.target} src={ButtonSVG} className="select-none select-none-hard button pause-button" alt="Logo"/>
                </button>
            </div>
    )
    }
}

export default PauseButton;