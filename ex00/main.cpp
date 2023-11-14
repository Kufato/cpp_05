/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:27:53 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/14 18:42:52 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	{
		std::cout << _BLUE << "### TESTS FOR CONSTRUCTOR ###\n" << _END << std::endl;
		try {
			Bureaucrat	jonh("jonh", -3);
		}
		catch(Bureaucrat::GradeTooHighException &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
		
		try {
			Bureaucrat	mick("mick", 151);
		}
		catch(Bureaucrat::GradeTooLowException &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
	}
	{
		std::cout << _BLUE << "\n### TESTS FOR INC/DEC GRADE ###\n" << _END << std::endl;
		try {
			Bureaucrat	bill("bill", 5);
			
			std::cout << bill << std::endl;
			bill.incGrade();
			std::cout << bill << std::endl;
			bill.incGrade();
			std::cout << bill << std::endl;
			bill.incGrade();
			std::cout << bill << std::endl;
			bill.incGrade();
			std::cout << bill << std::endl;
			bill.incGrade();
		}
		catch(Bureaucrat::GradeTooHighException &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
		try {
			Bureaucrat	bart("bart", 148);
			
			std::cout << bart << std::endl;
			bart.decGrade();
			std::cout << bart << std::endl;
			bart.decGrade();
			std::cout << bart << std::endl;
			bart.decGrade();
		}
		catch(Bureaucrat::GradeTooLowException &exep) {
			std::cerr << _RED << exep.what() << _END << std::endl;
		}
	}
	return (0);
}