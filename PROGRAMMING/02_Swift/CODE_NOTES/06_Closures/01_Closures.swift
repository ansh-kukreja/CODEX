import Cocoa


// Storing a Function in a variable

func greetUser() {
    print("Hello User")
}

let greetCopy = greetUser
greetCopy()




// Creating a Closure

let greetUser2 = {
    print("Hi there..")
}

greetUser2()




// Creating a Closure with Parameters

let greetUser3 = { (name: String) -> String in
    "Hi \(name)"
}
print(greetUser3("John Snow"))




// Data Type of Variables storing Functions

var greetCopy2: () -> Void = greetUser




// Custom Sorting an Array

let team = ["Gloria", "Suzanne", "Piper", "Tiffany", "Tasha"]

let sortedTeam = team.sorted()
print(sortedTeam)



// But if we want "Suzanne" to be at first index, no matter what.. then

func captainFirstSorted(name1: String, name2: String) -> Bool {
    if name1 == "Suzanne" {
        return true
    }
        
    if name2 == "Suzanne" {
        return false
    }
    
    return name1 < name2
}

let customSortedTeam = team.sorted(by: captainFirstSorted)
print(customSortedTeam)




// Now instead of passing a Normal function in "sorted()", we're gonna pass a Closure

let customSortedTeam2 = team.sorted(by: {(name1: String, name2: String) -> Bool in
    if name1 == "Suzanne" {
        return true
    }
        
    if name2 == "Suzanne" {
        return false
    }
    
    return name1 < name2
})

print(customSortedTeam2)


// == Cleaner Version ==

let customSortedTeam3 = team.sorted {
    if $0 == "Suzanne" {
        return true
    }
        
    if $1 == "Suzanne" {
        return false
    }
    
    return $0 < $1
}

print(customSortedTeam3)




// ========== Passing Function inside a Function =========

func makeArray(size: Int, using generator: () -> Int ) -> [Int]{
    var numbers = [Int]()
    
    for _ in 0..<size {
        let newNum = generator()
        numbers.append(newNum)
    }
    
    return numbers
}


let rolls = makeArray(size: 50, using: {
    Int.random(in: 1...20)
})

print(rolls)




// ======== We can pass any number of functions inside a function as parameters ========

func doAllTheWork(first: () -> Void, second: () -> Void, third: () -> Void){
    first()
    second()
    third()
}

doAllTheWork
{
    print("\nFirst Work Done..!")
}
second: {
    print("Second Work Done..!")
}
third: {
    print("Third Work Done..!\n")
}
