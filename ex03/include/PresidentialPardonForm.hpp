#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
	// Constructors
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
	
	// Overload operator
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	
	// Destructor
		~PresidentialPardonForm();

	// Getter
		const std::string &getTarget() const;

	// Methods
		void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &sh);
