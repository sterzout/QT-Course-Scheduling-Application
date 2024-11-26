#include "student.h"
#include <string>
#include "course.h"
#include "coursecatalog.h"
#include <QDebug>

Student::Student(const std::string& name, const std::string& userID, const std::string& email, const std::string& password)
    : User(name, userID, email, password), courseCatalog(CourseCatalog::getInstance()) {
}

QStringList Student::getCompletedCourses() const {
    return studentCompletedCourses;
}
QStringList Student::getFallCourses() const {
    return fallCourses;
}
QStringList Student::getWinterCourses() const {
    return winterCourses;
}

bool Student::addCourseToFall(Course* course) {
    bool goodToAppend = false;
    if (!studentCompletedCourses.contains(course->getCourseName())){
        if (fallCourses.size()>0){
            for (const QString& prereq : course->getPrerequisites()) {
                if (studentCompletedCourses.contains(prereq) && !fallCourses.contains(prereq) && !winterCourses.contains(prereq)) {
                    goodToAppend = false;
                    break;
                } else {
                    goodToAppend = true;
                }
            }
        }else {
            goodToAppend = true;  // No prerequisites means it's good to add
        }

    }else{
        goodToAppend = false;
    }
    if (goodToAppend && fallCourses.size() < 5) {
        fallCourses.append(course->getCourseName());
        return true;
    } else {
        return false;
    }


}

bool Student::addCourseToWinter(Course* course) {
    bool goodToAppend = false;
    if (!studentCompletedCourses.contains(course->getCourseName())){
        if (winterCourses.size()>0){
            for (const QString& prereq : course->getPrerequisites()) {
                if (studentCompletedCourses.contains(prereq) && !winterCourses.contains(prereq) && !fallCourses.contains(prereq)) {
                    goodToAppend = false;
                    break;
                } else {
                    goodToAppend = true;
                }
            }
        }else {
            goodToAppend = true;  // No prerequisites means it's good to add
        }

    }else{
        goodToAppend = false;
    }
    if (goodToAppend && winterCourses.size() < 5) {
        winterCourses.append(course->getCourseName());
        return true;
    } else {
        return false;
    }
}

//         for (const QString& prereq : course->getPrerequisites()) {
//             if (!studentCompletedCourses.contains(prereq)) {
//                 goodToAppend = false;
//                 break;
//             } else {
//                 goodToAppend = true;
//             }
//         }
//     } else {
//         goodToAppend = true;  // No prerequisites means it's good to add
//     }
// }
// if (goodToAppend && winterCourses.size() < 5) {
//     // winterCourses.append(course);
//     return true;
// } else {
//     return false;
// }





void Student::addCompletedCourse(Course* course) {
    // bool goodToAppend = true;
    // for (QString prereq : course->getPrerequisites()) {
    //     if (studentCompletedCourses.contains(prereq)) {
    //         goodToAppend = false;
    //         break;
    //     }
    // }
    // if (goodToAppend && fallCourses.size()<5){
    //     studentCompletedCourses.append(course->getCourseName());
    // }
}

bool Student::dropCourseFromFall(Course* course) {
    if (fallCourses.contains(course->getCourseName())){
        fallCourses.removeAll(course->getCourseName());
        return true;
    }
    return false;
}
bool Student::dropCourseFromWinter(Course* course) {
    if (winterCourses.contains(course->getCourseName())){
        winterCourses.removeAll(course->getCourseName());
        return true;
    }
    return false;
}



bool Student::hasTheCourse(const Course* course) const {
    // for (QString prereq : course->getPrerequisites()) {
    //     if (!studentCompletedCourses.contains(prereq)) {
    //         return false;  // Missing at least one prerequisite
    //     }
    // }
    // return true;
}
