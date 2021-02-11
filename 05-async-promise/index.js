const fibonacci_promise = require('bindings')('fibonacci_promise');

fibonacci_promise.Calculate(45)
  .then((data) => {
    console.log('Result:', data);
  })
  .catch((err) => {
    console.log(err);
  });

console.log('Processing...');
