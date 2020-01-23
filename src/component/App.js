import React from "react";
import {hot} from "react-hot-loader";
import InputSanitizer from "../logic/sanitizer";
import Buffer from "./buffer";
import './App.css';

class App extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      buffers: []
    };
  }
  checkPrompt(e) {
    if (e.keyCode === 13 || e.charCode === 13) {
      let t = e.target.value;
      let p = InputSanitizer(t);
      let buffer = {
        command: t,
        output: p,
        id: Date.now() + t
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

class Prompt extends React.Component {
  render() {
    return (
      <input type="text" className="core-prompt" onKeyPress={(e) => this.props.onKeyPress(e)}></input>
    );
  }
}

export default hot(module)(App);
