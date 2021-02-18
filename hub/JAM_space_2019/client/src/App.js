import React from 'react';
import './App.css';
import SignNaviguator from "./components/SignNaviguator";
import './Config.css'
import Organisations from "./pages/Organisations"
import Home from "./pages/Home"
import Members from "./pages/Members"
import APIConfig from "./utils/APIConfig";
import * as Config from "./utils/Config";

class App extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            organizations: [],
            pause: [],
            isMobile: false,
            displayMenu:false,
            pageIdMobile: 2
        }
        this.t = undefined;
        this.changePageMobile = this.changePageMobile.bind(this)
        this.displayMenu = this.displayMenu.bind(this)
        this.refreshOrganisations = this.refreshOrganisations.bind(this)
        this.getUsersINPause();
    }

    componentDidMount() {
        this.handleResize();
        window.addEventListener('resize', this.handleResize);
        this.changePage(1)
    }

    refreshOrganisations() {
        APIConfig.getOrgas().then((result) => {
            this.setState({
                organizations: result.data.organizations
            });
        }).catch((error) => {
            if (error && error.response && error.response.status === 401) {
                localStorage.removeItem("token");
                this.changePage(0);
            }
            console.error(error);
        })
    }

    handleResize = () => {
        if (window.innerWidth <= 1000 && !this.state.isMobile)
            this.setState({
                isMobile: true
            });
            else if (window.innerWidth > 1000 && this.state.isMobile)
            this.setState({
                isMobile: false
            });
    };

    changePage(id) {
        if (id < 0 || id > 1)
            return;

        if (id === 1 && !localStorage.getItem("token"))
            id = 0;
        else if (id === 1)
            this.refreshOrganisations();

        this.setState({
            pageId: id
        });
    };

    displayMenu() {
        this.setState({displayMenu: !this.state.displayMenu});
    }

    changePageMobile(id) {
        if (id >=1 && id <= 3)
            this.setState({pageIdMobile: id})
    }

    getUsersINPause = () => {
        APIConfig.getPauses().then((result) => {
            if (result.data[0])
                this.setState({
                        pause: {name: result.data[0].username, time: result.data[0].pause_size, date: result.data[0].pause_date}
                });
            this.t = setTimeout(this.getUsersINPause, 1000);
        }).catch((error) => {
            if (error && error.response && error.response.status === 401) {
                localStorage.removeItem("token");
                clearTimeout(this.t);
                this.changePage(0);
            }
            console.error(error);
        })
    };

    render() {
        let classes = "app--mobile main-color--back";

        if (Config.ENVIRONMENT === "extension")
            classes += " extension-sizes";

        if (this.state.pageId === 0)
            return (<div className={ classes }><SignNaviguator changePage={ (id) => { this.changePage(id) }} /> </div>);
        else {
            let right;
            let left;
            let page;
            if (this.state.isMobile) {
                if (this.state.pageIdMobile === 1) {
                    right = {id: 2, name: "Home"}
                    left = {id: 3, name: "Memb"}
                    page = <Organisations changePage={ (id) => { this.changePage(id)}} refreshOrganisations={this.refreshOrganisations} organizations={this.state.organizations}/>
                }
                else if (this.state.pageIdMobile === 2) {
                    right = {id: 3, name: "Memb"}
                    left = {id: 1, name: "Orga"}
                    page = <Home changePage={ (id) => { this.changePage(id)}} refreshOrganisations={this.refreshOrganisations} organizations={this.state.organizations}/>
                }
                else if (this.state.pageIdMobile === 3) {
                    right = {id: 1, name: "Orga"}
                    left = {id: 2, name: "Home"}
                    page = <Members changePage={ (id) => { this.changePage(id)}} refreshOrganisations={this.refreshOrganisations} organizations={this.state.organizations}/>
                }
            }
            let classes2 = "app--mobile main-color--back";

            if (Config.ENVIRONMENT === "extension")
                classes2 += " extension-sizes";

            return (
                <div>
                {this.state.isMobile ?
                    <div className={ classes2 }>
                        <MoveButton side="right" redirection={right} callback={this.changePageMobile}/>
                        {page}
                        <MoveButton side="left" redirection={left} callback={this.changePageMobile}/>
                    </div>
                :
                    <div className="app--navigator main-color--back">
                        <Organisations changePage={ (id) => { this.changePage(id)}} refreshOrganisations={this.refreshOrganisations} organizations={this.state.organizations}/>
                        <Home changePage={ (id) => { this.changePage(id)}}/>
                        <Members changePage={ (id) => { this.changePage(id)}} refreshOrganisations={this.refreshOrganisations} organizations={this.state.organizations}/>
                    </div>
                }
                <Notif pause={this.state.pause}/>
                </div>
            );
        }
    }
}

class MoveButton extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
        }
    }

    render() {
        let classButton = "button move-button--container border black-color-border white-color--back black-color main-font " + this.props.side;
        return (
            <button className={classButton} onClick={() => {this.props.callback(this.props.redirection.id)}}>
                <div className="move-button--text">{this.props.redirection.name}</div>
            </button>
        );
    }
}

class Notif extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
        }
    }

    render() {
        let name = "name";
        let time = "time";
        let date = "";
        if (this.props.pause) {
            name = this.props.pause.name;
            time = this.props.pause.time;
            date = new Date(this.props.pause.date).getHours() + ":" + new Date(this.props.pause.date).getMinutes();
        }
        return (
            <div className="white-color--back black-color--border notif-bar main-font">
                {date} - {name}<pre> </pre><span className="notif-text">started a </span><pre> </pre>{time} min. <pre> </pre><span className="notif-text"> pause</span>
            </div>
        );
    }
}

export default App;
