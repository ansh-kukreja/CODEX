import Cocoa


let employee = [
    "name": "Ansh Kukreja",
    "company": "Apple"
]

print(employee["name"])
print(employee["keyThatDoesntExists"])    // Will Not Throw Error, returns nil


// Better Approach for this is to give a default value that will be returned if the key doesn't exists
print(employee["keyThatDoesntExists", default: "No Value bro!"])



// Some examples of Dictonaries

let agesOfPeople = [
    "ansh": 23,
    "cheema": 28,
    "mik": 26
]

let dateOfBirths = [
    2003: "Ansh Kukreja",
    2000: "Harkirat Sangha"
]

var marksInDS = [String: Int]()
marksInDS["Ansh"] = 84
marksInDS["Chemma Y"] = 7