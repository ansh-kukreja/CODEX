
// ==== SetTimeout() function ====

console.log("Before");

setTimeout(() => {
    console.log("SetTimeout Function");
}, 4000);

console.log("After");


// ==== SetInterval function ====
// Calls the function repeatedly after given interval until it is stopped explicitly

let id = setInterval(() => {
    console.log("Yo");
}, 2000);

clearInterval(id);  // to stop this Interval explicitly