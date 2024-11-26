QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    course.cpp \
    coursecatalog.cpp \
    coursepage.cpp \
    coursetimetable.cpp \
    createaccountpage.cpp \
    falltermpage.cpp \
    loginorcreate.cpp \
    main.cpp \
    mainwindow.cpp \
    prerequisitepage.cpp \
    student.cpp \
    user.cpp \
    wintertermpage.cpp

HEADERS += \
    admin.h \
    course.h \
    coursecatalog.h \
    coursepage.h \
    coursetimetable.h \
    createaccountpage.h \
    falltermpage.h \
    loginorcreate.h \
    mainwindow.h \
    prerequisitepage.h \
    student.h \
    user.h \
    wintertermpage.h

FORMS += \
    coursepage.ui \
    coursetimetable.ui \
    createaccountpage.ui \
    falltermpage.ui \
    loginorcreate.ui \
    mainwindow.ui \
    prerequisitepage.ui \
    wintertermpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    courses.txt \
    studentCourseInfo.txt \
    tempfile.txt \
    userlogininfo.txt
