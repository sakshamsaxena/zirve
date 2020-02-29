import React from "react";
class Tree {
  constructor() {
    this.arguments = []
    this.directories = ["Experience", "Education", "Achievements"]
  }
  validateArgs(a) {
    this.arguments = a;
    if (a.length > 1) {
      return false;
    }
    if (a[0] !== undefined && a[0] !== null) {
      // Validate Directory
      for (var i = 0; i < this.directories.length; i++) {
        if (this.directories[i].toLowerCase() === a[1].toLowerCase()) {
          return true;
        }
      }
    }
    return false;
  }
  getInput() {
    return "$ tree";
  }
  getOutput() {
    return (
      <div>
        <p>├──Experience</p>
        <p>├──Education</p>
        <p>└──Achievements</p>
      </div>
    );
  }
}

export default Tree;
