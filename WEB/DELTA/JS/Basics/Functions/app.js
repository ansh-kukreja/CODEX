
// Different ways to define a function in JavaScript

function fun1(a,b){
    console.log("F1");
}

let fun2 = function(a,b){
    console.log("F2");
}

let fun3 = (a, b) => {
    console.log("F3"); // Implicitly returns the value
}


// -----------------------------------------------------------------------------------------------

function sayInfo(name, age) {
    console.log(`My name is ${name} and my age is ${age}`);
}

sayInfo("Ansh"); // we can pass less arguments than defined, without any error

sayInfo("Ansh", 22, "Extra"); // we can pass more arguments than defined, without any error

// -----------------------------------------------------------------------------------------------

// Passing function as argument to another function

function greetMorning() {
    return "Good Morning ";
}

function greet(greetMorn, name) {
    console.log(greetMorn() + name);
}

greet(greetMorning, "Ansh");

// -----------------------------------------------------------------------------------------------

// Returning Function in a Function

function factoryFunc(type){
    if(type == 1){
        return function(){
            console.log("Dummy Function 1");
        }
    }
    else if(type == 2){
        return function(){
            console.log("Dummy Function 2");
        }
    }
}

// -----------------------------------------------------------------------------------------------

// "this" keyword in an Arrow Function refers to the Scope of its Parent

let me = {
    name: "Ansh",
    age: 22,

    normalFun: function(){
        console.log(this);  // Here 'this' object refers to the 'me' object and print its body
    },

    arrowFun: () => {
        console.log(this);  // Here 'this' object refers to the scope of its Parent object i.e. 'me'
                            // which is 'Window' object by default.
                            // So 'this' here refers to the 'Window' object
    }
}

// -----------------------------------------------------------------------------------------------

let student = {
    fun: function(){
        setTimeout(() => {
            console.log(this);  // 'this' here refers to the 'student' object, i.e. scope of its parent
        }, 2000);
    },

    fun2: function(){
        setTimeout(function(){
            console.log(this);  // 'this' here refers to the 'Window' Object, because 'setTimeout' 
        }, 2000);               // function is of global scope, and global scope object is 'Window'
    }
}

// -----------------------------------------------------------------------------------------------
