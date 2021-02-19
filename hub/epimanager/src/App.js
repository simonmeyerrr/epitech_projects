import React, { Component } from 'react';
import MyInfo from './component/MyInfo';
import MyPlanning from './component/MyPlanning';
import MyNotification from './component/MyNotification';
import MySettings from './component/MySettings';
import './App.css';
import { Menu, Icon } from 'antd';

function get_theme() {
	if (JSON.parse(localStorage.getItem('epimanager_settings')).theme_dark) {
		return "dark";
	} else {
		return "light"
	}
}

function get_style_theme() {
	if (get_theme() === "dark") {
		return ({
			width: 300,
			height: "100%",
			backgroundColor: "#001529",
			color: "#ffffff"
		});
	} else {
		return ({
			width: 300,
			height: "100%",
			backgroundColor: "white",
			color: "#000d1a"
		});
	}
}

export class MyNavbar extends Component {
	constructor(props) {
		super(props);
		this.state = {
			current: this.props.menu
		}
		this.handleClick = this.handleClick.bind(this);
	}
	handleClick = (e) => {
		this.setState({current: e.key});
		this.props.update(e.key);
	}
	render() {
		return (
			<Menu
				onClick={this.handleClick}
				selectedKeys={[this.state.current]}
				mode="horizontal"
				theme={get_theme()}
				style={{
					width: "100%",
					fontSize: 45
				}}
			>
				<Menu.Item
					key="my_info"
					style={{
						width: "25%",
						height: 75,
						paddingTop: 15
					}}
				>
					<Icon style={{fontSize: 30}} type="user"/>
				</Menu.Item>
				<Menu.Item
					key="planning"
					style={{
						width: "25%",
						height: 75,
						paddingTop: 15
					}}
				>
					<Icon style={{fontSize: 30}} type="calendar"/>
				</Menu.Item>
				<Menu.Item
					key="notif"
					style={{
						width: "25%",
						height: 75,
						paddingTop: 15
					}}
				>
					<Icon style={{fontSize: 30}} type="ellipsis"/>
	  			</Menu.Item>
				<Menu.Item
					key="settings"
					style={{
						width: "25%",
						height: 75,
						paddingTop: 15
					}}
				>
					<Icon style={{fontSize: 30}} type="setting"/>
	  			</Menu.Item>
			</Menu>
		);
	}
}

export default class App extends Component {
	constructor() {
		super();
		this.state = {
			menu: "my_info",
			settings : JSON.parse(localStorage.getItem('epimanager_settings')),
			info: JSON.parse(localStorage.getItem('epimanager_info')),
			planning: JSON.parse(localStorage.getItem('epimanager_planning'))
		};
		this.displayMenu = this.displayMenu.bind(this);
		this.changeMenu = this.changeMenu.bind(this);
    this.updateData = this.updateData.bind(this);
	}
	updateData() {
		console.log("Datas updated");
    this.setState({
      settings : JSON.parse(localStorage.getItem('epimanager_settings')),
      info: JSON.parse(localStorage.getItem('epimanager_info')),
      planning: JSON.parse(localStorage.getItem('epimanager_planning'))
    });
	}
	displayMenu() {
		switch (this.state.menu) {
			case "my_info":
				return <MyInfo info={this.state.info}/>
			case "planning":
				return <MyPlanning planning={this.state.planning}/>
			case "notif":
				return <MyNotification/>
			case "settings":
				return <MySettings settings={this.state.settings} updateData={this.updateData}/>
			default:
				return <div> ERROR </div>
		}
	}
	changeMenu(menu) {
		this.setState({
			menu: menu
		});
		this.updateData();
	}
	render() {
		return (
			<div style={get_style_theme()}>
				<MyNavbar menu={this.state.menu} update={this.changeMenu} />
				{this.displayMenu()}
			</div>
		);
	}
}
