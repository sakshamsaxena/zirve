class Whoami {
  constructor() {
    this.arguments = []
  }
  validateArgs(a) {
    this.arguments = a;
    return a.length === 0;
  }
  getInput() {
    return "$ whoami";
  }
  getOutput() {
    return "Saksham Saxena";
  }
}

export default Whoami;