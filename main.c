// Before including standard headers, remove any macro definitions
#undef snprintf

// Include standard headers
#include <stdio.h>
#include <CUnit.h>	   // ASSERT macros for use in test cases, and includes other framework headers.
#include <CUError.h>   // Error handling functions and data types. Included automatically by CUnit.h.
#include <TestDB.h>    // Data type definitions and manipulation functions for the test registry, suites, and tests. Included automatically by CUnit.h.
#include <TestRun.h>   // Data type definitions and functions for running tests and retrieving results. Included automatically by CUnit.h.
#include <Automated.h> // Automated interface with xml output.
#include <Basic.h>     // Basic interface with non-interactive output to stdout.
#include <Console.h>   // Interactive console interface.
#include <CUCurses.h>  // Interactive console interface (*nix).

#include "sign_up.h"
#include "login.h"

/* Test Code to test the Sign Up */
struct Account Test_User =
{
	-1, // this is to indicate user hasn't assigned ID 
	"Mahmoud Reda",
	26,
	01,
	02,
	1999,
	Male,
	Masters_Student,
	"redareda@gmail.com",
	"0106079149"
};
unsigned char Result;

/* The function that will execute before executing the Test suite */
int test_start()
{
	// Start the test by adding the user
	printf("\nTest User Adding\n");
	Test_User.id = Current_user;  // Assigning user ID
	Result = assign(&Test_User);  // Call to sign-up function to add user to DB
	printf("\nTest User Added with id %d\n", Test_User.id);
	// Return 0 to indicate the setup was successful
	return 0;
}

/* The function that will execute after executing the Test suite */
int test_end()
{
	// Clean up after tests (if needed)
	printf("\nTest Suite Executed Successfully with user ID %d\n", Test_User.id);
	return 0;
}

/************************************************************************************
* Test ID                : TestCase 1
* Description            : Testing the Sign Up Functionality
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Mahmoud Reda
*                          Age                          -> 26
*                          DOB_day                      -> 01
*                          DOB_Month                    -> 02
*                          DOB_Year                     -> 1999
*                          Educational_Status           -> Masters_Student
*                          Gender                       -> Male
*                          Email                        -> redareda@gmail.com
*                          Password                     -> 01060791489
* Test Expected output   : The DB should be updated with the previous inputs correctly
*                          and Function should return 1
*************************************************************************************/

void TestCase1()
{
	// Assert that the result of the sign-up is 1 (success)
	CU_ASSERT_EQUAL(Result, 1);

	// Assert that the user information was correctly added to the DB
	CU_ASSERT_STRING_EQUAL(DB[Test_User.id].name, Test_User.name);
	CU_ASSERT_EQUAL(DB[Test_User.id].id, Current_user - 1);  // Check if ID is correct
	CU_ASSERT_EQUAL(DB[Test_User.id].Age, Test_User.Age);
	CU_ASSERT_EQUAL(DB[Test_User.id].DOB_day, Test_User.DOB_day);
	CU_ASSERT_EQUAL(DB[Test_User.id].DOB_month, Test_User.DOB_month);
	CU_ASSERT_EQUAL(DB[Test_User.id].DOB_year, Test_User.DOB_year);
	CU_ASSERT_EQUAL(DB[Test_User.id].educational_status, Test_User.educational_status);
	CU_ASSERT_EQUAL(DB[Test_User.id].gender, Test_User.gender);
	CU_ASSERT_STRING_EQUAL(DB[Test_User.id].email, Test_User.email);  // Email validation
	CU_ASSERT_STRING_EQUAL(DB[Test_User.id].password, Test_User.password);  // Password validation
}
/************************************************************************************
* Test ID                : TestCase 2
* Description            : Testing the Login Functionality
* Pre-requisites         : There is a User Assigned to DB (Test User)
* Test inputs            :
*                          Valid Email                   -> redareda@gmail.com
*                          Valid Password                -> 01060791489
*                          Invalid Email                 -> wrongemail@gmail.com
*                          Invalid Password              -> wrongpassword
* Test Expected output   :
*                          Login with valid credentials should return 1.
*                          Login with invalid credentials should return 0.
*************************************************************************************/

void TestCase2()
{
	// Test valid login
	unsigned char login_result = login("redareda@gmail.com", "01060791489");
	CU_ASSERT_EQUAL(login_result, 1);  // Should return 1 (valid credentials)

	// Test invalid login with wrong email
	login_result = login("wrongemail@gmail.com", "01060791489");
	CU_ASSERT_EQUAL(login_result, 0);  // Should return 0 (invalid email)

	// Test invalid login with wrong password
	login_result = login("redareda@gmail.com", "wrongpassword");
	CU_ASSERT_EQUAL(login_result, 0);  // Should return 0 (invalid password)
}

// Main test runner
int main()
{
	// Initialize the CUnit registry
	if (CU_initialize_registry() != CUE_SUCCESS) {
		printf("Registry initialization failed!\n");
		return CU_get_error();
	}

	// Adding Test Suite to the Registry
	CU_pSuite suite_page = CU_add_suite("Sign Up and Login", test_start, test_end);
	if (suite_page == NULL) {
		printf("Suite creation failed!\n");
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Adding Test Cases to the Test Suite
	if (CU_add_test(suite_page, "Sign Up", TestCase1) == NULL) {
		printf("Test case for sign-up addition failed!\n");
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Adding the login test case
	if (CU_add_test(suite_page, "Login", TestCase2) == NULL) {
		printf("Test case for login addition failed!\n");
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Running the Automated Test */
		// CU_automated_run_tests();
		// CU_list_tests_to_file();

		/* Running the Test Suite through Basic Console */
		//CU_basic_set_mode(CU_BRM_VERBOSE);
		//CU_basic_run_tests();

		/* Running the Test Suite through Console interactive */
	CU_console_run_tests();


	/* Clear the registry after test finished */
	CU_cleanup_registry();

	return 0;
}


