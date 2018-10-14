
exports.returnFibo = function (n) {
  var a = 1
  var b = 1
  var p = 0
  if (n === 0 || n === 1) {
    console.log(1)
  } else {
    for (var i = 2; i <= n; i++) {
      p = a + b
      a = b
      b = p
    }
    console.log(p)
  }
}
exports.printFibo = function (n) {
  var a = 1
  var b = 1
  var p = 0
  for (var i = 0; i <= n; i++) {
    if (i === 0 || i === 1) {
      console.log(1)
    } else {
      p = a + b
      a = b
      b = p
      console.log(p)
    }
  }
}
