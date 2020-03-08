import React from "react";
import Directory from "../../directory/index.js";

class Tree {
  constructor() {
    this.arguments = [];
    this.tree = [];
  }
  validateArgs(a) {
    if (a.length === 0) {
      this.tree = Directory;
      return true
    }
    return false;
  }
  getInput() {
    return "tree";
  }
  generateJsx(nodeList, level, lastNode) {
    if (nodeList.length === 0) {
      return [];
    }
    let outputJsx = [];
    for (let j = 0; j < nodeList.length; j++) {
      let node = nodeList[j];
      let predash = [];
      for (let x = 0; x < level - 1; x++) {
        if (x + 1 === level - 1 && lastNode) {
          predash.push(<span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span>);
        } else {
          predash.push(<span>│&nbsp;&nbsp;&nbsp;&nbsp;</span>);
        }
      }
      let dash = "├──";
      let isThisLastNode = false;
      if (j + 1 === nodeList.length) {
        dash = "└──";
        isThisLastNode = true;
      }
      outputJsx.push(
        <p>
          {predash}
          {dash}
          {node.Name}
        </p>
      );
      outputJsx = outputJsx.concat(
        this.generateJsx(node.Children, level + 1, isThisLastNode)
      );
    }
    return outputJsx;
  }
  getOutput() {
    let output = this.generateJsx(this.tree, 1, false);
    return <div>{output}</div>;
  }
}

export default Tree;
