import React from "react";
class Ls {
  constructor() {
    this.arguments = []
    this.mode = "plain"
    this.directories = ["Experience", "Education", "Achievements"]
  }
  validateArgs(a) {
    this.arguments = a;
    if (a.length === 0) {
      return true;
    }
    if (a[0] !== "-R") {
      this.mode = "plain"
    } else {
      this.mode = "recur"
    }
    let dir = ""
    if (this.mode === "recur") {
      if (a[1] === undefined || a[1] === null) {
        return true;
      }
      dir = a[1]
    } else {
      dir = a[0];
    }
    if (this.mode == "plain" && (dir === undefined || dir == null)) {
      return false;
    }
    // Validate Directory
    for (var i = 0; i < this.directories.length; i++) {
      if (this.directories[i].toLowerCase() === dir.toLowerCase()) {
        return true;
      }
    }
    return false;
  }
  getInput() {
    let base = "$ ls";
    if (this.arguments.length) {
      for (var i = 0; i < this.arguments.length; i++) {
        base += " " + this.arguments[i]
      }
    }
    return base;
  }
  getOutput() {
    return (
      <div>
        <p>Experience</p>
        <p>Education</p>
        <p>Achievements</p>
      </div>
    );
  }
}

export default Ls;
