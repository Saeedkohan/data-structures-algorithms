import csv

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None



class Student:
    def __init__(self, student_id, name, average):
        self.student_id = student_id
        self.name = name
        self.average = float(average)


class Professor:
    def __init__(self, prof_id, name):
        self.prof_id = prof_id
        self.name = name



class Major:
    def __init__(self, name, physical_space):
        self.name = name
        self.physical_space = float(physical_space)
        self.students_head = None
        self.professors_head = None


def add_student(major, student):
    node = Node(student)
    node.next = major.students_head
    major.students_head = node


def add_professor(major, professor):
    node = Node(professor)
    node.next = major.professors_head
    major.professors_head = node



def count_students(major):
    count = 0
    current = major.students_head
    while current:
        count += 1
        current = current.next
    return count


def count_professors(major):
    count = 0
    current = major.professors_head
    while current:
        count += 1
        current = current.next
    return count


def average_of_major(major):
    total = 0
    count = 0
    current = major.students_head
    while current:
        total += current.data.average
        count += 1
        current = current.next
    return total / count if count != 0 else 0


def top_3_students(major):
    students = []
    current = major.students_head
    while current:
        students.append(current.data)
        current = current.next

    students.sort(key=lambda s: s.average, reverse=True)
    return students[:3]


def space_per_student(major):
    students = count_students(major)
    if students == 0:
        return 0
    return major.physical_space / students


def load_students_from_csv(filename, majors):
    with open(filename, newline='', encoding='utf-8') as file:
        reader = csv.DictReader(file)
        for row in reader:
            student = Student(row['student_id'],row['name'],row['average'])
            add_student(majors[row['major']], student)


def load_professors_from_csv(filename, majors):
    with open(filename, newline='', encoding='utf-8') as file:
        reader = csv.DictReader(file)
        for row in reader:
            professor = Professor(row['prof_id'],row['name'])
            add_professor(majors[row['major']], professor)




def show_major_info(major):
    print("\major:", major.name)
    print("Number of students:", count_students(major))
    print("Average:", round(average_of_major(major), 2))
    print("Number of professors:", count_professors(major))
    print("Physical space per student:", round(space_per_student(major), 2))

    print("Top three students:")
    top_students = top_3_students(major)
    if not top_students:
        print("Unregistered student")
    else:
        for s in top_students:
            print(f"{s.name} | average: {s.average}")


def menu(majors):
    while True:
        print("1.Display information of each major")
        print("2.Exit")

        choice = input("Input :")

        if choice == "1":
            for key in majors:
                show_major_info(majors[key])
        elif choice == "2":
            print("Exit")
            break
        else:
            print("Invalid option")



majors = {
    "CS": Major("CS", 500),
    "Math": Major("Math", 300),
    "Physics": Major("Physics", 400)
}
load_students_from_csv("students.csv", majors)
load_professors_from_csv("professors.csv", majors)
menu(majors)