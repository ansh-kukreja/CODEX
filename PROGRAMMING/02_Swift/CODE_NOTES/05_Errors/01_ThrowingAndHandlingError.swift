import Cocoa


enum PasswordError: Error{
    case short, obvious
}


func checkPassword(_ password: String) throws -> String{
    if password.count <= 4 { throw PasswordError.short}
    if password == "12345" { throw PasswordError.obvious}
    
    return "Strong Password✅"
}





do{
    let myPass: String = "12345"
    let result = try checkPassword(myPass)
    print(result)
}

catch PasswordError.short{
    print("Password must contain atleast 5 digits")
}

catch{
    print("Error: Weak Password ❌")
}