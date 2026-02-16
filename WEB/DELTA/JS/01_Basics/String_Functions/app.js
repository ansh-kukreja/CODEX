

// ==== Removes Spaces ====
let str = "    He ll o A nsh Ku k r e ja      ";
let trimmedStr = str.trim();   // Output -> "AnshKukreja"


// ==== Upper/Lowercase ====
let str1 = "ansh";
str1.toUpperCase();
str1.toLowerCase();


// ==== IndexOf() ====
let str2 = "anshkukreja";
let index2 = str2.indexOf("ku");


// ==== Method Chaining ====
let str3 = "ansh";
let output3 = str.trim().toUpperCase();



// ==== Slice Method ====
let str4 = "AnshKukreja.com";

let output4 = str4.slice(4);  // "Kukreja.com"
// Will print substring from index 4 to end of string

output4 = str4.slice(12, 14); // "co"  
// Will print substring from range 12-13, 
// Exclusive of ending index i.e 14

output4 = str4.slice(-4);  // ".com"
// Means print string from (str.length - 4) to end of string
// 15-4 = 11,  prints 11-14



// ==== Replace Method ====
let str5 = "Ansh Kukreja";
let output5 = str5.replace("Ansh", "Arnav");  // "Arnav Kukreja"
// Replaces first occurrences only


// ==== Repeat Method ====
let str6 = "Mango ";
let output6 = str6.repeat(7);
console.log(output6);






