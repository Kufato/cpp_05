/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:27:53 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/14 18:48:30 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	{
		std::cout << _BLUE << "\n### TESTS FOR FORM CONSTRUCTOR ###\n" << _END << std::endl;
		try {
			Form	declaration_de_ressource_trimestrielle("declaration de ressource trimestrielle", -5, 69);
		}
		catch (Form::GradeTooHighException &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}

		try {
			Form	attestation_de_droit_a_l_image("attestation de droit a l'image", 285, 69);
		}
		catch (Form::GradeTooLowException &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}

		try {
			Form	avis_d_imposition("avis d'imposition", 18, -34);
		}
		catch (Form::GradeTooHighException &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}

		try {
			Form	releve_de_situation("releve de situation", 42, 8762);
		}
		catch (Form::GradeTooLowException &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
	}
	{
		std::cout << _BLUE << "\n### TESTS FOR FORM ###\n" << _END << std::endl;
		try {
			Form		demande_carte_d_identite("demande carte d'identite", 69, 78);
			Bureaucrat	Jonny_Mac_and_Cheese("Jonny_Mac_and_cheese", 67);

			std::cout << demande_carte_d_identite << std::endl; 
			Jonny_Mac_and_Cheese.signForm(demande_carte_d_identite);
		}
		catch (Form::GradeTooLowException &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
		
		try {
			Form		acte_de_naissance("acte de naissance", 4, 6);
			Bureaucrat	Stephane_Plaza	("Stephane Plaza", 12);

			std::cout << std::endl;
			std::cout << acte_de_naissance << std::endl;
			Stephane_Plaza.signForm(acte_de_naissance);
			std::cout << std::endl;
			std::cout << acte_de_naissance << std::endl;
			Stephane_Plaza.signForm(acte_de_naissance);
		}
		catch (Form::GradeTooLowException &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
	}
	return (0);
}