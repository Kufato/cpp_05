/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:27:53 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/02 11:31:09 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	{
		std::cout << _BLUE << "\n### TESTS FOR SHRUBBERY_CREATION_FORM ###\n" << _END << std::endl;
		try {
			Bureaucrat				tom("tom", 138);
			ShrubberyCreationForm	form("tom");

			tom.executeForm(form);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
		std::cout << std::endl;
		try {
			Bureaucrat				jake("jake", 138);
			ShrubberyCreationForm	form("jake");

			jake.signForm(form);
			jake.executeForm(form);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
		std::cout << std::endl;
		try {
			Bureaucrat				mike("mike", 138);
			ShrubberyCreationForm	form("mike");

			mike.signForm(form);
			mike.decGrade();
			mike.executeForm(form);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
	}
	{
		std::cout << _BLUE << "\n### TESTS FOR ROBOTOMY_REQUEST_FORM ###\n" << _END << std::endl;
		try {
			Bureaucrat			moise("moise", 47);
			RobotomyRequestForm	form("moise");

			moise.executeForm(form);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
		std::cout << std::endl;
		try {
			Bureaucrat			ben("ben", 47);
			RobotomyRequestForm	form("ben");

			ben.signForm(form);
			ben.decGrade();
			ben.executeForm(form);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
		std::cout << std::endl;
		try {
			Bureaucrat			josh("josh", 47);
			RobotomyRequestForm	form("josh");

			josh.signForm(form);
			josh.decGrade();
			josh.decGrade();
			josh.executeForm(form);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
	}
	{
		std::cout << _BLUE << "\n### TESTS FOR PRESIDENTIAL_PARDON_FORM ###\n" << _END << std::endl;
		try {
			Bureaucrat				gunther("gunther", 8);
			PresidentialPardonForm	form("gunther");

			gunther.executeForm(form);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
		std::cout << std::endl;
		try {
			Bureaucrat				max("max", 8);
			PresidentialPardonForm	form("max");

			max.signForm(form);
			max.decGrade();
			max.executeForm(form);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
		std::cout << std::endl;
		try {
			Bureaucrat				rub("rub", 8);
			PresidentialPardonForm	form("rub");

			rub.signForm(form);
			rub.decGrade();
			rub.decGrade();
			rub.decGrade();
			rub.executeForm(form);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
	}
	std::cout << std::endl;
	return (0);
}