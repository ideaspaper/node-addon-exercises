const Callback = require('bindings')('callback');

try {
  Callback.Callback(3, (data) => {
    console.log(data);
  });
} catch(err) {
  console.log('The error is:', err);
}

console.log('Process done!');
