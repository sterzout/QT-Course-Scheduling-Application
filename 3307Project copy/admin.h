#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin : public User {
public:
    // Constructor: Use const std::string& for parameters that are not modified
    Admin(const std::string& name, const std::string& userID, const std::string& email, const std::string& password);
};

#endif // ADMIN_H
