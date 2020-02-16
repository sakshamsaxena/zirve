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
    return "$ whoami";
  }
  getOutput() {
    return (
      <div>
        <p>##############################</p>
        <p># Hi, I'm Saksham Saxena. &nbsp;&nbsp;&nbsp;#</p>
        <p># Something about me etc etc #</p>
        <p>##############################</p>
      </div>
    );
  }
}

export default Whoami;