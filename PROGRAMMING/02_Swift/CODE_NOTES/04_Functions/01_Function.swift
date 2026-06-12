import Cocoa


func printTableOf(num: Int){
    for i in 1...10 {
        print("\(num) x \(i) = \(num * i)")
    }
}
printTableOf(num: 7)




func rollDice() -> Int {
    return Int.random(in: 1...20)  // Writing 'return' is optional when there is only 1 line of code in func
}
print(rollDice())





// ========= Using Tuples with Functions ==========

// ---- Version 1 ----
func getUser() -> (firstName: String, lastName: String) {
    
    let userTuple = (firstName: "Ansh", lastName: "Kukreja");
    return userTuple;
    
}

let user1 = getUser()
print(user1.firstName)
print(user1.lastName)




// ---- Version 2 ----
func getUser2() -> (firstName: String, lastName: String) {
    
    let userTuple = ("Ansh","Kukreja");
    return userTuple;
    
}

let user2 = getUser2()
print(user2.firstName)
print(user2.lastName)




// ---- Version 3 ----
func getUser3() -> (String,String) {
    
    let userTuple = ("Ansh","Kukreja");
    return userTuple;
    
}

let user3 = getUser3()
print(user3.0)
print(user3.1)




// ---- Version 4 ----
func getUser4() -> (firstName: String, lastName: String) {
    
    let userTuple = ("Ansh","Kukreja");
    return userTuple;
    
}

let (firstName, lastName) = getUser4()

print(firstName)
print(lastName)





// ========== Somethin new here.. ==========

func hireEmployee(name: String) { }

func hireEmployee(title: String) { }

func hireEmployee(location: String) { }





// ========= When we don't want to give labels while passing arguments =========

func greet(_ name: String){
    print("Kive aa \(name)")
}
 
greet("Singh")




// ====== Having different name for parameter =======

func greet2(name personName: String){
    print("Kive aa \(personName)")
}
greet2(name: "Singh")





// ==== Default Values ====

func greet3(name personName: String = "Insaan"){
    print("Kive aa \(personName)")
}
greet3()