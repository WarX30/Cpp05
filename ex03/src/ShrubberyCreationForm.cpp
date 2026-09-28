#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << BOLD_ON YELLOW << "ShrubberyCreationForm constructor called" << BOLD_OFF << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << BOLD_ON YELLOW << "ShrubberyCreationForm copy constructor called" << BOLD_OFF << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	std::cout << BOLD_ON YELLOW << "ShrubberyCreationForm overloaded operator called" << BOLD_OFF << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BOLD_ON RED << "ShrubberyCreationForm destructor called" << BOLD_OFF << std::endl;
}

const std::string	&ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();

	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();

	std::string file_name;
	
	if (this->getTarget().empty())
		file_name = "default_shrubbery";
	else
		file_name = this->getTarget() + "_shrubbery";
	
	std::ofstream	file(file_name.c_str());
	
	if (!file.is_open())
		throw std::runtime_error("Could not open Shrubbery file");
	file << "       *\n";
	file << "      ***\n";
	file << "     *****\n";
	file << "    *******\n";
	file << "   *********\n";
	file << "  ***********\n";
	file << " *************\n";
	file << "***************\n";
	file << "     |===|\n";
	file << "     |===|\n";
	file << "     |===|\n";
	file << "    =======\n";
	file.close();
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &sh)
{
	out << BOLD_ON GREEN <<"[SCF_NAME 📄]: " << BOLD_OFF << sh.getName() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_SIGN]: " << BOLD_OFF <<sh.getGradeToSign() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_EXEC]: " << BOLD_OFF <<sh.getGradeToExecute() << std::endl;
	out << BOLD_ON GREEN << "[IS_SIGN]: " << BOLD_OFF << sh.getIsSigned() << std::endl;
	out << BOLD_ON GREEN << "[TARGET]: " << BOLD_OFF << sh.getTarget() << std::endl;
	
	return out;
}
