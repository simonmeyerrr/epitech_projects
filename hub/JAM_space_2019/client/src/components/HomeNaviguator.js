import React from "react";
import Navbar from "./Navbar";
import Home from "../pages/Home";
import Organisations from "../pages/Organisations";
import Members from "../pages/Members";

class HomeNaviguator extends React.Component {
    constructor(props) {
        super(props);

        /**
         * Pages ID:
         * 0 - Home
         * 1 - Members
         * 2 - Organizations
         */

        this.state = {
            subPageId: 0,
            isMobile: false
        }
    }

    changeSubPage = (id) => {
        if (id < 0 || id > 2)
            return;

        this.setState({
            subPageId: id
        });
    };

    getPage = () => {
        switch (this.state.subPageId) {
            case 0:
                return <Organisations changePage={ (id) => { this.props.changePage(id) } } changeSubPage={ (id) => { this.changeSubPage(id) } }/>;
            case 1:
                return <Home changePage={ (id) => { this.props.changePage(id) } } changeSubPage={ (id) => { this.changeSubPage(id) } }/>;
            case 2:
                return <Members changePage={ (id) => { this.props.changePage(id) } } changeSubPage={ (id) => { this.changeSubPage(id) } }/>;
            default:
                return <div />
        }
    };

    handleResize = () => {
        if (window.innerWidth <= 480 && !this.state.isMobile)
            this.setState({
                isMobile: true
            });
        else if (window.innerWidth > 480 && this.state.isMobile)
            this.setState({
                isMobile: false
            });
    };

    render() {
        window.addEventListener('resize', this.handleResize);
        return (
            <div>
                { this.state.isMobile &&
                    <Navbar
                        changePage={ (id) => { this.props.changePage(id) } }
                        changeSubPage={ (id) => { this.changeSubPage(id); } }
                /> }
                { this.getPage() }
            </div>
        );
    }

}

export default HomeNaviguator;