const object = require('./build/Release/obj.target/object');

const user = new object.User('Acong', 16, 'Student');

console.log(user);           // User {}
console.log(user.GetName()); // Acong
console.log(user.GetAge());  // 16
console.log(user.GetJob());  // Student
user.SetJob('Accountant');   // Set the Job to Accountant
console.log(user.Greet());   // Greeting! My name is Acong, my Age is 16, and my job is Accountant
