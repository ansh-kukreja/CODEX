import Cocoa


struct Album{
    let title: String
    let artist: String
    let year: Int
    
    func printSummary(){
        print("\(title) by \(artist) (\(year))")
    }
}

let interstellar = Album(title: "Intersteller", artist: "Harkirat Sangha", year: 2025)

interstellar.printSummary()




// If we create a constant object of a struct, then swift will mark all of its properties as constant too..
// So Swift doesn't allow struct's member functions to change the value of struct variables unless stated explicitly

// So to make a function to be able to modify the struct variables, we have to make the function "mutating"

// e.g.

struct AlbumInfo{
    var a = 40   // <== Default Value
    var noOfSongs: Int
    
    func changeCount1(){
//        noOfSongs = 10        //  <<== Throws error
        print("No of Songs in the album is \(noOfSongs)")
    }
    
    mutating func changeCount2(){
        noOfSongs += 1
        print("No of Songs in the album is \(noOfSongs)")
    }
}

// ==== For a Variable Object the Mutating function works fine ====
var album1 = AlbumInfo(noOfSongs: 7)
album1.changeCount2()


// ==== For a Constant Object the Mutating function is not accessible ====
let album2 = AlbumInfo(noOfSongs: 8)
//album2.changeCount2()




//  ========== Getter/Setter ===========

struct Employee{
    let name: String
    var vacationAllocated = 14
    var vacationTaken = 0
    
//    var vacationRemaining: Int {
//        vacationAllocated - vacationTaken        <<== This is a computed property that we can access like a normal variable
//    }
    
    var vacationRemaining: Int {
        get{  // Getter
            vacationAllocated - vacationTaken
        }
        set{ // Setter
            vacationAllocated = vacationTaken + newValue
        }
    }
}

var emp1 = Employee(name: "kdjd", vacationAllocated: 24)
emp1.vacationTaken += 4

print(emp1.vacationRemaining)      // Getter
emp1.vacationRemaining = 10        // Setter
print(emp1.vacationAllocated)




// ========== Property Observers ==========
// Whenever a property is changed.. it will trigger the Property Observer Function

struct Game {
    var score = 0 {    // 'score' is a normal variable, just that an observer is attached to it
        didSet{
            print("Score is now \(score)")
        }
    }
}

var hideAndSeek = Game()
hideAndSeek.score += 2
hideAndSeek.score -= 1
hideAndSeek.score += 5
hideAndSeek.score += 2




struct App {
    var contacts = [String]() {
        willSet{
            print("New Value will be \(newValue)")
        }
        didSet{
            print("There are now \(contacts.count) contacts")
            print("Old Value was \(oldValue)")
        }
    }
}

var app = App()
app.contacts.append("Tom Hardy")




// ========= Initialiser / Constructor ==========

struct Player {
    let name: String
    let number: Int
    
    init(name: String){
        self.name = name
        self.number = Int.random(in: 1...99)
    }
}

let player = Player(name: "Messi")
print(player.number)




// ======== Access Specifiers =========

// Swift has these access specifiers:
// 1. private
// 2. fileprivate
// 3. public
// 4. private(set)


struct BankAccount{
    private var funds = 0
}




// ======= Static Variables/Functions ========

struct AppData {
    static let version = "2026.0.01"
}

print(AppData.version)




