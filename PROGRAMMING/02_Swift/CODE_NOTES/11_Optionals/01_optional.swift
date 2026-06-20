import Cocoa


// ==== Optionals ====

var number: Int? = nil


//number = 4



func printSquare(of number: Int?) {
    
    if let number = number {     // Runs if "number" has some value
        print(number)
    }

    guard let number = number else {     // Runs if "number" doesn't have any value
        print("Number has no value bro")
        return
    }
}

printSquare(of: number)

