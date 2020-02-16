class Ls {
  constructor() {
    this.arguments = []
  }
  validateArgs(a) {
    this.arguments = a;
    return a.length === 0;
  }
  getInput() {
    return "$ ls";
  }
  getOutput() {
    return "listing of stuff";
  }
}

export default Ls;
