class Cmd {
  Command = "noop";
  Arguments = [];
  constructor(c, a) {
    if (typeof c === "string" && this.isValidCommandString(c)) {
      this.Command = c;
    }
    if (Array.isArray(a) && this.isValidArgumentArray(a)) {
      this.Arguments = a;
    }
  }
  isValidCommandString(c) {
    return c.length;
  }
  isValidArgumentArray(a) {
    return a.length;
  }
}

export default Cmd;
