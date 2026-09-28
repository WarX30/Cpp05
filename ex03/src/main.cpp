#include "../include/Intern.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#define SECTION "\033[1;35m"
#define RESET "\033[0m"
#define GREEN1 "\033[1;32m"
#define RED1 "\033[1;31m"
#define BLUE1 "\033[1;34m"
#define CYAN1 "\033[1;36m"
#define BOLD "\033[1m"

static void printSection(const std::string &title)
{
	std::cout << std::endl;
	std::cout << SECTION
			  << "========================================"
			  << RESET << std::endl;
	std::cout << SECTION << title << RESET << std::endl;
	std::cout << SECTION
			  << "========================================"
			  << RESET << std::endl;
}

int	main(void)
{
	std::srand(std::time(NULL));

	Intern		intern;
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	middle("Middle", 50);
	Bureaucrat	junior("Junio", 150);

	AForm		*form;

	printSection("TEST 1 - Shrubbery Creation");

	form = intern.makeForm("shrubbery creation", "Garden");
	if (form != NULL)
	{
		std::cout << BOLD << "Created form: " << RESET
				  << *form << std::endl;
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	printSection("TEST 2 -  Robotomy Request");

	form = intern.makeForm("robotomy request", "Bender");
	if (form != NULL)
	{
		std::cout << BOLD << "Created form: " << RESET
				  << *form << std::endl;
		middle.signForm(*form);
		middle.incrementGrade(25);
		for (int i = 0; i < 5; i++)
		{
			std::cout << CYAN1 << "Attempt " << i + 1
					  << RESET << std::endl;
			middle.executeForm(*form);
		}
		middle.decrementGrade(25);
		delete form;
	}

	printSection("TEST 3 - Presidential Pardon");

	form = intern.makeForm("presidential pardon", "Arthur");
	if (form != NULL)
	{
		std::cout << BOLD << "Created form: " << RESET
				  << *form << std::endl;
		middle.signForm(*form);
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	printSection("TEST 4 - Unknow Form");

	form = intern.makeForm("Unknow Form", "Nobody");
	if (form == NULL)
	{
		std::cout << GREEN1
				  << "Unknow form correctly rejected." << RESET
				  << RESET << std::endl;
	}
	else
	{
		std::cout << RED1
				  << "ERROR: unknow form was created." << RESET
				  << RESET << std::endl;
		delete form;
	}

	printSection("TEST 5 - Insufficient Grade");

	form = intern.makeForm("shrubbery creation", "Forbidden");
	if (form != NULL)
	{
		junior.signForm(*form);
		junior.executeForm(*form);

		junior.incrementGrade(149);
		std::cout << junior << std::endl;

		junior.signForm(*form);
		junior.executeForm(*form);
		
		junior.decrementGrade(149);
		delete form;
	}

	printSection("TEST 6 - Multiple Dynamic Forms");
	
	std::string formName[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	std::string target[3] = {
		"House",
		"Robot",
		"Prisoner"
	};

	AForm *forms[3];

	for (int i = 0; i < 3; i++)
	{
		forms[i] = intern.makeForm(formName[i], target[i]);
		if (forms[i] != NULL)
		{
			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]);
		}
	}
	for (int i = 0; i < 3; i++)
		delete forms[i];

	std::cout << std::endl;
	std::cout << GREEN
			  << "All tests completed."
			  << RESET << std::endl;
	return (0);
}
