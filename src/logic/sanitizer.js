import Cmd from "../types/cmd";
/**
 * Input Sanitizer checks if the input command is valid or not.
 * @param {string} stdin The input as received from user via Prompt.
 * @return {string} Respective Command Class
 */
export default function InputSanitizer(stdin) {
  // Split the input by spaces to generate "argv"
  stdin = stdin.trim();
  stdin = stdin.split(" ");
  let cmds = [];
  for (let index = 0; index < stdin.length; index++) {
    // Validate each argument
    let inputRegExp = new RegExp(/([a-zA-Z-]{1,})/, "g");
    let matches = inputRegExp.exec(stdin[index]);

    if (matches === null || matches.length === 0) {
      // Input should not have any undesired chars
      return new Cmd();
    }

    if (matches.length === 2 && matches[0] === matches[1]) {
      // Valid stdin
      cmds.push(matches[0]);
    }
  }

  // Build Complete Command
  switch (cmds.length) {
    case 0:
      // Noop
      return new Cmd();
    case 1:
      // Command without argument
      return new Cmd(cmds[0], []);
    default:
      // Command with arguments
      return new Cmd(cmds[0], cmds.slice(1));
  }
}
