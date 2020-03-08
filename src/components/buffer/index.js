import React from "react";
import { v1 as uuidv1 } from 'uuid';

class Buffer extends React.Component {
  render() {
    let buffers = this.props.value.map(buffer => {
      let uniqueKey = uuidv1();
      let input = buffer.userInput;
      let output = "Sorry, didn't get that.";
      let command = buffer.outputCommand;

      if (command !== undefined && command !== null) {
        input = command.getInput();
        output = command.getOutput();
      }

      return (
        <div key={uniqueKey} className="single-buffer">
          <div className="buffer-output">
            <div className="buffer-line"><span className="dollar">$</span>{input}</div>
            <div className="buffer-line">{output}</div>
          </div>
        </div>
      );
    });
    return buffers;
  }
}

export default Buffer;
