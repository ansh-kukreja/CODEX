import Cocoa


// ======== Inheritance ========

class Employee{
    let hours: Int
    
    init(hours: Int){
        self.hours = hours
    }
    
    func greet(){
        print("Hello there.. I'm an Employee")
    }
}

class Developer: Employee{
    func work(){
        print("I'm writing code for \(hours) hours")
    }
}


let dave = Developer(hours: 8)
dave.work()




// ====== Function Overriding =======

class Intern: Employee{
    override func greet(){
        print("Hello there.. I'm an Intern")
    }
}




// ====== Final Classes can't be Inherited by Child Classes (It itself can inherit from another class) =======

final class FinalClass: Employee{
    
}




// ======= Initializers/Constructors ========

class Vehichle {
    let isElectric: Bool
    
    init(isElectric: Bool) {
        self.isElectric = isElectric
    }
}

class Car: Vehichle {
    let isConvertible: Bool
    
    init(isElectric: Bool, isConvertible: Bool) {
        self.isConvertible = isConvertible
        super.init(isElectric: isElectric)
    }
}




// ===== Copying Classes ======

class User {
    var username = "Anonymous"
}

let user1 = User()
let user2 = user1

user2.username = "Meggsy"

print(user1.username)   // <- These both share same memory
print(user2.username)   //



// To actually create a copy

class User2 {
    var username = "Anonymous"
    
    func copy() -> User2 {
        let user = User2()
        user.username = username
        return user
    }
}

var user4 = User2()
var user5 = user4.copy()




// ===== Deinitializer =====

class User6 {
    var id: Int
    
    init(id: Int) {
        self.id = id
        print("I got alive: \(id)")
    }
    
    deinit {
        print("I am ded: \(id)")
    }
}
