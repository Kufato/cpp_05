/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:29:09 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/02 10:31:33 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructor
Form::Form(void) : _signedGrade(150), _executeGrade(150), _name("default") {
	this->_signed = false;
	// std::cout << "Form constructor called" << std::endl;
	return ;
}

Form::Form(std::string name, int si_grade, int ex_grade) : _signedGrade(si_grade), _executeGrade(ex_grade), _name(name) {
	if (si_grade < 1 || ex_grade < 1)
		throw Form::GradeTooHighException();
	if (si_grade > 150 || ex_grade > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
	// std::cout << "Form set values constructor called" << std::endl;
	return ;
}

Form::Form(const Form &toCopy) : _signedGrade(toCopy.getSignedGrade()), _executeGrade(toCopy.getExecuteGrade()), _name(toCopy.getName()) {
	// std::cout << "Form copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

// Destructor
Form::~Form(void) {
	// std::cout << "Form destructor called" << std::endl;
	return ;
}

// Overload operator
Form	&Form::operator=(const Form &toCopy) {
	if (this == &toCopy)
		return (*this);
	this->_signed = toCopy.getSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &ostream, const Form &form) {
	std::cout << "Form :\t\t\t\t" << _GREEN << form.getName() << _END << std::endl;
	std::cout << "Grade required to sign it :\t" << _GREEN << form.getSignedGrade() << _END << std::endl;
	std::cout << "Grade required to execute it :\t" << _GREEN << form.getExecuteGrade() << _END << std::endl;
	std::cout << "Signed :\t\t\t" << _GREEN << form.getSigned() << _END << std::endl;
	return (ostream);
}

// Public method
void	Form::beSigned(Bureaucrat &bureaucrat) {
	if (this->_signed == true) {
		throw Form::FormAlreadySigned();
		return ;
	}
	if (bureaucrat.getGrade() <= this->getSignedGrade()) {
		this->_signed = true;
		return ;
	}
	throw Form::GradeTooLowException();
	return ;
}

// Getters
const bool	&Form::getSigned(void) const {
	return (this->_signed);
}

const int	&Form::getExecuteGrade(void) const {
	return (this->_executeGrade);
}

const int	&Form::getSignedGrade(void) const {
	return (this->_signedGrade);
}

const std::string	&Form::getName(void) const {
	return (this->_name);
}

// Excptions
const char	*Form::GradeTooHighException::what(void) const throw() {
	return ("The grade you entered is too high");
}

const char	*Form::GradeTooLowException::what(void) const throw() {
	return ("The grade you entered is too low");
}

const char	*Form::FormAlreadySigned::what(void) const throw() {
	return ("This form is already signed");
}