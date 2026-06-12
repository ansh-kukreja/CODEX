import Cocoa

enum Weekday {
    case monday, tuesday, wednesday, thursday, friday, saturday, sunday
}

var today = Weekday.monday    // Now "today" can only store values of type "Weekday"

today = .tuesday
today = .wednesday
