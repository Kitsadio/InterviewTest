import logo from './logo.svg';
import './App.css';

import WebSocket from 'ws';

function App() {
    function colour(MachineState) {
        if(MachineState == "IDLE")
        {
            return 'GREEN';
        }
        else if (MachineState == "PRODUCING")
        {
            return 'ORANGE';
        }
        else if (MachineState == "STARVED")
        {
            return 'RED' ;
        }
        else{
           //log('UNKNOWN MACHINE STATE');
        }
    }

    //THIS IS WHERE IT WOULD RECEIVE.. BUT UNABLE TO CONNECT WS
    var s = "PRODUCING MACHINE";
    const Array = s.split(" ");
    var Machine = [];
    var Machine1 = [];
    var Machine2 = [];

    if(Array[1] == "MACHINE")
    {
        Machine = [Array[0], Array[1]];
        localStorage['MACHINE'] = JSON.stringify(Machine);
    }
    else if(Array[1] == "MACHINE1")
    {
        Machine1 = [Array[0], Array[1]];
        localStorage['MACHINE1'] = JSON.stringify(Machine1);
    }
    else
    {
        Machine2 = [Array[0], Array[1]];
        localStorage['MACHINE2'] = JSON.stringify(Machine2);
    }

    var stored = localStorage['MACHINE'];
    if (stored) Machine = JSON.parse(stored);

    stored = localStorage['MACHINE1'];
    if (stored) Machine1 = JSON.parse(stored);

    stored = localStorage['MACHINE2'];
    if (stored) Machine2 = JSON.parse(stored);

    return (
    <div className="App">
      <header className="App-header">
          <h1>{Machine[1]} {colour(Machine[0])}</h1>
          <h1>{Machine1[1]} {colour(Machine1[0])}</h1>
          <h1>{Machine2[1]} {colour(Machine2[0])}</h1>
      </header>
    </div>
  );
}

export default App;
