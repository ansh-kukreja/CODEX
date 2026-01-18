
// "ForEach" Method
let arr1 = [1,2,3,4,5,6,7];

let printNums = function(num){
    console.log("Printing " + num);
}

arr1.forEach(printNums);

arr1.forEach((n) => {
    // whatever..
});

// -----------------------------------------------------------------------------------------------

// "Map" Function (To Modify Array elements)

let arr2 = [1,2,3,4];

let square = arr2.map((n) => {
    return n*n;
});

console.log(`Square of Given Array : ${square}`);

// -----------------------------------------------------------------------------------------------

// "Filter" Function (To Filter out elements)

let arr3 = [1,2,3,4,5,6,7,8,9];

let evenNums = arr3.filter((n) => {
    return (n % 2 == 0);
});

console.log(`Even elements in given array : ${evenNums}`);

// -----------------------------------------------------------------------------------------------

// "Every" Method
// If all the elements satisfies the condition then return "true",
// and even if 1 element doesn't satisfies the given cond. then it return "false"
// Works like logical AND

let arr4 = [1,2,3,4,5,6,7,8,9];

let res4 = arr4.every((n) => {
    return (n % 2 == 0);
});


// "Some" Method
// Even if atleast one element satisfies the given condition then it return "true" else "false"
// Works like logical OR

let res5 = arr4.some((n) => {
    return (n % 2 == 0);
});

// -----------------------------------------------------------------------------------------------

// "Reduce" Method
// Reduces the array into single value

let arr5 = [2,9,4];

let sum = arr5.reduce((res, n) => {
    return res + n;
});

console.log(`Array has been Reduced to: ${sum}`);

// -----------------------------------------------------------------------------------------------

// "Spread" function '...'

let str6 = "anshkukreja";

console.log(...str6);  // a n s h k u k r e j a

// -----------------------------------------------------------------------------------------------
