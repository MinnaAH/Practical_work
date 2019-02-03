import React, { Component } from 'react' ;

export default class DateNow extends Component{
    render() {
        const date = new Date().getDate();
        const month = new Date().getMonth() + 1;
        const year = new Date().getFullYear();
        return(
            <p>Tänään on {date}.{month}.{year}</p>
        );
    };
}