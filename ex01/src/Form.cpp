#include "../include/Form.hpp"

Form::Form()
	: _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << BOLD_ON << "Form Default constructor called" << BOLD_OFF << std::endl;
}

Form::Form(const std::string name, const int sign_lvl, const int execute_lvl)
	: _name(name), _isSigned(false), _gradeToSign(sign_lvl), _gradeToExecute(execute_lvl)
{
	if (_gradeToSign < HIGH_GRADE || _gradeToExecute < HIGH_GRADE)
		throw GradeTooHighException();
	if (_gradeToSign > LOW_GRADE || _gradeToExecute > LOW_GRADE)
		throw GradeTooLowException();
	std::cout << BOLD_ON YELLOW << "Form custom constructor called" << BOLD_OFF << std::endl;
}

Form::Form(const Form &other)
	: _name(other.getName()), _isSigned(other.getIsSigned()) , _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute())
{
	std::cout << BOLD_ON YELLOW << "Form custom constructor called" << BOLD_OFF << std::endl;
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		this->_isSigned = other.getIsSigned();
	std::cout << BOLD_ON YELLOW << "Form overloaded operator called" << BOLD_OFF << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << BOLD_ON RED << "Form destructor called" << BOLD_OFF << std::endl;
}

const std::string &Form::getName(void) const
{
	return (this->_name);
}

const int &Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

const bool &Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

const int &Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat &b)
{
	
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << BOLD_ON GREEN <<"[FORM_NAME 📄]: " << BOLD_OFF << f.getName() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_EXEC]: " << BOLD_OFF <<f.getGradeToExecute() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_SIGN]: " << BOLD_OFF <<f.getGradeToSign() << std::endl;
	out << BOLD_ON GREEN << "[IS_SIGN]: " << BOLD_OFF << f.getIsSigned() << std::endl;
	
	return out;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("\033[1m\033[36mForm grade too hight !\033[0m");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("\033[1m\033[36mForm grade too low !\033[0m");
}
