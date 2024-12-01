#include "login.h"
#include "sign_up.h"  // Include sign_up.h for access to DB and Account structure

#include <string.h>  // For strcmp()

// Function to validate login by checking the email and password
// against the stored data in DB
bool login(const char* email, const char* password) {
    // Loop through the database to find the user
    for (int i = 0; i < Current_user; i++) {
        // Compare the email and password with stored data
        if (strcmp(DB[i].email, email) == 0 && strcmp(DB[i].password, password) == 0) {
            return true;  // Email and password match, login successful
        }
    }
    // No matching email and password found
    return false;
}
