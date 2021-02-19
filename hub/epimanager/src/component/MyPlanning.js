import React, { Component } from 'react';
import { Row, Col } from 'antd';
import '../App.css';
import './MyPlanning.css';

const BackColorDark = ["#001529", "#001545"]
const BackColorLight = ["#ffffff", "#f2f2f2"]

function get_theme() {
	if (JSON.parse(localStorage.getItem('epimanager_settings')).theme_dark) {
		return "dark";
	} else {
		return "light"
	}
}

function get_style_theme(i) {
	if (get_theme() === "dark") {
		return (BackColorDark[i % 2]);
	} else {
		return (BackColorLight[i % 2]);
	}
}

export class Activity extends Component {
	constructor(props) {
		super(props);
		this.dispActivity = this.dispActivity.bind(this);
	}
	dispActivity() {
		return (
			JSON.parse(localStorage.getItem('epimanager_planning')).planning[this.props.i].map((value, i) =>
				<Row style={{
					backgroundColor: get_style_theme(i)
				}}>
					<Col span={14} style={{padding: 3}}> <a target="_blank" href={value.link}> {value.name} </a> </Col>
					<Col span={4} style={{padding: 2, textAlign: "center"}}> {value.start} <br/> {value.end} </Col>
					<Col span={6} style={{padding: 3, textAlign: "center"}}> {value.room} </Col>
				</Row>
			)
		);
	}
	render() {
		if (JSON.parse(localStorage.getItem('epimanager_planning')).planning[this.props.i].length <= 0) {
			return (
				<div></div>
			);
		} else {
			return (
				<div>
					<div className="day_title" >
						{JSON.parse(localStorage.getItem('epimanager_planning')).date[this.props.i]}
					</div>
					{this.dispActivity()}
				</div>
			);
		}
	}
}

export default class MyPlanning extends Component {
	getPlanning() {
    let planning = this.props.planning;
    let activity = 0
		for (let i = 0; i < planning.length; i++) {
    	for (let j = 0; j < planning[i].length; j++) {
    		activity++;
			}
		}
		if (activity > 0) {
      return (
        JSON.parse(localStorage.getItem('epimanager_planning')).date.map((value, i) =>
          <Activity i={i} />
        )
      );
		} else {
    	return <div> Pas d'activité cette semaine. </div>
		}
	}
	render() {
		return (
			<div className="MyPlanning" >
				{this.getPlanning()}
			</div>
			);
	}
}
