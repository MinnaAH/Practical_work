import React from 'react';
import Table from '@material-ui/core/Table';
import TableBody from '@material-ui/core/TableBody';
import TableCell from '@material-ui/core/TableCell';
import TableHead from '@material-ui/core/TableHead';
import TableRow from '@material-ui/core/TableRow';
import Paper from '@material-ui/core/Paper';

import Country from './Country';

import { countries } from '../maat';

interface ICountriesState {
}


class Countries extends React.Component<{}, ICountriesState> {
  public render() {
    return (
        <Paper>
          <h1>Component: Countries Local</h1>
          <Table>
            <TableHead>
              <TableRow>
                <TableCell>
                  Name
                </TableCell>
                <TableCell>
                  Population
                </TableCell>
                <TableCell>
                  Percentage
                </TableCell>
                <TableCell>
                  Position
                </TableCell>
              </TableRow>
            </TableHead>
            <TableBody>
              {countries.map(country => <Country prop1={country} />)}
            </TableBody>
          </Table>
        </Paper>
    )
  };
}

export default Countries;