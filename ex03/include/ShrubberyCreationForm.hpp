#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
	// Constructors
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
	
	// Overload operator
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	
	// Destructor
		~ShrubberyCreationForm();

	// Getter
		const std::string &getTarget() const;

	// Methods
		void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &sh);
