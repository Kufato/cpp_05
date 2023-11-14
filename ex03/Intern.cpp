/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:15:26 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/02 15:47:42 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Constructor
Intern::Intern(void) {
	// std::cout << "Intern constructor called" << std::endl;
	return ;
}

Intern::Intern(const Intern &toCopy) {
	// std::cout << "Intern copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

// Destructor
Intern::~Intern(void) {
	// std::cout << "Intern destructor called" << std::endl;
	return ;
}

// Overload operator
Intern	&Intern::operator=(const Intern &toCopy) {
	if (this == &toCopy)
		return (*this);
	// nothing to copy
	return (*this);
}

// Public method
AForm	*Intern::makeForm(std::string form, std::string target) {
	size_t 		i = 0;
	std::string	formTab[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	
	while (i < 3 && form != formTab[i])
		i++;
	switch (i) {
		case 0:
			std::cout << "Intern creates " << form << _END << std::endl;
			return (new ShrubberyCreationForm(target));
			break ;
		case 1:
			std::cout << "Intern creates " << form << _END << std::endl;
			return (new RobotomyRequestForm(target));
			break ;
		case 2:
			std::cout << "Intern creates " << form << _END << std::endl;
			return (new PresidentialPardonForm(target));
			break ;
		default:
			throw Intern::WrongNameException();
			break ;
	}
	return (NULL);
}

// Exception
const char	*Intern::WrongNameException::what(void) const throw() {
	return ("The form name is wrong");
}