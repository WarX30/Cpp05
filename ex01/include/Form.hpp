#pragma once

#include "Bureaucrat.hpp"
#include <exception>

class Form
{
	private:
		const std::string _name;
		bool			  _isSigned;
		const int		  _gradeToSign;
		const int		  _gradeToExecute;
	
	public:
	// Constructor
		Form();
		Form(const std::string name, const int sign_lvl, const int execute_lvl);
		Form(const Form &other);

	// Overload operator
		Form &operator=(const Form &other);

	//Destructeur
		~Form();

	//Getters
		const std::string &getName(void) const;
		const int	&getGradeToSign(void) const;
		const bool	&getIsSigned(void) const;
		const int	&getGradeToExecute(void) const;
	
	// Method
		void	beSigned(const Bureaucrat &b);

	// Exception 
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Form &f);
