#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include "course.h"
#include <QString>
#include <QList>
#include "coursecatalog.h"

class Student : public User {
public:
    // Constructor
    Student(const std::string& name, const std::string& userID, const std::string& email, const std::string& password);

    // Accessors for course lists
    QStringList getCompletedCourses() const;
    QStringList getFallCourses() const;
    QStringList getWinterCourses() const;

    // Modifiers for courses
    bool addCourseToFall(Course* course);
    bool addCourseToWinter(Course* course);
    void addCompletedCourse(Course* course);
    bool dropCourseFromFall(Course* course);
    bool dropCourseFromWinter(Course* course);

    // Check if prerequisites are satisfied
    bool hasTheCourse(const Course* course) const;

private:
    QStringList studentCompletedCourses;  // Completed courses
    QStringList fallCourses;    // Courses in the fall term
    QStringList winterCourses;  // Courses in the winter term
    CourseCatalog* courseCatalog;  // Singleton instance of CourseCatalog

};

#endif
