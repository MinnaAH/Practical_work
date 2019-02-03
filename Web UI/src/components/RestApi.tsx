import React from 'react';
import Paper from '@material-ui/core/Paper';

interface ICountriesState {
  data: any;
}


class RestApiDemo extends React.Component<{}, ICountriesState> {
  constructor(props) {
    super(props)
    this.state = {
      data: ['testitem'],
    }
  }
  public async componentDidMount() {
    console.log('inside componentDidMount');

    const fetchedData = await fetch('https://restcountries.eu/rest/v2/all');

    const data = await fetchedData.json();

    console.log('data is here: ', data);
    this.setState({ data });
  }
  public render() {
    return (
        <Paper>
          <h1>Component RestApi-Countires Remote</h1>
          {this.state.data.map((item, index) => <div key={index}>{item.name}</div>)}
        </Paper>
    )
  };
}

export default RestApiDemo;