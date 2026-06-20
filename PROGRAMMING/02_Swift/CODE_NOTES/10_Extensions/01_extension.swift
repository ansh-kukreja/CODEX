import Cocoa


// Extensions

// Usecase 1
extension String {
    func trimmed() -> String {
        self.trimmingCharacters(in: .whitespacesAndNewlines)
    }
    
    mutating func trim() {
        self = self.trimmed()
    }
    
    var lines: [String] {
        self.components(separatedBy: .newlines)
    }
}


let s = "     Tere kalle jatt ne si bande 4 dakk lee..  taiyo tere pind vich rolla pe gya..      "
let cleanString = s.trimmed()

print(cleanString)



// Usecase 2
extension Array {
    func isNotEmpty() -> Bool {
        self.isEmpty == false
    }
}

let guests = ["Mario", "Sonic", "Jack", "Dino"]

if guests.isNotEmpty() {
    print("We have \(guests.count) guests!")
}

