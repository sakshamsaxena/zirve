import Whoami from "./commands/whoami";
import Which from "./commands/which";
import Tree from "./commands/tree";
import Wget from "./commands/wget";

class Cmd {
  Command = null;
  constructor(c, a) {
    let cmd = this.isValidCommandString(c);
    if (!cmd) {
      return
    }
    this.Command = cmd
    let args = this.isValidArgumentArray(a);
    if (!args) {
      this.Command = null;
    }
  }
  isValidCommandString(c) {
    if (typeof c !== "string") {
      return false;
    }
    const validCmds = [
      { cmdStr: "Whoami", cmdCls: Whoami },
      { cmdStr: "Which", cmdCls: Which },
      { cmdStr: "Tree", cmdCls: Tree },
      { cmdStr: "Wget", cmdCls: Wget }
    ];
    for (let index = 0; index < validCmds.length; index++) {
      if (validCmds[index].cmdStr.toLowerCase() === c.toLowerCase()) {
        return new validCmds[index].cmdCls();
      }
    }
    return false;
  }
  isValidArgumentArray(a) {
    if (this.Command === null) {
      return false;
    }
    return this.Command.validateArgs(a);
  }
}

export default Cmd;
