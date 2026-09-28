#pragma once

#include "../include/AForm.hpp"

class	Intern
{
	public:
	// constructor
		Intern();
		Intern(const Intern &other);
	
	// Overload operator
		Intern &operator=(const Intern &other);
	
	// Destructor
		~Intern();
	
	// Methode
		AForm *makeForm(std::string const &formName, std::string const &target);
};
