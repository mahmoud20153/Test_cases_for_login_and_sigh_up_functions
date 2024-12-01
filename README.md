Software Testing Project
Overview
This project demonstrates a comprehensive Software Testing System for a user management application, implemented in C. It includes functionalities for:

User Sign-Up: Validating and storing user information.

Login: Ensuring secure access through email and password verification.

Integration of the CUnit Testing Framework for rigorous testing of the application's functionalities.

Features
User Sign-Up:
Validates user inputs like name, age, date of birth, educational status, and gender.
Implements email and password validation.

User Login:
Secure authentication using validated email and password.

CUnit Test Cases:
Automated testing for both sign-up and login functionalities.
Test cases ensure data integrity and robust validation.

Technologies Used
Programming Language: C
Testing Framework: CUnit
Version Control: Git and GitHub

Folder Structure
Project
│   README.md        # Project documentation
│   main.c           # Entry point for the application
│   sign_up.h        # Header file for sign-up functionalities
│   sign_up.c        # Implementation of sign-up logic
│   login.h          # Header file for login functionalities
│   login.c          # Implementation of login logic
│   tests.c          # CUnit test cases
│   Makefile         # Build automation file (if applicable)
└───docs
        API_Documentation.md # Detailed API docs (optional)
        
How to Run the Project
Clone the Repository:
git clone https://github.com/YourUsername/YourProjectName.git
cd YourProjectName
Build the Project:
If using a Makefile:
make
Otherwise, compile manually:
gcc -o project main.c sign_up.c login.c -lcunit
Run the Project:
./project
Run Tests:
./tests

Getting Started
Prerequisites:
C compiler (e.g., GCC)
CUnit library installed on your system.

Set Up:
Ensure the CUnit library is linked during compilation.
Follow the steps above to build and run the project.
Sample Test Cases

Sign-Up Test:
Input: Valid user details.
Expected Output: User is successfully added to the database.

Login Test:
Input: Correct email and password.
Expected Output: Login successful.

 
