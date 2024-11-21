#ifndef USER_H
#define USER_H

#include <string>


class User {
public:
    std::string name;
    std::string userID;
    std::string email;
    std::string password;

    // Constructor and destructor
    User(const std::string& name, const std::string& userID, const std::string& email, const std::string& password);
    virtual ~User() {} // Ensure proper cleanup in derived classes

    // Getters
    virtual std::string getName() const;
    virtual std::string getUserID() const;
    virtual std::string getEmail() const;
    virtual std::string getPassword() const;



    // Static factory method to create User objects based on userID
    static User* createUser(const std::string& name, const std::string& userID, const std::string& email, const std::string& password);
};

#endif
