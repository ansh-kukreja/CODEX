import Cocoa

let stringWithQuotes = "Swift is \"Good\" and Easy"
print(stringWithQuotes)


let multiLineString = """
Hi!
From a Future
iOS Developer
"""
print(multiLineString)




var a = "Hi! I'm learning Swift!"

// String Functions

print(a.count)
print(a.uppercased())
print(a.hasPrefix("Hi"))
print(a.hasSuffix("Swift!"))



// String Concatenation

let f1 = "IPhone"
let f2 = "Cool"
let f3 = f1 + " is " + f2 
print(f3)




// Joining Integers and Strings

let g1 = 23
let g2 = "Ansh"

let g = "Hi! I am \(g2) and I'm \(g1) years old"    
print(g)