#include "user.h"
#include "student.h"
#include "admin.h"


User::User(const std::string& name, const std::string& userID, const std::string& email, const std::string& password)
    : name(name), userID(userID), email(email), password(password) {}

std::string User::getName() const {
    return name;
}

std::string User::getUserID() const {
    return userID;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getPassword() const {
    return password;
}


User* User::createUser(const std::string& name, const std::string& userID, const std::string& email, const std::string& password) {
    if (userID == "admin1") {
        // Return an Admin object
        return new Admin(name, userID, email, password);
    } else {
        // Return a Student object
        return new Student(name, userID, email, password);
    }
}
