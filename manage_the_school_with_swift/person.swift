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

class Mentor: Person, Classify {
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

class Student: Person, Classify {
    func isStudent() -> Bool {
        return true
    }
}

protocol Classify {
    func isStudent() -> Bool
}

class School {
    var name: String
    var list_persons: [Person] = []

    init(name: String) {
        self.name = name
    }

    func addStudent(p: Person) -> Bool {
        if p is Student {
            list_persons.append(p)
            return true
        }
        return false
    }
    func addMentor(p: Person) -> Bool {
        if p is Mentor {
            list_persons.append(p)
            return true
        }
        return false
    }

    func listStudents() -> [Person] {
        var list_students = list_persons.filter({(p) -> Bool in
            return p is Student
        })

        list_students = list_students.sort{(a, b) -> Bool in
            return a.age > b.age
        }

        return list_students
    }

    func listMentors() -> [Person] {
        var list_mentors = list_persons.filter({(p) -> Bool in
            return p is Mentor
        })

        list_mentors = list_mentors.sort{(a, b) -> Bool in
            return a.age > b.age
        }

        return list_mentors
    }

    func listMentorsBySubject(subject: Subject) -> [Person] {
        let list_mentors = listMentors()

        var list_mentors_by_subject = list_mentors as! [Mentor]

        list_mentors_by_subject = list_mentors_by_subject.filter({(m) -> Bool in
            return m.subject == subject
        })

        return list_mentors_by_subject
    }
}
