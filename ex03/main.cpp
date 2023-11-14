/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:27:53 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/14 18:49:41 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	{
		std::cout << _BLUE << "\n### TESTS FOR INTERN CREATION OF SHRUBBERY_CREATION_FORM ###\n" << _END << std::endl;
		try {
			Intern		intern;
			AForm		*formulair_d_hadesion = intern.makeForm("ShrubberyCreationForm", "gab");
			Bureaucrat	ben("ben", 4);

			ben.signForm(*formulair_d_hadesion);
			ben.executeForm(*formulair_d_hadesion);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << "You can't create this form because " << exep.what() << _END << std::endl;
		}
	}
	{
		std::cout << _BLUE << "\n### TESTS FOR INTERN CREATION OF ROBOTOMY_REQUEST_FORM ###\n" << _END << std::endl;
		try {
			Intern		intern;
			AForm		*lettre_de_motivation = intern.makeForm("RobotomyRequestForm", "mat");
			Bureaucrat	mat("mat", 8);

			mat.signForm(*lettre_de_motivation);
			mat.executeForm(*lettre_de_motivation);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << "You can't create this form because " << exep.what() << _END << std::endl;
		}
	}
	{
		std::cout << _BLUE << "\n### TESTS FOR INTERN CREATION OF PRESIDENTIAL_PARDON_FORM ###\n" << _END << std::endl;
		try {
			Intern		intern;
			AForm		*releve_de_situation = intern.makeForm("PresidentialPardonForm", "pix");
			Bureaucrat	tim("tim", 2);

			tim.signForm(*releve_de_situation);
			tim.executeForm(*releve_de_situation);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << "You can't create this form because " << exep.what() << _END << std::endl;
		}
	}
	{
		std::cout << _BLUE << "\n### TESTS FOR ERRORS ###\n" << _END << std::endl;
		try {
			Intern		intern;
			AForm		*bulletin_de_salaire = intern.makeForm("TrucDeOuf", "il n'existe pas");
			Bureaucrat	dom("dom", 1);

			dom.signForm(*bulletin_de_salaire);
			dom.executeForm(*bulletin_de_salaire);
		}
		catch (std::exception &exep) {
			std::cerr << _RED << "You can't create this form because " << exep.what() << _END << std::endl;
		}
	}
	std::cout << std::endl;
	return (0);
}