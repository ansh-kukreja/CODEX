// Prototypes are the Mechanism by which JavaScipt object inherits features from one another.

// It is like a single template object from where all objects inherit methods and properties,
// without having their own copy

let arr = [1,2,3,4];


// To use Reference of the Prototype
arr.__proto__


// To use Actual Object
Array.prototype
String.prototype


// -----------------------------------------------------------------------------------------

arr.sayHello(() => {
    console.log("Hi! I am arr");
});

// This "sayHello" exists only for "arr" object, not for all other Array objects

// -----------------------------------------------------------------------------------------

arr.__proto__.push = (n) => {
    console.log("Pushing Number");
}

// Accessing the Prototype reference of "arr" and overriding the body of "push" function 

// -----------------------------------------------------------------------------------------


