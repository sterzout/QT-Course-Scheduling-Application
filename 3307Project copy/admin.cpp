#include "admin.h"
#include <iostream>

Admin::Admin(const std::string& name, const std::string& userID, const std::string& email, const std::string& password)
    : User(name, userID, email, password) {}



