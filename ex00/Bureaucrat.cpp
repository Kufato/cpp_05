/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:53:32 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/14 18:43:14 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat(void) : _name("default") {
	this->_grade = 0;
	// std::cout << "Bureaucrat constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	// std::cout << "Bureaucrat set name and grade constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy) : _name(toCopy.getName()) {
	*this = toCopy;
	// std::cout << "Bureaucrat copy constructor called" << std::endl;
	return ;
}

// Destructor
Bureaucrat::~Bureaucrat(void) {
	// std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

// Overload operator
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &toCopy) {
	if (this == &toCopy)
		return (*this);
	this->_grade = toCopy.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat) {
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (ostream);
}

// Public methods
void	Bureaucrat::decGrade(void) {
	if ((this->_grade + 1) > 150) {
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	this->_grade++;
	return ;
}

void	Bureaucrat::incGrade(void) {
	if ((this->_grade - 1) < 1) {
		throw Bureaucrat::GradeTooHighException();
		return ;
	}
	this->_grade--;
	return ;
}

// Getters
const std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

// Exceptions
const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("The grade you entered is too high");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("The grade you entered is too low");
}

