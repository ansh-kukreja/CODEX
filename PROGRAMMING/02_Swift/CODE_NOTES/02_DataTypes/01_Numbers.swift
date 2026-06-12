import Cocoa

// Swift Ignores underscores in a Number Value (All three are Same for Swift)
let c1 = 100_000_000
let c2 = 100000000
let c3 = 1__0__000_00___00
print(c1,c2,c3)


var num = 4
num += 2
num -= 2
num *= 2
num /= 2
print(num)

print(num.isMultiple(of: 2))
print(18.isMultiple(of: 9))


let d1 = 1
let d2 = 2.0

//let d3 = d1 + d2    //  <== This is Not Allowed (Can't Mix Up the Data Types in Swift)

let d4 = d1 + Int(d2)    // We Need to Parse the Variable into one single Data Type



let d5 = "SwiftUI"
//d5 = 49     //   <== We Can't Change the Data Type of an existing Variable