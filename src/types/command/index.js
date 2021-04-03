import Whoami from "./commands/whoami";
import Tree from "./commands/tree";
import Init from "./commands/init";
import Anniversary from "./commands/anniversary";

const validCmds = [
  {
    cmdStr: "Anniversary",
    cmdCls: Anniversary
  },
  {
    cmdStr: "Whoami",
    cmdCls: Whoami
  },
  {
    cmdStr: "Tree",
    cmdCls: Tree
  },
  {
    cmdStr: "Init",
    cmdCls: Init
  }
];

class Command {
  /**
   * Command
   * The only public property that the class exports.
   * Carries reference to a specific command class.
   */
  Command = null;

  constructor(commandString, argumentsArray) {
    if (!this.isValidCommandString(commandString) ||
        !this.isValidArgumentsArray(argumentsArray)) {
      this.Command = null
      return;
    }
  }

  /**
   * 
   * @param {string} commandString 
   */
  isValidCommandString(commandString) {
    if (typeof commandString !== "string") {
      return false;
    }
    for (let index = 0; index < validCmds.length; index++) {
      if (validCmds[index].cmdStr.toLowerCase() === commandString.toLowerCase()) {
        this.Command = new validCmds[index].cmdCls();
        return true;
      }
    }
    return false;
  }

  /**
   * 
   */
  isValidArgumentsArray(argumentsArray) {
    if (this.Command === null) {
      return false;
    }
    return this.Command.validateArgs(argumentsArray);
  }
}

export default Command;
