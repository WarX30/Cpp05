#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << BOLD_ON YELLOW << "PresidentialPardonForm constructor called" << BOLD_OFF << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << BOLD_ON YELLOW << "PresidentialPardonForm copy constructor called" << BOLD_OFF << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	std::cout << BOLD_ON YELLOW << "PresidentialPardonForm overloaded operator called" << BOLD_OFF << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BOLD_ON RED << "PresidentialPardonForm destructor called" << BOLD_OFF << std::endl;
}

const std::string	&PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw NotSignedException();

	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	
	std::cout << BOLD_ON << this->getTarget() << BOLD_OFF
			  << " has been pardoned by Zaphod Beeblebrox !"
			  << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &sh)
{
	out << BOLD_ON GREEN <<"[PPF_NAME 📄]: " << BOLD_OFF << sh.getName() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_SIGN]: " << BOLD_OFF <<sh.getGradeToSign() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_EXEC]: " << BOLD_OFF <<sh.getGradeToExecute() << std::endl;
	out << BOLD_ON GREEN << "[IS_SIGN]: " << BOLD_OFF << sh.getIsSigned() << std::endl;
	out << BOLD_ON GREEN << "[TARGET]: " << BOLD_OFF << sh.getTarget() << std::endl;
	
	return out;
}
