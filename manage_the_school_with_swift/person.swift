class Person {

    var first_name: String
    var last_name: String
    var age: Int

    init(first_name: String, last_name: String, age: Int) {
        self.first_name = first_name
        self.last_name = last_name
        self.age = age
    }

    func fullName() -> String {
        return first_name + " " + last_name
    }
}

class Mentor: Person {
    func isStudent() -> Bool {
        return false
    }
}

class Student: Person {
    func isStudent() -> Bool {
        return true
    }
}

protocol Classify {
    func isStudent() -> Bool
}
