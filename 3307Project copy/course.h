#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QStringList>

class Course
{
public:
    // Constructor with parameters
    Course(const QString& faculty, const QString& courseName, const QStringList& prerequisites);

    // Getters for course properties
    QString getFaculty() const;
    QString getCourseName() const;
    QStringList getPrerequisites() const;

private:
    QString faculty;
    QString courseName;
    QStringList prerequisites;
};

#endif // COURSE_H
