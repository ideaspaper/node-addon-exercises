const FibonacciAsync = require('bindings')('fibonacci_async');

FibonacciAsync.Calculate(40, (err, data) => {
  if (err) {
    console.log(err);
  } else {
    console.log('Result:', data);
  }
});

console.log('Processing...');
