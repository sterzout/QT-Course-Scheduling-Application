#include "student.h"
#include <ostream>
#include <string>
#include <vector>
#include <iostream>
#include "course.h"

Student::Student(const std::string& name, const std::string& userID, const std::string& email, const std::string& password)
    : User(name, userID, email, password) {}

QStringList Student::getPrerequisites() const {
    return prerequisites;
}

QList<Course*> Student::getFallCourses() const {
    return fallCourses;
}

QList<Course*> Student::getWinterCourses() const {
    return winterCourses;
}

void Student::addCourseToFall(Course* course) {
    if (fallCourses.size()>=5){
        std::cout << "Course " << course << " cannot be added to Fall term." << std::endl;
    }else{
        std::cout << "Course " << course << " added to Fall term." << std::endl;
        fallCourses.append(course);

    }
}

void Student::addCourseToWinter(Course* course) {
    if (winterCourses.size()>=5){
        std::cout << "Course " << course << " cannot be added to Winter term." << std::endl;
    }else{
        std::cout << "Course " << course << " added to Winter term." << std::endl;
        winterCourses.append(course);

    }}




void Student::addPrerequisite(Course* course) {
    prerequisites.append(course->getCourseName());
}

void Student::dropCourseFromFall(Course* course) {
    fallCourses.removeAll(course);  // Removes all matching occurrences
}

void Student::dropCourseFromWinter(Course* course) {
    winterCourses.removeAll(course);
}

bool Student::hasPrerequisites(const Course* course) const {
    for (QString prereq : course->getPrerequisites()) {
        if (!prerequisites.contains(prereq)) {
            return false;  // Missing at least one prerequisite
        }
    }
    return true;
}
