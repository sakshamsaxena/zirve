import React from "react";
class Anniversary {
  constructor() {
    this.arguments = []
  }
  validateArgs(a) {
    this.arguments = a;
    return a.length === 0;
  }
  getInput() {
    return "anniversary";
  }
  getOutput() {
    return (
      <div>
        <p>##############################</p>
        <p>#&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Anniversary &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;#</p>
        <p>##############################</p>
      </div>
    );
  }
}

export default Anniversary;