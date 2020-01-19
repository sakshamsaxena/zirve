import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';

class Terminal extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      buffers: []
    };
  }
  checkPrompt(e) {
    if (e.keyCode === 13 || e.charCode === 13) {
      let t = e.target.value;
      let buffer = {
        command: t,
        output: 'hello'
      }
      let u = this.state.buffers.length ? this.state.buffers.concat([buffer]) : [buffer];
      this.setState({ buffers: u });
      document.getElementsByClassName('core-prompt')[0].value = '';
      return false;
    }
    return true;
  }
  render() {
    return (
      <div className="core-terminal">
        <Buffer value={this.state.buffers}></Buffer>
        <Prompt onKeyPress={(e) => this.checkPrompt(e)}></Prompt>
      </div>
    );
  }
}

class Buffer extends React.Component {
  render() {
    let vals = this.props.value;
    let buffers = vals.map((p) => {
      return (
        <div className="single-buffer">
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
    return (
      <div className="buffer-output">
        {this.props.value}
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

class Prompt extends React.Component {
  render() {
    return (
      <input type="text" className="core-prompt" onKeyPress={(e) => this.props.onKeyPress(e)}></input>
    );
  }
}

// ========================================

ReactDOM.render(
  <Terminal />,
  document.getElementById('root')
);
