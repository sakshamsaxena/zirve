import React from "react";
class Ls {
  constructor() {
    this.arguments = []
    this.mode = "plain"
    this.directories = ["experience", "education", "achievements"]
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
    let base = "ls";
    if (this.arguments.length) {
      for (var i = 0; i < this.arguments.length; i++) {
        base += " " + this.arguments[i]
      }
    }
    return base;
  }
  getOutput() {
    let dirMap = {
      "experience":["SoftDev at Zomato from X to Y", "Ass Soft Dev at BCS from A to B"],
      "education": ["B.Tech in Engineering Physics from DTU, 2017"]
    }
    if (this.arguments.length === 0) {
      return (
        <div>
          <p>Experience</p>
          <p>Education</p>
          <p>Achievements</p>
        </div>
      );
    }
    if (this.arguments.length === 1) {
      if (this.mode === "plain") {
        // ls dir
        let contents = dirMap[this.arguments[0].toLowerCase()]
        var output = []
        for (var i = 0; i < contents.length; i++) {
          console.log(contents[i])
          output.push(<p>{contents[i]}</p>)
        }
        return (
          <div>
            {output}
          </div>
        )
      }
    }
  }
}

export default Ls;
