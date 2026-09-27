#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << BOLD_ON YELLOW << "RobotomyRequestForm constructor called" << BOLD_OFF << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << BOLD_ON YELLOW << "RobotomyRequestForm copy constructor called" << BOLD_OFF << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	std::cout << BOLD_ON YELLOW << "RobotomyRequestForm overloaded operator called" << BOLD_OFF << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BOLD_ON RED << "RobotomyRequestForm destructor called" << BOLD_OFF << std::endl;
}

const std::string	&RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
	{
		std::cout << BOLD_ON CYAN << "BRRRRRRR! The robotomy failed" << BOLD_OFF << std::endl;
		throw NotSignedException();
	}

	if (executor.getGrade() > this->getGradeToExecute())
	{
		std::cout << BOLD_ON CYAN << "BRRRRRRR! The robotomy failed" << BOLD_OFF << std::endl;
		throw GradeTooLowException();
	}
	
	if (std::rand() % 2 == 0)
	{
		std::cout << "YOUPPIIII! " << BOLD_ON << this->getTarget() << BOLD_OFF
			  << " has been robotomized successfuly !" << std::endl;
	}
	else {
		std::cout << BOLD_ON CYAN << "BRRRRRRR! The robotomy failed" << BOLD_OFF << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &sh)
{
	out << BOLD_ON GREEN <<"[RBF_NAME 📄]: " << BOLD_OFF << sh.getName() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_SIGN]: " << BOLD_OFF <<sh.getGradeToSign() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_EXEC]: " << BOLD_OFF <<sh.getGradeToExecute() << std::endl;
	out << BOLD_ON GREEN << "[IS_SIGN]: " << BOLD_OFF << sh.getIsSigned() << std::endl;
	out << BOLD_ON GREEN << "[TARGET]: " << BOLD_OFF << sh.getTarget() << std::endl;
	
	return out;
}
