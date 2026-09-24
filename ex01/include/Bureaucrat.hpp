#pragma	once

#include <iostream>
#include <exception>
#include <ostream>
#include <string>

#define HIGH_GRADE 1
#define LOW_GRADE	150

#define BOLD_ON "\033[1m"
#define BOLD_OFF "\033[0m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

class Form;

class	Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	
	public:
	// Constructor
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
	
	// Overload operator
		Bureaucrat	&operator=(const Bureaucrat &other);
	
	// Destructor
		~Bureaucrat();

	// Getters
		const std::string &getName(void) const;
		unsigned int	getGrade(void) const;

	// Methods
		void	incrementGrade(int value);
		void	decrementGrade(int value);
		
		void	signFrom(const Form &f);
	
	// Exception
		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);
