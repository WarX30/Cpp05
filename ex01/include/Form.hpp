#pragma once

#include "Bureaucrat.hpp"
#include <exception>

class Form
{
	private:
		const std::string _name;
		const int		  _gradeToSign;
		const int		  _gradeToExecute;
		bool			  _isSigned;
	
	public:
	// Constructor
		Form();
		Form(const std::string &name, int sign_grade, int execute_grade);
		Form(const Form &other);

	// Overload operator
		Form &operator=(const Form &other);

	//Destructeur
		~Form();

	//Getters
		const std::string &getName(void) const;
		int				  getGradeToSign(void) const;
		int				  getGradeToExecute(void) const;
		bool			  getIsSigned(void) const;
	
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
