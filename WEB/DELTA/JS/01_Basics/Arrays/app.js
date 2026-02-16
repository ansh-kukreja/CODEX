
let names = ["Ansh", "Shradha", "Shubh", "Sidhu"];
names.length;

let arr1 = [];


arr1 = ["Ansh", 49, true, 98.49];
let output1 = arr1[0][0];  // "A"
// Means 0th element of 'arr1' and '0th' element of "Ansh" i.e. "A"



// ==== ARRAY FUNCTIONS ====
let arr2 = ["Maruti", "Ford", "Honda", "Toyota"];

arr2.push("RollsRoyce");
// Add the new element in the end of the array

arr2.pop();
// Deletes element from end of the Array and returns that value

arr2.unshift("Porsche");
// Add the element to the start of the Array

arr2.shift();
// Deletes element from the start of the Array and returns the value

arr2.indexOf("Honda"); // Output -> 2
arr2.indexOf("Bentley"); // Output(Not Present) -> -1


arr2.includes("Ford"); // true
arr2.includes("Bentley"); // false


let arr3 = ["Volkswagen", "MG", "Hyundai", "Pagani"];
let concatArray = arr2.concat(arr3);  // merges two arrays


arr3.reverse();
// ** Reverses the Original Array **



// ====== SLICE METHOD ======
// Doesn't change the Original Array

let arr4 = ["Red", "Blue", "Green", "Yellow", "Pink", "Black"];
arr4.slice();       // Output -> ["Red", "Blue", "Green", "Yellow", "Pink", "Black"]
arr4.slice(2);      // Output -> ["Green", "Yellow", "Pink", "Black"]
arr4.slice(2,4);    // Output -> ["Green", "Yellow"]     ## (Ending Index is Excluded) ##
arr4.slice(40);     // Output -> []
arr4.slice(-2);     // Output -> ["Pink", "Black"]       ## (means Last ke 2 elements dedo) ##



// ====== SPLICE METHOD ======
// Modifies the Original Array
// When given single value like ".splice(4)" it will work similar as Slice

let arr5 = ["Red", "Blue", "Green", "Yellow", "Pink", "Black"];

arr5.splice(4);  // Returns -> ["Pink", "Black"] 
// Now Orginal Array is ["Red", "Blue", "Green", "Yellow"]

arr5.splice(0,1); // Means Start with 0 index and Delete 1 element
// it will Return "Red"
// Now Orginal Array is ["Blue", "Green", "Yellow"]

arr5.splice(0,1,"Green","Yellow"); // Means start with 0, delete 1 element and insert given elements
// in the index starting with 0 index



let arr6 = ["Pagani", "Bentley", "RollsRoyce", "Ferrari", "Porsche"];
arr6.sort(); // Will Sort Strings in Ascending Order

let arr7 = [40, 29, 90, 49, 94, 99, 104, 100];
arr7.sort();
// ******  Will Not Sort the Numbers as Expected  ******
// Becuse JS will convert the numbers into strings and then sort it
// .sort() function is used to sort "chars" and "strings" generally



// ==== Pass by Reference in Array ====
let arr8 = ["one", "two", "three", "four"];
let temp8 = arr8; // Any change done in "temp8" will reflect on both the arrays
// in this way reference of the array is passed


// ==== Constant Array ====
const arr9 = ["Pagani", "Bentley", "RollsRoyce", "Ferrari", "Porsche"];
arr9.push("Lamborghini");  // Valid Operation
arr9.pop();   // Valid Operation
arr9 = arr8;  // Invalid Operation, Not Allowed (throws error)















