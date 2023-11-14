/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:56:05 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/02 11:22:31 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), _target(target) {
	// std::cout << "PresidentialPardonForm constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &toCopy) {
	// std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void) {
	// std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return ;
}

// Overload operator
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &toCopy) {
	if (this == &toCopy)
		return (*this);
	// nothing to copy, everything is constant
	return (*this);
}

// Public method
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const{
	if (this->_signed == false) {
		throw AForm::FormNotSigned();
		return ;
	}
	if (executor.getGrade() <= this->getExecuteGrade()) {
		std::cout << "Bureaucrat " << executor.getName() << ", you have been pardoned by Zaphod Beeblebrox" << std::endl;
		return ;
	}
	throw AForm::GradeTooLowException();
	return ;
}

// Getter
const std::string	&PresidentialPardonForm::getTarget(void) const {
	return (this->_target);
}