
// ForEach Method
let arr1 = [1,2,3,4,5,6,7];

let printNums = function(num){
    console.log("Printing " + num);
}

arr1.forEach(printNums);

arr1.forEach((n) => {
    // whatever..
});

// -----------------------------------------------------------------------------------------------

// Map Function (To Modify Array elements)

let arr2 = [1,2,3,4];

let square = arr2.map((n) => {
    return n*n;
});

console.log(`Square of Given Array : ${square}`);

// -----------------------------------------------------------------------------------------------

// Filter Function (To Filter out elements)

let arr3 = [1,2,3,4,5,6,7,8,9];

let evenNums = arr3.filter((n) => {
    return (n % 2 == 0);
});

console.log(`Even elements in given array : ${evenNums}`);

// -----------------------------------------------------------------------------------------------



