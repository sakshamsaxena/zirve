import React from "react";
class Whoami {
  constructor() {
    this.arguments = []
  }
  validateArgs(a) {
    this.arguments = a;
    return a.length === 0;
  }
  getInput() {
    return "whoami";
  }
  getOutput() {
    return (
      <div>
        <p>##############################</p>
        <p>#&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Saksham Saxena &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;#</p>
        <p>##############################</p>
      </div>
    );
  }
}

export default Whoami;