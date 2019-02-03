import * as React from 'react';

class Clock extends React.Component<any, any>{
    constructor(props: any){
        super(props);
        const d = new Date();
        this.state={
            time: d.toLocaleTimeString()
        }
        this.tick = this.tick.bind(this)
    }
    public tick(){
        const d = new Date()
        this.setState({
            time: d.toLocaleTimeString()
        })
    }
    public componentDidMount(){
        setInterval(this.tick, 1000);
    }
    public render(){
        return(
            <div>
                <p>{this.state.time}</p>
            </div>
        );
    }
}

export default Clock;