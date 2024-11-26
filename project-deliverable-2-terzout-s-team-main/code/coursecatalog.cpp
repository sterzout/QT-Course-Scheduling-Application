#include "coursecatalog.h"
#include "course.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

// Initialize the static instance to nullptr
CourseCatalog* CourseCatalog::instance = nullptr;

CourseCatalog* CourseCatalog::getInstance() {
    if (instance == nullptr) {
        instance = new CourseCatalog();  // Create the singleton instance if it doesn't exist
    }
    return instance;
}

void CourseCatalog::addCourse(Course* course) {
    courses.append(course);  // Add the course to the catalog
}

QList<Course*> CourseCatalog::getCourses() const {
    return courses;  // Return the list of courses
}
