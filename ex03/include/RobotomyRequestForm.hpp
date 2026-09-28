#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
	// Constructors
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
	
	// Overload operator
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	
	// Destructor
		~RobotomyRequestForm();

	// Getter
		const std::string &getTarget() const;

	// Methods
		void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &sh);

