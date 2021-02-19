import React, { Component } from 'react';
import '../App.css';
import './MyInfo.css';

export default class MyInfo extends Component {
	render() {
		console.log(this.props.info)
		return (
			<div className="MyInfo" >
				<img
					src={this.props.info.photo}
					alt=""
					className="profil_image"
				/>
				<div className="profil_info">
					{this.props.info.name}
					<br />
					Credits: {this.props.info.credit}
					<br />
					GPA: {this.props.info.gpa}
				</div>
			</div>
		);
	}
}
