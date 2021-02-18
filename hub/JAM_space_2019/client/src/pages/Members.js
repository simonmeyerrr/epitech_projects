import React from "react";
import "./Members.css"
import APIConfig from "../utils/APIConfig";
import AddIcon from "../assets/add.svg";

class Members extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            members: [],
            selected: null,
            hover: false,
            memberName: "",
            username: "",
            hoverLogout: false,
        };
        this.handleChange = this.handleChange.bind(this);
        this.addMember = this.addMember.bind(this)
        this.toggleHoverEnter = this.toggleHoverEnter.bind(this)
        this.toggleHoverLeave = this.toggleHoverLeave.bind(this)
        this.toggleHoverEnterLogout = this.toggleHoverEnterLogout.bind(this)
        this.toggleHoverLeaveLogout = this.toggleHoverLeaveLogout.bind(this)
        this.getUsers = this.getUsers.bind(this)
    }

    componentDidMount() {
        this.props.refreshOrganisations();
        APIConfig.getUserName().then((response) => {
            this.setState({
                username: response.data.username
            });
        }).catch((error) => {
            if (error && error.response && error.response.status === 401) {
                localStorage.removeItem("token");
                this.props.changePage(0);
            }
        });
    }

    componentDidUpdate(prevProps) {
        if (prevProps.organizations !== this.props.organizations)
            if (this.props.organizations.length > 0) {
                this.getUsers(this.props.organizations[0].name)
            }
    }

    handleChange(event) {
        event.persist();
        this.getUsers(event.target.value)
    };

    getUsers(orga) {
        APIConfig.getOrgaMembers(orga).then((response) => {
            this.setState({
                members: response.data.members,
                selected: orga
            });
        }).catch((error) => {
            if (error && error.response && error.response.status === 401) {
                localStorage.removeItem("token");
                this.props.changePage(0);
            }
        });
    }

    toggleHoverEnter() {
        this.setState({hover: true});
    }

    toggleHoverLeave() {
        this.setState({hover: false});
    }

    toggleHoverEnterLogout() {
        this.setState({hoverLogout: true});
    }

    toggleHoverLeaveLogout() {
        this.setState({hoverLogout: false});
    }

    addMember() {
        if (!this.state.selected)
            return;
        APIConfig.inviteInOrga(this.state.selected, this.state.memberName).then((result) => {
            this.props.refreshOrganisations();
            this.getUsers(this.state.selected);
        }).catch((error) => {
            if (error && error.response && error.response.status === 401) {
                localStorage.removeItem("token");
                this.props.changePage(0);
            }
        });
        this.setState({ memberName: ""});
    }

    onNewMember = (e) => {
        this.setState({ memberName: e.target.value });
    };

    signOut = () => {
        localStorage.removeItem("token");
        this.props.changePage(0);
    };

    render() {
        let classAdd = "select-none orga--add-button__image";
        if (this.state.hover)
            classAdd += "__hover";
        let classLogout
        if (this.state.hoverLogout)
            classLogout = "black-color members-logout border white-color--back black-color--border main-font"
        else
            classLogout = "white-color members-logout  border black-color--back  white-color--border main-font"
        return(
            <div className="members--container">
                <div className="members--first">
                    <div className="black-color second-font members--title">
                        Members of
                    </div>
                    <div className="black-color--back separation-bar" />
                    {
                        this.props.organizations.map((value, index) => {
                            return <div key={ index }>{ value.username }</div>
                        })
                    }
                    <select className="white-color--back border black-color--border select-none button members-select main-font black-color" onChange={ this.handleChange } name="organization" id="organization_select" >
                        {
                            this.props.organizations.map((value, index) => {
                                return <option key={ index } value={ value.name }>{ value.name }</option>
                            })
                        }
                    </select>
                    <div className="black-color--back separation-bar" />

                    <div className="members--member--container">
                        {
                            this.state.members.map((value, index) => {
                                return <Member key={index} username={value.username} />
                            })
                        }
                    </div>
                    <div className="black-color--back separation-bar" />
                    <input
                        className="white-color--back  black-color--border orga--text-box main-font black-color"
                        type="text"
                        name="New Name"
                        value={this.state.memberName}
                        placeholder="Add a member..."
                        onChange={this.onNewMember}/>
                    <button className="white-color--back border black-color--border select-none button orga--add-button main-font black-color" onClick={ this.addMember }
                        onFocus={this.toggleHoverEnter}
                        onBlur={this.toggleHoverLeave}
                        onMouseEnter={this.toggleHoverEnter}
                        onMouseLeave={this.toggleHoverLeave}>
                        <img src={AddIcon} className={classAdd} alt="Add"/>
                    </button>
                </div>
                <div className="members--container-info">
                    <h4 className="black-color second-font members--username">{this.state.username.length >= 15 ? this.state.username.substring(0, 13) + "..." : this.state.username}</h4>
                    <button className={classLogout}
                        onClick={this.signOut}onFocus={this.toggleHoverEnterLogout}
                        onBlur={this.toggleHoverLeaveLogout}
                        onMouseEnter={this.toggleHoverEnterLogout}
                        onMouseLeave={this.toggleHoverLeaveLogout}>
                            Sign Out
                    </button>
                </div>
            </div>
        )
    }
}

class Member extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            hover: false,
        };
    }

    toggleHoverEnter = () => {
        this.setState({hover: true});
    };

    toggleHoverLeave = () => {
        this.setState({hover: false});
    };

    render() {
        return(
            <button className="member-container white-color--back border black-color--border select-none button member--container"
                onFocus={this.toggleHoverEnter}
                onBlur={this.toggleHoverLeave}
                onMouseEnter={this.toggleHoverEnter}
                onMouseLeave={this.toggleHoverLeave}>
                    <div className="main-font black-color member--name">{this.props.username}</div>
            </button>
        )
    }
}

export default Members;