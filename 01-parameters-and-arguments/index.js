const parameters_and_arguments = require('bindings')('parameters_and_arguments');

console.log(parameters_and_arguments)

console.log(parameters_and_arguments.Add(5, 10));
console.log(parameters_and_arguments.Sub(5, 10));
console.log(parameters_and_arguments.Mul(5, 10));
console.log(parameters_and_arguments.Div(5, 10));
