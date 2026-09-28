#pragma once

#include "Bureaucrat.hpp"
#include <exception>

class AForm
{
	private:
		const std::string _name;
		const int		  _gradeToSign;
		const int		  _gradeToExecute;
		bool			  _isSigned;
	
	public:
	// Constructor
		AForm();
		AForm(const std::string &name, int sign_grade, int execute_grade);
		AForm(const AForm &other);

	// Overload operator
		AForm &operator=(const AForm &other);

	//Destructeur
		virtual ~AForm();

	//Getters
		const std::string &getName(void) const;
		int				  getGradeToSign(void) const;
		int				  getGradeToExecute(void) const;
		bool			  getIsSigned(void) const;
	
	// Method
		void	beSigned(const Bureaucrat &b);
	
		virtual void execute(Bureaucrat const &executor) const = 0;

	// Exception 
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &f);
