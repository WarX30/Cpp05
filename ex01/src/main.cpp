#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include <exception>

int	main(void)
{
	std::cout << BOLD_ON << "===== FORM CONSTRUCTION ====="
			  << BOLD_OFF << std::endl;
	try{
		Form taxForm("Tax Form", 50, 25);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n" << BOLD_ON << "===== SUCCESSFULL SIGN ====="
			  << BOLD_OFF << std::endl;
	try {
		Bureaucrat bob("bob", 50);
		Form taxForm("Tax Form", 50, 25);
		Form form1("Highest", 1, 1);
		Form form2("Lowest", 150, 150);

		std::cout << bob << std::endl;
		std::cout << taxForm << std::endl;

		bob.signFrom(taxForm);

		std::cout << taxForm << std::endl;

		bob.incrementGrade(49);
		std::cout << bob << std::endl;
		std::cout << form1 << std::endl;
		bob.signFrom(form1);
		std::cout << form1 << std::endl;

		bob.decrementGrade(149);
		std::cout << bob << std::endl;
		std::cout << form2 << std::endl;
		bob.signFrom(form2);
		std::cout << form2 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n" << BOLD_ON << "===== FAILED SIGN ====="
			  << BOLD_OFF << std::endl;
	try {
		Bureaucrat alice("Alice", 100);
		Form taxForm("Tax Form", 50, 25);

		std::cout << alice << std::endl;
		std::cout << taxForm << std::endl;

		alice.signFrom(taxForm);

		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n" << BOLD_ON << "===== INVALID FORM: GRADE 0 ====="
			  << BOLD_OFF << std::endl;
	try {
		Form invalid("Invalid Form", 0, 25);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n" << BOLD_ON << "===== INVALID FORM: GRADE 151 ====="
			  << BOLD_OFF << std::endl;
	try {
		Form invalid("Invalid Form", 151, 25);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n" << BOLD_ON << "===== COPY CONSTRUCTOR ====="
			  << BOLD_OFF << std::endl;
	try {
		Form original("Original", 50, 25);
		Bureaucrat bob("Bob", 25);

		bob.signFrom(original);

		Form copy(original);

		std::cout << "Original: " << std::endl;
		std::cout << original << std::endl;

		std::cout << "Copy: " << std::endl;
		std::cout << copy << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n" << BOLD_ON << "===== ASSIGNMENT OPERATOR ====="
			  << BOLD_OFF << std::endl;
	try {
		Form original("Original", 50, 25);
		Form target("Target", 100, 75);
		Bureaucrat bob("Bob", 25);

		bob.signFrom(original);

		std::cout << "Before assignment: " << std::endl;
		std::cout << target << std::endl;

		target = original;

		std::cout << "After assignment: " << std::endl;
		std::cout << target << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
