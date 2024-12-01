#pragma once

#include <stdbool.h>  // To define bool, true, false

// Function to validate login by checking the email and password
// against the stored data in DB
bool login(const char* email, const char* password);
