#pragma once
#include <stdbool.h>

// maximum number of users in the SW
#define Max_users 1000

// this is to supress the error of using strcpy instead of strcpy_s
#define _CRT_SECURE_NO_WARNINGS

// Global variable that holds the current user id 
int Current_user;

enum Gender {
	Male,
	Female
};

enum Educational_Status
{
    Student,
    Faculty_Student,
    Graduate,
    Masters_Student,
    PHD_Student,
    PHD_Holder
};

// Structure that contains the user info
struct Account
{
    unsigned id;
    char name[32];
    int Age;
    unsigned char DOB_day;
    unsigned char DOB_month;
    unsigned short DOB_year;
    enum Gender gender;
    enum Educational_Status educational_status;
    char email[64];
    char password[32];
};

// this array is of structures Account
// each element is the info of one user 
struct Account DB[Max_users];

// This function takes a pointer to the structure account 
// The function is designed to add a new user’s data to the database (DB)
unsigned char assign(struct Account* Form);

/**
 * Validates the email format.
 *
 * @param email Pointer to the email string.
 * @return true if the email format is valid, false otherwise.
 */
bool validate_email(const char* email);

/**
 * Validates the password strength.
 *
 * @param password Pointer to the password string.
 * @return true if the password meets the required criteria, false otherwise.
 */
bool validate_password(const char* password);

/**
 * Checks if both email and password in the account are valid.
 *
 * @param account Pointer to the Account structure.
 * @return true if both email and password are valid, false otherwise.
 */
bool is_valid_account(const struct Account* account);

