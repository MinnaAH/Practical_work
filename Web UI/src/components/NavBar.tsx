import Link from 'next/link';
import React from 'react';
import AppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import Button from '@material-ui/core/Button';

const Navbar: React.SFC<{}> = () => (
  <AppBar position="static" color="inherit">
    <Toolbar>
      <Link href="/"><Button color="primary">Home</Button></Link>
      <Link href="/clock"><Button color="inherit">Clock</Button></Link>
      <Link href="/datenow"><Button color="inherit">Date</Button></Link>
      <Link href="/restapi"><Button color="inherit">Rest Api</Button></Link>
      <Link href="/countries"><Button color="inherit">Countries</Button></Link>
    </Toolbar>
  </AppBar>
)

export default Navbar;