import React from "react";

class Buffer extends React.Component {
  render() {
    let vals = this.props.value;
    let buffers = vals.map(p => {
      return (
        <div key={p.id} className="single-buffer">
          <Output value={p}></Output>
        </div>
      );
    });
    return buffers;
  }
}

class Output extends React.Component {
  render() {
    let input = this.props.value.command;
    let output = "";
    let cls = this.props.value.output.Command;
    if (cls === null) {
      input = "$ " + input;
      output = "Bhakchodi mat pel bsdk";
    } else {
      input = cls.getInput();
      output = cls.getOutput();
    }
    return (
      <div className="buffer-output">
        <div className="buffer-line">{input}</div>
        <div className="buffer-line">{output}</div>
      </div>
    );
  }
}

export default Buffer;
