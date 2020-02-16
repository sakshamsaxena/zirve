import React from "react";
class Ls {
  constructor() {
    this.arguments = []
  }
  validateArgs(a) {
    this.arguments = a;
    return a.length === 0;
  }
  getInput() {
    return "$ ls";
  }
  getOutput() {
    return (
      <div>
        <p>experience</p>
        <p>education</p>
        <p>bhakchodi</p>
      </div>
    );
  }
}

export default Ls;
