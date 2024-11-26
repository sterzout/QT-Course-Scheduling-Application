#ifndef COURSECATALOG_H
#define COURSECATALOG_H

#include "course.h"
#include <QString>
#include <QList>

class CourseCatalog {
public:
    static CourseCatalog* getInstance();  // Get the singleton instance

    void addCourse(Course* course);  // Add a course to the catalog
    QList<Course*> getCourses() const;  // Get all courses in the catalog

private:
    CourseCatalog() {}  // Private constructor to prevent direct instantiation
    ~CourseCatalog() {}  // Destructor

    static CourseCatalog* instance;  // Static instance of CourseCatalog
    QList<Course*> courses;  // List of courses
};

#endif
