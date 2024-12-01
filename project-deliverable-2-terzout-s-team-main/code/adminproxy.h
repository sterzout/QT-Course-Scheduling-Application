#ifndef ADMINPROXY_H
#define ADMINPROXY_H

#include "user.h"
#include "admin.h"

class AdminProxy {
public:
    // Constructor
    AdminProxy(User* user) : user(user) {}

    // Methods to control access to Admin methods
    //for add
    void addCourse(Course* course) {
        if (hasAdminAccess()) {
            static_cast<Admin*>(user)->addCourse(course);
        } else {
            std::cout << "Access Denied: Only administrators can add courses.\n";
        }
    }
    //for remove
    void removeCourse(Course* course) {
        if (hasAdminAccess()) {
            static_cast<Admin*>(user)->removeCourse(course);
        } else {
            std::cout << "Access Denied: Only administrators can remove courses.\n";
        }
    }
    //for remove user
    void removeUsers(User* userToRemove) {
        if (hasAdminAccess()) {
            static_cast<Admin*>(user)->removeUsers(userToRemove);
        } else {
            std::cout << "Access Denied: Only administrators can remove users.\n";
        }
    }

    // Method to check if the user has admin has the access
    bool hasAdminAccess() const {
        return user->getUserID() == "admin1";
    }

private:
    User* user;
};

#endif // ADMINPROXY_H
