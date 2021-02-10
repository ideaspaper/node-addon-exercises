const hello_world = require('bindings')('hello_world');

console.log(hello_world.Hello(), hello_world.World());
