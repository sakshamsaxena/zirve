import Whoami from "./commands/whoami";
import Tree from "./commands/tree";
import Ls from "./commands/ls";
import Init from "./commands/init";

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
      { cmdStr: "Tree", cmdCls: Tree },
      { cmdStr: "Ls", cmdCls: Ls },
      { cmdStr: "Init", cmdCls: Init }
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
