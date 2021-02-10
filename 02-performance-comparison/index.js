const performance_comparison = require('bindings')('performance_comparison');

function fibonacciRecursive(n) {
  if (n < 2) return n;
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

const task = 46;

const hstart1 = process.hrtime();
fibonacciRecursive(task);
const hrend1 = process.hrtime(hstart1);
console.log('Regular Fibonacci execution time (hr): %ds %dms', hrend1[0], hrend1[1] / 1000000);

const hstart2 = process.hrtime();
performance_comparison.FibonacciRecursive(task);
const hrend2 = process.hrtime(hstart2);
console.log('Addon Fibonacci execution time (hr): %ds %dms', hrend2[0], hrend2[1] / 1000000);
