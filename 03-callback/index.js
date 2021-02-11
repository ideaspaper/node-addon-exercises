const callback = require('bindings')('callback');

try {
  callback.Callback(3, (data) => {
    console.log(data);
  });
} catch(err) {
  console.log('The error is:', err);
}

console.log('Process done!');
