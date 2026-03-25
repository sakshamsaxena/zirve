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
    return "init";
  }
  getOutput() {
    return (
      <div>
        <p>Hey, Saksham here. Glad to see you logged in!</p>
        <p>This is my personal website in a (nut)shell.</p>
        <br/>
        <p>Currently building <b>Nexus AI</b> — partnering with early-stage startups</p>
        <p>to accelerate growth through cloud modernisation, DevOps maturity,</p>
        <p>and Generative AI adoption.</p>
        <br/>
        <p>10+ years connecting the dots between technology, business strategy,</p>
        <p>and operations. I solve the problems that lie between departments.</p>
        <br/>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;<b>Get in touch</b></p>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Email&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: [saksham@nexusai.world]</p>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;LinkedIn&nbsp;: [<a href="https://www.linkedin.com/in/sakshamsaxenanexusai/">sakshamsaxenanexusai</a>]</p>
        <br/>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;<b>Commands Available</b></p>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;whoami</p>
        <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tree</p>
        <br/>
      </div>
    );
  }
}

export default Init;
