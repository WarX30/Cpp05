#include "../include/AForm.hpp"

AForm::AForm()
	: _name("default"), _gradeToSign(1), _gradeToExecute(1), _isSigned(false)
{
	std::cout << BOLD_ON << "AForm Default constructor called" << BOLD_OFF << std::endl;
}

AForm::AForm(const std::string &name, int sign_grade, int execute_grade)
	: _name(name), _gradeToSign(sign_grade), _gradeToExecute(execute_grade), _isSigned(false)
{
	if (_gradeToSign < HIGH_GRADE || _gradeToExecute < HIGH_GRADE)
		throw GradeTooHighException();
	if (_gradeToSign > LOW_GRADE || _gradeToExecute > LOW_GRADE)
		throw GradeTooLowException();
	std::cout << BOLD_ON YELLOW << "AForm custom constructor called" << BOLD_OFF << std::endl;
}

AForm::AForm(const AForm &other)
	: _name(other.getName()) , _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute()), _isSigned(other.getIsSigned())
{
	std::cout << BOLD_ON YELLOW << "AForm custom constructor called" << BOLD_OFF << std::endl;
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_isSigned = other.getIsSigned();
	std::cout << BOLD_ON YELLOW << "AForm overloaded operator called" << BOLD_OFF << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << BOLD_ON RED << "AForm destructor called" << BOLD_OFF << std::endl;
}

const std::string &AForm::getName(void) const
{
	return (this->_name);
}

int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

bool AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if ((int)b.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << BOLD_ON GREEN <<"[AFORM_NAME 📄]: " << BOLD_OFF << f.getName() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_SIGN]: " << BOLD_OFF <<f.getGradeToSign() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_EXEC]: " << BOLD_OFF <<f.getGradeToExecute() << std::endl;
	out << BOLD_ON GREEN << "[IS_SIGN]: " << BOLD_OFF << f.getIsSigned() << std::endl;
	
	return out;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("\033[1m\033[36mAForm 📄 grade too high !\033[0m");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("\033[1m\033[36mAForm 📄 grade too low !\033[0m");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("\033[1m\033[36mAForm 📄 is not signed !\033[0m");
}
