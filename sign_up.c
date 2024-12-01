#include "sign_up.h"
#include "string.h"

// Function to validate email (already declared in sign_up.h)
bool validate_email(const char* email) {
	// Email validation logic
	if (email == NULL || strlen(email) < 5) {
		return false;
	}

	const char* at = strchr(email, '@');  // Locate '@'
	const char* dot = strrchr(email, '.'); // Locate last '.'

	// Check if '@' and '.' exist and are in the correct order
	if (!at || !dot || at > dot) {
		return false;
	}

	// Check that '@' is not the first character and '.' is not the last
	if (at == email || dot == (email + strlen(email) - 1)) {
		return false;
	}

	// Validate each character in the email
	for (const char* ptr = email; *ptr; ptr++) {
		if (!isalnum(*ptr) && *ptr != '@' && *ptr != '.' && *ptr != '-' && *ptr != '_') {
			return false; // Invalid character
		}

		// Check for consecutive special characters
		if ((*(ptr) == '.' || *(ptr) == '@' || *(ptr) == '-' || *(ptr) == '_') &&
			(*(ptr + 1) == '.' || *(ptr + 1) == '@' || *(ptr + 1) == '-' || *(ptr + 1) == '_')) {
			return false; // Consecutive special characters
		}
	}

	return true;
}

// Function to validate password (already declared in sign_up.h)
bool validate_password(const char* password) {
	if (password == NULL || strlen(password) < 8) {
		return false; // Password should be at least 8 characters long
	}

	// Check for at least one digit, one letter, and one special character
	bool has_digit = false, has_alpha = false, has_special = false;
	for (int i = 0; password[i] != '\0'; i++) {
		if (isdigit(password[i])) {
			has_digit = true;
		}
		else if (isalpha(password[i])) {
			has_alpha = true;
		}
		else if (ispunct(password[i])) {
			has_special = true;
		}
	}

	return has_digit && has_alpha && has_special;
}

unsigned char assign(struct Account* Form) {
	// the variable to hold the return value
	unsigned char RET = 0;
	/* Check the name length is less than 32 */
	if (strlen(Form->name) > 32)
	{
		RET = 0;
	}
	/* Check the Age is in Acceptable range 0 - 100 */
	else if (Form->Age < 0 || Form->Age>100)
	{
		RET = 0;
	}
	/* Check the DOB_day is in Acceptable range 1 - 31 */
	else if (Form->DOB_day < 1 || Form->DOB_day > 31)
	{
		RET = 0;
	}
	/* Check the DOB_month is in Acceptable range 1 - 12 */
	else if (Form->DOB_month < 1 || Form->DOB_month > 12)
	{
		RET = 0;
	}
	/* Check the DOB_year is in Acceptable range 1924 - 2024 */
	else if (Form->DOB_year < 1924 || Form->DOB_year > 2024)
	{
		RET = 0;
	}
	/* Check the edeucational status is accepted one */
	else if (Form->educational_status != Student && Form->educational_status != Faculty_Student && Form->educational_status != Graduate &&
		Form->educational_status != Masters_Student && Form->educational_status != PHD_Student && Form->educational_status != PHD_Holder)
	{
		RET = 0;
	}

	/* Check the gender is accepted one */
	else if (Form->gender != Male && Form->gender != Female)
	{
		RET = 0;
	}

	/* Every thing is okay */
	else
	{
		DB[Current_user].id = Current_user;
		strcpy(DB[Current_user].name, Form->name); // Copy name
		DB[Current_user].Age = Form->Age;
		DB[Current_user].DOB_day = Form->DOB_day;
		DB[Current_user].DOB_month = Form->DOB_month;
		DB[Current_user].DOB_year = Form->DOB_year;
		DB[Current_user].educational_status = Form->educational_status;
		DB[Current_user].gender = Form->gender;
		strcpy(DB[Current_user].email, Form->email);  // Copy email
		strcpy(DB[Current_user].password, Form->password);  // Copy password
		RET = 1;
		Current_user++;
	}

	return RET;
}




