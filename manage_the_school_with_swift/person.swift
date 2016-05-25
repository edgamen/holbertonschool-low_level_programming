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

enum Subject: String {
    case Math
    case English
    case French
    case History
}

class Mentor: Person {
    let subject: Subject?

    func isStudent() -> Bool {
        return false
    }

    init(first_name: String, last_name: String, age: Int, subject: Subject = Subject.Math)
    {
        self.subject = subject
        super.init(first_name: first_name, last_name: last_name, age: age)
    }

    func stringSubject() -> String {
        if self.subject == nil {
            return "Err: Subject is nil"
        }
        else {
            return self.subject!.rawValue
        }
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
