#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include <exception>

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150)
{
	std::cout << BOLD_ON << "Bureaucrat default constructor called" << BOLD_OFF << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	if (_grade < HIGH_GRADE)
		throw GradeTooHighException();
	if (_grade > LOW_GRADE)
		throw GradeTooLowException();
	std::cout << BOLD_ON YELLOW << "Bureaucrat custom constructor called" << BOLD_OFF << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other.getGrade())
{
	std::cout << BOLD_ON YELLOW << "Bureaucrat custom constructor called" << BOLD_OFF << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other.getGrade();
	std::cout << BOLD_ON YELLOW << "Bureaucrat overloaded operator called" << BOLD_OFF << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BOLD_ON RED << "Bureaucrat destructor called" << BOLD_OFF << std::endl;
}

const std::string &Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(int value)
{
	int	new_grade;

	new_grade = this->getGrade() - value;
	if (new_grade < HIGH_GRADE)
		throw GradeTooHighException();
	else
	{
		this->_grade -= value;
		std::cout << BOLD_ON GREEN << "You Lvl Up !!!" << BOLD_OFF << std::endl;
	}
}

void	Bureaucrat::decrementGrade(int value)
{
	int	new_grade;

	new_grade = this->getGrade() + value;
	if (new_grade > LOW_GRADE)
		throw GradeTooLowException();
	else
	{
		this->_grade += value;
		std::cout << BOLD_ON GREEN << "You Lvl Down !!!" << BOLD_OFF << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
	out << BOLD_ON BLUE << other.getName() << BOLD_OFF
		<< ", bureaucrat grade "
		<< BOLD_ON CYAN << other.getGrade() << BOLD_OFF 
		<< "." << std::endl;
	return out;
}

void	Bureaucrat::signFrom(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << BOLD_ON BLUE << this->getName() << BOLD_OFF
				  << " signed " << BOLD_ON CYAN << f.getName() << BOLD_OFF
				  << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BOLD_ON BLUE << this->getName() << BOLD_OFF
				  << " couldn't sign " << BOLD_ON CYAN << f.getName() << BOLD_OFF
				  << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\033[1m\033[36mBureaucrat grade too high !\033[0m");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\033[1m\033[36mBureaucrat grade too low !\033[0m");
}
