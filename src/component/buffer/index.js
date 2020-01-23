import React from "react";

class Buffer extends React.Component {
  render() {
    let vals = this.props.value;
    let buffers = vals.map(p => {
      return (
        <div key={p.id} className="single-buffer">
          <Command value={p.command}></Command>
          <Output value={p.output}></Output>
        </div>
      );
    });
    return buffers;
  }
}

class Output extends React.Component {
  render() {
    let output = "";
    let cls = this.props.value.Command;
    if (cls === null) {
      output = "Bhakchodi mat pel bsdk";
    } else {
      output = cls.getOutput();
    }
    return (
      <div className="buffer-output">
        {output}
      </div>
    );
  }
}

class Command extends React.Component {
  render() {
    return (
      <div className="buffer-command">
        {this.props.value}
      </div>
    );
  }
}

export default Buffer;
