
// Object Literal
let person = {
    name: "Ansh",
    age: 22,
    chestSize: 40,
    bicepSize: 14.5,
    weight: 68,
    maxBenchPress: 100,

    carsOwned: ["Porsche", "BMW", "Audi"],

    say: function() {
        console.log("I'm CEO Bitch!");
    }
};

// Accessing Value from an Object
console.log(person["name"]);  // 1st way of accessing
console.log(person.name);     // 2nd Way of accessing


// ------------------------------------------------------------------------------------------


let usingKeywordsAsKeys = {
    1: "a",
    2: "b",
    null: "c",
    undefined: "d",
    true: "e",
    false: "f",

    // JS will convert all these keywords into Strings and won't treat them as keywords
};

usingKeywordsAsKeys[1]; // This will first convert 1 to a string "1" and then print "a"

// usingKeywordsAsKeys.1   -> this will not work


// ------------------------------------------------------------------------------------------


person.eyeColor = "Brown"; // Will create a new property in the Original Object

delete person.weight;  // will delete the property


// ------------------------------------------------------------------------------------------

// Object of Objects
let students = {
    ansh: {
        age: 22,
        section: "D",
    },
    shradha: {
        age: 22,
        section: "A",
    }, 
};


// Array of Objects
let studs = [
    {
        name: "Ansh",
        age: 22,
    },
    {
        name: "Shradha",
        age: 22,
    },
];


// ------------------------------------------------------------------------------------------


// 'Math' Object
console.log(Math.PI);          // Prints the value of PI
console.log(Math.sqrt(16));    // Prints the square root of 16
console.log(Math.pow(2, 3));   // Prints 2 raised to the power 3
console.log(Math.random());    // Prints a random number between 0 and 1 (exclusive of 1)


// ------------------------------------------------------------------------------------------

// Generating Random Number between two numbers, e.g. 1-9
let n = 9;
let randomNum = Math.floor(Math.random() * n) + 1;  // Gives Random nums between 1-9 (including 1 and 9)

// ------------------------------------------------------------------------------------------

// Functions in Objects

let random = {
    // First Way
    add: function(a,b){
        return a+b;
    },

    // Second Way
    sub(a,b){
        return a-b;
    }
}

// ------------------------------------------------------------------------------------------

// "This" Keyword

let student = {
    name: "Ansh",
    age: 22,
    eng: 90,
    ds: 98,
    web: 99,

    avgMarks(){
    //  let avg = (eng + ds + web) / 3;     // ❌ - This will throw error (Not Allowed)

        let avg = (this.eng + this.ds + this.web) / 3;     // ✅ - Use 'This' Keyword

        console.log(avg);
    }
}
student.avgMarks();

// ------------------------------------------------------------------------------------------

// Spread function '...'

let obj = {
    name: "Ansh",
    age: 22,
};

let newObj = {...obj,  id: 7081};

console.log(newObj);

// ------------------------------------------------------------------------------------------

// Destructuring of Objects

let student4 = {
    name: "Ansh",
    age: 22,
    phone: 8096500009,
    id: 7081,
    state: "Haryana"
};

let {name, age} = student4;  // Fetching Variables using same keys

let {phone: mobileNumber, id:userId} = student4;  // Fetching Values using keys and saving them in our variables

let {state: stateOfLiving, city: shehar = "Kurukshetra"} = student4;   // Giving Default Values is allowed

// ------------------------------------------------------------------------------------------



