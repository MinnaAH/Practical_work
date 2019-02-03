import TableRow from '@material-ui/core/TableRow';
import TableCell from '@material-ui/core/TableCell';

interface ICountryProp {
  prop1?: object;
}

const Country: React.SFC<ICountryProp> = ({ prop1 = {} }) => {
  return (
      <TableRow>
        {console.log('DEBUG: ', prop1)}
            <TableCell>
              {prop1.name}
            </TableCell>
            <TableCell>
              {prop1.population}
            </TableCell>
            <TableCell>
              {prop1.percentage}
            </TableCell>
            <TableCell>
              {prop1.position}
            </TableCell>
        </TableRow>
  )
}

export default Country;