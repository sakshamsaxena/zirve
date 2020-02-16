class Tree {
  constructor() {
    this.arguments = []
  }
  validateArgs(a) {
    this.arguments = a;
    return a.length === 0;
  }
  getInput() {
    return "$ tree";
  }
  getOutput() {
    return "tree view";
  }
}

export default Tree;
