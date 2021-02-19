import React, { Component } from 'react';
import { Icon } from 'antd';
import '../App.css';
import './MyNotification.css';

export default class MyNotification extends Component {
	render() {
		return (
			<div className="MyNotification" >
				<a target="_blank" rel="noopener noreferrer" href="https://github.com/simonmeyerrr/epimanager" >
					<Icon type="github" />
				</a>
			</div>
		);
	}
}
