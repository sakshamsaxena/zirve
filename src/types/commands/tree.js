import React from "react";
class Tree {
  constructor() {
    this.arguments = []
  }
  validateArgs(a) {
    this.arguments = a;
    return a.length === 0;
  }
  getInput() {
    return "$ tree";
  }
  getOutput() {
    return (
      <div>
        <p>├──Work Experience</p>
        <p>├──Education</p>
        <p>├──Social</p>
      </div>
    );
  }
}

export default Tree;
