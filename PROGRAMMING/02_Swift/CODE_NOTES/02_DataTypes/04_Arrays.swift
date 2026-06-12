import Cocoa


// Way 1
var singers = ["Sidhu", "Karan", "Harkirat", "SMG"]
singers.append("Shubh")

// Way 2
var ages = Array<Int>()
ages.append(23)

// Way 3
var scores = [Int]()
scores.append(100)


// Array Functions
var names = ["Paul", "Jack", "Steve", "Peter"]

let res1 = names.count                // Size of Array
let res2 = names.contains("Bannner")  // gives bool value
let res3 = names.remove(at: 1)
let res4 = names.removeAll()
let res5 = names.sorted()
let res6 = names.reversed()           // Returns a New Array