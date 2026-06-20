import Cocoa


// ==== Protocols defines the bare minimum functionalities that a struct needs to have

protocol Vehicle {
    var name: String { get }
    var currentPassemgers: Int { get set }
    func estimateTime(for distance: Int) -> Int
    func travel(distance: Int)
}

struct Car: Vehicle {
    let name = "Car"
    var currentPassemgers = 1
    
    func estimateTime(for distance: Int) -> Int {
        return distance / 50
    }
    
    func travel(distance: Int) {
        print("I'm driving \(distance) km")
    }
    
    func openSunRoof() {
        print("It's a nice day!")
    }
}


struct Bicycle: Vehicle {
    let name = "Bicycle"
    var currentPassemgers = 1
    
    func estimateTime(for distance: Int) -> Int {
        return distance / 10
    }
    
    func travel(distance: Int) {
        print("I'm cycling \(distance) km")
    }
}


func commute(distance: Int, using vehicle: Vehicle){
    if(vehicle.estimateTime(for: distance) > 100){
        print("That's too slow, I'll try a different vechicle")
    }
    else{
        vehicle.travel(distance: distance)
    }
}


let car = Car()
commute(distance: 100, using: car)

let bike = Bicycle()
commute(distance: 50, using: bike)


func getTravelEstimates(using vehicles: [Vehicle], distance: Int) {
    for  vehicle in vehicles {
        let estimate = vehicle.estimateTime(for: distance)
        print("\(vehicle.name): \(estimate) hours to Travel \(distance)km")
    }
}

getTravelEstimates(using: [car, bike], distance: 100)
