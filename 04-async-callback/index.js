const FibonacciCallback = require('bindings')('fibonacci_callback');

FibonacciCallback.Calculate(45, (err, data) => {
  if (err) {
    console.log(err);
  } else {
    console.log('Result:', data);
  }
});

console.log('Processing...');
