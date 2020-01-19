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
      let u = this.state.buffers.length ? this.state.buffers.concat(t) : t;
      this.setState({buffers: u});
      return false;
    }
    return true;
  }
  render() {
    return (
      <div className="core-terminal">
        <Buffer value={this.state.buffers}></Buffer>
        <Prompt onKeyPress={(e)=> this.checkPrompt(e)} ></Prompt>
      </div>
    );
  }
}

class Buffer extends React.Component {
  render() {
    return (
      <div className="core-buffer">
        {this.props.value}
      </div>
    );
  }
}

class Prompt extends React.Component {
  render() {
    return (
      <input type="text" className="core-prompt" onKeyPress={(e)=> this.props.onKeyPress(e)}></input>
    );
  }
}

// ========================================

ReactDOM.render(
  <Terminal />,
  document.getElementById('root')
);
