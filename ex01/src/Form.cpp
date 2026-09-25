#include "../include/Form.hpp"

Form::Form()
	: _name("default"), _gradeToSign(1), _gradeToExecute(1), _isSigned(false)
{
	std::cout << BOLD_ON << "Form Default constructor called" << BOLD_OFF << std::endl;
}

Form::Form(const std::string &name, int sign_grade, int execute_grade)
	: _name(name), _gradeToSign(sign_grade), _gradeToExecute(execute_grade), _isSigned(false)
{
	if (_gradeToSign < HIGH_GRADE || _gradeToExecute < HIGH_GRADE)
		throw GradeTooHighException();
	if (_gradeToSign > LOW_GRADE || _gradeToExecute > LOW_GRADE)
		throw GradeTooLowException();
	std::cout << BOLD_ON YELLOW << "Form custom constructor called" << BOLD_OFF << std::endl;
}

Form::Form(const Form &other)
	: _name(other.getName()) , _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute()), _isSigned(other.getIsSigned())
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

int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

bool Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if ((int)b.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << BOLD_ON GREEN <<"[FORM_NAME 📄]: " << BOLD_OFF << f.getName() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_SIGN]: " << BOLD_OFF <<f.getGradeToSign() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_EXEC]: " << BOLD_OFF <<f.getGradeToExecute() << std::endl;
	out << BOLD_ON GREEN << "[IS_SIGN]: " << BOLD_OFF << f.getIsSigned() << std::endl;
	
	return out;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("\033[1m\033[36mForm 📄 grade too high !\033[0m");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("\033[1m\033[36mForm 📄 grade too low !\033[0m");
}
