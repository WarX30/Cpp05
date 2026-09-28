#include "../include/Intern.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << BOLD_ON << "Intern default constructor called !" << BOLD_OFF << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << BOLD_ON YELLOW << "Intern copy constructor called !" << BOLD_OFF << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << BOLD_ON YELLOW << "Intern overloaded operator called !" << BOLD_OFF << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << BOLD_ON RED << "Intern destructor called !" << BOLD_OFF << std::endl;
}

static AForm *createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *createPresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*creates[3])(const std::string &);
		
	creates[0] = &createShrubbery;
	creates[1] = &createRobotomy;
	creates[2] = &createPresidential;

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates "
					  << BOLD_ON BLUE << formName << BOLD_OFF
					  << std::endl;
			return (creates[i](target));
		}
	}
	std::cerr << "Form '" << formName << "' not found" << std::endl;
	return (NULL);
}
