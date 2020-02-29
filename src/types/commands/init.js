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
        <p>&nbsp;&nbsp;&nbsp;&nbsp;<b>Quick Links</b></p>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Resume&nbsp;: [Download]</p>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GitHub&nbsp;: [<a href="https://github.com/sakshamsaxena">sakshamsaxena</a>]</p>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Email&nbsp;&nbsp;: [saksham_saxena@outlook.com]</p>
        <br/>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;<b>Commands Available</b></p>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;whoami</p>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ls [-R] [DIRECTORY]</p>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tree [DIRECTORY]</p>
        <br/>
      </div>
    );
  }
}

export default Init;
