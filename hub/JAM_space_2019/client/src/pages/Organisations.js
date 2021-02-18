import React from "react";
import "./Organisation.css"
import APIConfig from "../utils/APIConfig";
import ValideIcon from "../assets/valid.svg";
import DeletIcon from "../assets/delet.svg";
import AddIcon from "../assets/add.svg";

class Organisations extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            orgaName: "",
            hover: false
        };
        this.toggleHoverEnter = this.toggleHoverEnter.bind(this);
        this.toggleHoverLeave = this.toggleHoverLeave.bind(this);
    }

    createOrga = () => {
        APIConfig.createOrga(this.state.orgaName).then((result) => {
            this.props.refreshOrganisations()
        }).catch((error) => {
            if (error && error.response && error.response.status === 401) {
                localStorage.removeItem("token");
                this.props.changePage(0);
            }
            console.error(error);
        });
        this.setState({ orgaName: ""});
    };

    onTeamNameChange = (e) => {
        this.setState({ orgaName: e.target.value });
    };

    changeActive = (name, active) => {
        APIConfig.setOrgaActive(name, active).then((response) => {
            this.props.refreshOrganisations()
        }).catch((error) => {
            if (error && error.response && error.response.status === 401) {
                localStorage.removeItem("token");
                this.props.changePage(0);
            }
            console.error(error);
        });
    };

    toggleHoverEnter() {
        this.setState({hover: true});
    }

    toggleHoverLeave() {
        this.setState({hover: false});
    }

    render() {
        let classAdd = "select-none orga--add-button__image";
        if (this.state.hover)
            classAdd += "__hover";
        return(
            <div className="orga--container">
                <div className="black-color second-font orga--title">My<br/>organizations</div>
                <div className="black-color--back separation-bar" />
                <div className="orga--organisation--container">
                    {
                        this.props.organizations.map((value, index) => {
                            return <Organisation changeActive={ (name, active) => this.changeActive(name, active) } key={index} name={value.name} active={value.active} refresh={this.props.refreshOrganisations}/>
                        })
                    }
                </div>
                <div className="black-color--back separation-bar" />
                <input
                    className="white-color--back  black-color--border orga--text-box main-font black-color"
                    type="text"
                    name="New Name"
                    value={this.state.orgaName}
                    placeholder="Add an organization..."
                    onChange={this.onTeamNameChange}/>
                <button className="white-color--back border black-color--border select-none button orga--add-button main-font black-color" onClick={ this.createOrga }
                    onFocus={this.toggleHoverEnter}
                    onBlur={this.toggleHoverLeave}
                    onMouseEnter={this.toggleHoverEnter}
                    onMouseLeave={this.toggleHoverLeave}>
                    <img src={AddIcon} className={classAdd} alt="Add"/>
                </button>
            </div>
        )
    }
}

class Organisation extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            hover: false,
            hoverDelet: false
        };
        this.delet = this.delet.bind(this)
        this.toggleHoverEnter = this.toggleHoverEnter.bind(this);
        this.toggleHoverLeave = this.toggleHoverLeave.bind(this);
        this.toggleHoverEnterDelet = this.toggleHoverEnterDelet.bind(this);
        this.toggleHoverLeaveDelet = this.toggleHoverLeaveDelet.bind(this);
    }

    toggleHoverEnter() {
        this.setState({hover: true});
    }

    toggleHoverLeave() {
        this.setState({hover: false});
    }

    toggleHoverEnterDelet() {
        this.setState({hoverDelet: true});
        this.setState({hover: true});
    }

    toggleHoverLeaveDelet() {
        this.setState({hoverDelet: false});
        this.setState({hover: false});
    }

    delet(event) {
        event.preventDefault();
        console.log("ok")
        APIConfig.leaveOrga(this.props.name).then((response) => {
            this.props.refresh();
        }).catch((error) => {
            if (error && error.response && error.response.status === 401) {
                localStorage.removeItem("token");
                this.props.changePage(0);
            }
        });
    };

    render() {
        let classBack = "border black-color--border organisation--back";
        let classDelet = "select-none button organisation-delet--icon";
        if (this.state.hover)
            classBack += "__hover";
        else {
            classDelet += "__none"
        }
        if (this.props.active)
            classBack += " black-color--back";
        else
            classBack += " white-color--back";
        if (this.state.hoverDelet)
            classDelet += "__hover";
        return(
            <div className="organisation-container"
            onMouseEnter={this.toggleHoverEnter}
            onMouseLeave={this.toggleHoverLeave}>
                <button className="organisation-button"
                    onClick={ () => { this.props.changeActive(this.props.name, !this.props.active) } }
                    onFocus={this.toggleHoverEnter}
                    onBlur={this.toggleHoverLeave}>
                    <div className="white-color--back border black-color--border organisation--front main-font black-color">
                        {this.props.name.length >= 15 ? this.props.name.substring(0, 13) + "..." : this.props.name}
                        {this.props.active ? <img src={ValideIcon} onMouseUp={this.onMouseUp} className="select-none organisation-valid" onMouseDown={this.onMouseDown} alt="Logo"/> : null}
                    </div>
                    <div className={classBack}/>
                </button>
                <button className="organisation-delet button"
                    onClick={this.delet}
                    onFocus={this.toggleHoverEnterDelet}
                    onBlur={this.toggleHoverLeaveDelet}
                    onMouseEnter={this.toggleHoverEnterDelet}
                    onMouseLeave={this.toggleHoverLeaveDelet}>
                    <img src={DeletIcon} onMouseUp={this.onMouseUp} className={classDelet} onMouseDown={this.onMouseDown} alt="delet"/>
                </button>
            </div>
        )
    }
}

export default Organisations;