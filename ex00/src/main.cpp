#include "../include/Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	std::cout << "===== VALID CONSTRUCTION =====" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 42);
		std::cout << bob << std::endl;

		std::cout << "\n===== INCREMENT GRADE =====" << std::endl;
		bob.incrementGrade(5);
		std::cout << bob << std::endl;

		std::cout << "\n===== DECREMENT GRADE =====" << std::endl;
		bob.decrementGrade(10);
		std::cout << bob << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== INVALID CONSTRUCTION: GRADE 0 =====" << std::endl;
	try
	{
		Bureaucrat high("High", 0);
		std::cout << high << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== INVALID CONSTRUCTION: GRADE 151 =====" << std::endl;
	try
	{
		Bureaucrat low("Low", 151);
		std::cout << low << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== INCREMENT ABOVE LIMIT =====" << std::endl;
	try
	{
		Bureaucrat top("Top", 5);
		std::cout << top << std::endl;
		top.incrementGrade(5);
		std::cout << top << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== DECREMENT BELOW LIMIT =====" << std::endl;
	try
	{
		Bureaucrat bottom("Bottom", 145);
		std::cout << bottom << std::endl;
		bottom.decrementGrade(5);
		std::cout << bottom << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== COPY CONSTRUCTOR =====" << std::endl;
	Bureaucrat original("Original", 150);
	Bureaucrat copy(original);

	std::cout << "Original: " << original << std::endl;
	std::cout << "Copy:     " << copy << std::endl;

	/*try
	{
		std::cout << "\n===== COPY CONSTRUCTOR =====" << std::endl;
		Bureaucrat original("Original", 250);
		Bureaucrat copy(original);

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}*/
	return 0;
}
