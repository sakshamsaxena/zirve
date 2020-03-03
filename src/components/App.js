import React from "react";
import { hot } from "react-hot-loader";
import InputSanitizer from "../logic/sanitizer";
import Buffer from "./buffer";
import Prompt from "./prompt";
import Command from "../types/command";
import "./App.css";

class App extends React.Component {
  Buffers = [];
  constructor(props) {
    super(props);
    this.state = {
      buffers: [
        {
          userInput: "init",
          outputCommand: new Command("init", []).Command
        }
      ]
    };
  }

  /**
   * executeCommand
   * Sanitizes input text and checks if it is a valid command.
   * If so, then executes it, otherwise returns standard error message.
   */
  executeCommand(stdin) {
    let newBuffer = {
      userInput: stdin,
      outputCommand: InputSanitizer(stdin).Command
    };
    this.setState({ buffers: this.state.buffers.concat(newBuffer) });
  }

  /**
   * checkPromptForCommand
   * Listens to user input on each key press, and sends through
   * the input text when Enter/Return key is pressed.
   */
  checkPromptForCommand(e) {
    if (e.keyCode === 13 || e.charCode === 13) {
      this.executeCommand(e.target.value);
      document.getElementsByClassName(e.target.className)[0].value = "";
      return false;
    }
    return true;
  }
  render() {
    return (
      <div className="core-terminal">
        <Buffer value={this.state.buffers}></Buffer>
        <Prompt onKeyPress={e => this.checkPromptForCommand(e)}></Prompt>
      </div>
    );
  }
}

export default hot(module)(App);
