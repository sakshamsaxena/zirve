class Whoami {
  constructor() {
    this.arguments = []
  }
  validateArgs(a) {
    this.arguments = a;
    return a.length === 0;
  }
  getOutput() {
    return "Saksham Saxena";
  }
}

export default Whoami;