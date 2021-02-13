const fibonacci_callback = require('./build/Release/obj.target/fibonacci_callback');

fibonacci_callback.Calculate(45, (err, data) => {
  if (err) {
    console.log(err);
  } else {
    console.log('Result:', data);
  }
});

console.log('Processing...');
