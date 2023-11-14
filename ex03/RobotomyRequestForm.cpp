/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:15:58 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/02 11:22:17 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target) {
	// std::cout << "RobotomyRequestForm constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &toCopy) {
	// std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void) {
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return ;
}

// Overload operator
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &toCopy) {
	if (this == &toCopy)
		return (*this);
	// nothing to copy, everything is constant
	return (*this);
}

// Public method
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const{
	if (this->_signed == false) {
		throw AForm::FormNotSigned();
		return ;
	}
	if (executor.getGrade() <= this->getExecuteGrade()) {
		std::srand(std::time(0));
		int	rand = std::rand();
		int	delay = 1000000;

		std::cout << "* Some drilling noises *" << std::endl;
		usleep(delay);
		std::cout << "* More drilling noises *" << std::endl;
		usleep(delay);
		std::cout << "* A lot of drilling noises *" << std::endl;
		usleep(delay);
		usleep(delay);
		if (rand % 2 == 0)
			std::cout << _GREEN << "Bureaucrat " << executor.getName() << ", you have been robotomized" << _END << std::endl;
		else
			std::cout << _RED << "The robotimization was not successful" << _END << std::endl;
		return ;
	}
	throw AForm::GradeTooLowException();
	return ;
}

// Getter
const std::string	&RobotomyRequestForm::getTarget(void) const {
	return (this->_target);
}