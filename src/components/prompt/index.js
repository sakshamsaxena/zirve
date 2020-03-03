import React from "react";

class Prompt extends React.Component {
  render() {
    return (
      <span>
        <span className="dollar">$</span>
        <input
          type="text"
          className="core-prompt"
          onKeyPress={e => this.props.onKeyPress(e)}
        ></input>
      </span>
    );
  }
}

export default Prompt;
