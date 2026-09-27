#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
	std::srand(std::time(NULL));

	std::cout << "\n";
	std::cout << BOLD_ON BLUE
			  << "========== CPP05 EX02 =========="
			  << BOLD_OFF << std::endl;

	/* ========================================================= */
	/*                       BUREAUCRATS                         */
	/* ========================================================= */

	std::cout << "\n";
	std::cout << BOLD_ON CYAN
			  << "===== BUREAUCRATS ====="
			  << BOLD_OFF << std::endl;

	Bureaucrat boss("Boss", 1);
	Bureaucrat middle("Middle", 50);
	Bureaucrat junior("Junior", 150);

	std::cout << boss;
	std::cout << middle;
	std::cout << junior;


	/* ========================================================= */
	/*                 SHRUBBERY CREATION FORM                  */
	/* ========================================================= */

	std::cout << "\n";
	std::cout << BOLD_ON CYAN
			  << "===== SHRUBBERY CREATION ====="
			  << BOLD_OFF << std::endl;

	ShrubberyCreationForm shrubbery("garden");

	std::cout << shrubbery << std::endl;

	std::cout << BOLD_ON YELLOW
			  << "--- Execute before signing ---"
			  << BOLD_OFF << std::endl;

	boss.executeForm(shrubbery);

	std::cout << BOLD_ON YELLOW
			  << "--- Sign form ---"
			  << BOLD_OFF << std::endl;

	boss.signForm(shrubbery);

	std::cout << BOLD_ON YELLOW
			  << "--- Execute after signing ---"
			  << BOLD_OFF << std::endl;

	boss.executeForm(shrubbery);


	/* ========================================================= */
	/*                   ROBOTOMY REQUEST                        */
	/* ========================================================= */

	std::cout << "\n";
	std::cout << BOLD_ON CYAN
			  << "===== ROBOTOMY REQUEST ====="
			  << BOLD_OFF << std::endl;

	RobotomyRequestForm robotomy("Bender");

	std::cout << robotomy << std::endl;

	std::cout << BOLD_ON YELLOW
			  << "--- Sign form ---"
			  << BOLD_OFF << std::endl;

	middle.signForm(robotomy);

	std::cout << BOLD_ON YELLOW
			  << "--- Robotomy attempts ---"
			  << BOLD_OFF << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "\nAttempt " << i + 1 << ": ";
		boss.executeForm(robotomy);
	}


	/* ========================================================= */
	/*                 PRESIDENTIAL PARDON                       */
	/* ========================================================= */

	std::cout << "\n";
	std::cout << BOLD_ON CYAN
			  << "===== PRESIDENTIAL PARDON ====="
			  << BOLD_OFF << std::endl;

	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << pardon << std::endl;

	std::cout << BOLD_ON YELLOW
			  << "--- Sign form ---"
			  << BOLD_OFF << std::endl;

	middle.signForm(pardon);

	std::cout << BOLD_ON YELLOW
			  << "--- Middle executes ---"
			  << BOLD_OFF << std::endl;

	middle.executeForm(pardon);

	std::cout << BOLD_ON YELLOW
			  << "--- Boss executes ---"
			  << BOLD_OFF << std::endl;

	boss.executeForm(pardon);


	/* ========================================================= */
	/*                    GRADE TESTS                             */
	/* ========================================================= */

	std::cout << "\n";
	std::cout << BOLD_ON CYAN
			  << "===== GRADE TESTS ====="
			  << BOLD_OFF << std::endl;

	PresidentialPardonForm difficultPardon("Ford Prefect");

	std::cout << BOLD_ON YELLOW
			  << "--- Junior tries to sign ---"
			  << BOLD_OFF << std::endl;

	junior.signForm(difficultPardon);

	std::cout << BOLD_ON YELLOW
			  << "--- Boss signs ---"
			  << BOLD_OFF << std::endl;

	boss.signForm(difficultPardon);

	std::cout << BOLD_ON YELLOW
			  << "--- Junior tries to execute ---"
			  << BOLD_OFF << std::endl;

	junior.executeForm(difficultPardon);

	std::cout << BOLD_ON YELLOW
			  << "--- Boss executes ---"
			  << BOLD_OFF << std::endl;

	boss.executeForm(difficultPardon);


	/* ========================================================= */
	/*                    COPY CONSTRUCTOR                        */
	/* ========================================================= */

	std::cout << "\n";
	std::cout << BOLD_ON CYAN
			  << "===== COPY CONSTRUCTOR ====="
			  << BOLD_OFF << std::endl;

	ShrubberyCreationForm original("original");

	boss.signForm(original);

	std::cout << "\nOriginal:\n";
	std::cout << original << std::endl;

	ShrubberyCreationForm copy(original);

	std::cout << "\nCopy:\n";
	std::cout << copy << std::endl;


	/* ========================================================= */
	/*                    OPERATOR =                              */
	/* ========================================================= */

	std::cout << "\n";
	std::cout << BOLD_ON CYAN
			  << "===== OPERATOR = ====="
			  << BOLD_OFF << std::endl;

	ShrubberyCreationForm assigned("assigned");

	std::cout << "\nBefore assignment:\n";
	std::cout << assigned << std::endl;

	assigned = original;

	std::cout << "\nAfter assignment:\n";
	std::cout << assigned << std::endl;


	/* ========================================================= */

	std::cout << "\n";
	std::cout << BOLD_ON BLUE
			  << "========== END OF TEST =========="
			  << BOLD_OFF << std::endl;

	return (0);
}
