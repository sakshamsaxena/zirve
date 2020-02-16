import React from "react";
class Init {
  constructor() {
    this.arguments = [];
  }
  validateArgs(a) {
    this.arguments = a;
    return a.length === 0;
  }
  getInput() {
    return "";
  }
  getOutput() {
    return (
      <div>
        <p>Hey, Saksham here. Glad to see you logged in!</p>
        <p>This is my personal website in a (nut)shell.</p>
        <p>Hope you enjoy your session.</p>
        <br/>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;Quick Links:</p>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Resume : </p>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GitHub : </p>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Email : </p>
      </div>
    );
  }
}

export default Init;
