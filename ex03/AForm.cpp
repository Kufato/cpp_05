/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:29:09 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/02 10:31:42 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructor
AForm::AForm(void) : _signedGrade(150), _executeGrade(150), _name("default") {
	this->_signed = false;
	// std::cout << "AForm constructor called" << std::endl;
	return ;
}

AForm::AForm(std::string name, int si_grade, int ex_grade) : _signedGrade(si_grade), _executeGrade(ex_grade), _name(name) {
	if (si_grade < 1 || ex_grade < 1)
		throw AForm::GradeTooHighException();
	if (si_grade > 150 || ex_grade > 150)
		throw AForm::GradeTooLowException();
	this->_signed = false;
	// std::cout << "AForm set values constructor called" << std::endl;
	return ;
}

AForm::AForm(const AForm &toCopy) : _signedGrade(toCopy.getSignedGrade()), _executeGrade(toCopy.getExecuteGrade()), _name(toCopy.getName()) {
	// std::cout << "AForm copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

// Destructor
AForm::~AForm(void) {
	// std::cout << "AForm destructor called" << std::endl;
	return ;
}

// Overload operator
AForm	&AForm::operator=(const AForm &toCopy) {
	if (this == &toCopy)
		return (*this);
	this->_signed = toCopy.getSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &ostream, const AForm &aform) {
	std::cout << "Form :\t\t\t\t" << _GREEN << aform.getName() << _END << std::endl;
	std::cout << "Grade required to sign it :\t" << _GREEN << aform.getSignedGrade() << _END << std::endl;
	std::cout << "Grade required to execute it :\t" << _GREEN << aform.getExecuteGrade() << _END << std::endl;
	std::cout << "Signed :\t\t\t" << _GREEN << aform.getSigned() << _END << std::endl;
	return (ostream);
}

// Public method
void	AForm::beSigned(Bureaucrat &bureaucrat) {
	if (this->_signed == true) {
		throw AForm::FormAlreadySigned();
		return ;
	}
	if (bureaucrat.getGrade() <= this->getSignedGrade()) {
		this->_signed = true;
		return ;
	}
	throw AForm::GradeTooLowException();
	return ;
}

// Getters
const bool	&AForm::getSigned(void) const {
	return (this->_signed);
}

const int	&AForm::getExecuteGrade(void) const {
	return (this->_executeGrade);
}

const int	&AForm::getSignedGrade(void) const {
	return (this->_signedGrade);
}

const std::string	&AForm::getName(void) const {
	return (this->_name);
}

// Excptions
const char	*AForm::GradeTooHighException::what(void) const throw() {
	return ("The grade you entered is too high");
}

const char	*AForm::GradeTooLowException::what(void) const throw() {
	return ("The grade you entered is too low");
}

const char	*AForm::FormAlreadySigned::what(void) const throw() {
	return ("This form is already signed");
}

const char	*AForm::FormNotSigned::what(void) const throw() {
	return ("This form is not signed");
}