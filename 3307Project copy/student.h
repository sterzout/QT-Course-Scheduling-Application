#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include "course.h"
#include <QString>
#include <QList>

class Student : public User {
public:
    // Constructor
    Student(const std::string& name, const std::string& userID, const std::string& email, const std::string& password);

    // Accessors for course lists
    QStringList getPrerequisites() const;
    QList<Course*> getFallCourses() const;
    QList<Course*> getWinterCourses() const;

    // Modifiers for courses
    void addCourseToFall(Course* course);
    void addCourseToWinter(Course* course);
    void addPrerequisite(Course* course);
    void dropCourseFromFall(Course* course);
    void dropCourseFromWinter(Course* course);

    // Check if prerequisites are satisfied
    bool hasPrerequisites(const Course* course) const;

private:
    QStringList prerequisites;  // Completed courses
    QList<Course*> fallCourses;    // Courses in the fall term
    QList<Course*> winterCourses;  // Courses in the winter term
};

#endif
