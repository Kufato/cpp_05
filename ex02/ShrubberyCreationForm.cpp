/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:34:22 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/02 11:22:34 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target) {
	// std::cout << "ShrubberyCreationForm set target constructor called" << std::endl;
	return ;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy) : AForm(toCopy), _target(toCopy._target) {
	// std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	// std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return ;
}

// Overload operator
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &toCopy) {
	if (this == &toCopy)
		return (*this);
	// nothing to copy, everything is constant
	return (*this);
}

// Public method
void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->_signed == false) {
		throw AForm::FormNotSigned();
		return ;
	}
	if (executor.getGrade() <= this->getExecuteGrade()) {
		std::string		file_name;
		std::ofstream	outfile;

		file_name = this->getTarget().c_str();
		outfile.open(file_name.append("_shrubbery").c_str());
		if (!outfile.is_open()) {
			std::cerr << _RED << "Error: Could not open the file" << _END << std::endl;
			return ;
		}
		outfile << "             /\\" << std::endl;
		outfile << "            <  >" << std::endl;
		outfile << "             \\/" << std::endl;
		outfile << "             /\\" << std::endl;
		outfile << "            /  \\" << std::endl;
		outfile << "           /++++\\" << std::endl;
		outfile << "          /  ()  \\" << std::endl;
		outfile << "          /      \\" << std::endl;
		outfile << "         /~`~`~`~`\\" << std::endl;
		outfile << "        /  ()  ()  \\" << std::endl;
		outfile << "        /          \\" << std::endl;
		outfile << "       /            \\" << std::endl;
		outfile << "      /  ()  ()  ()  \\" << std::endl;
		outfile << "      /              \\" << std::endl;
		outfile << "     /++++++++++++++++\\" << std::endl;
		outfile << "    /  ()  ()  ()  ()  \\" << std::endl;
		outfile << "    /                  \\" << std::endl;
		outfile << "   /~`~`~`~`~`~`~`~`~`~`\\" << std::endl;
		outfile << "  /  ()  ()  ()  ()  ()  \\" << std::endl;
		outfile << "  /                      \\" << std::endl;
		outfile << " /########################\\" << std::endl;
		outfile << "/,.,.,.,.,.,.,.,.,.,.,.,.,.\\" << std::endl;
		outfile << "           |   |" << std::endl;
		outfile << "          |`````|" << std::endl;
		outfile << "          \\_____/" << std::endl;
		outfile << std::endl;
		outfile << std::endl;
		outfile << "             /\\" << std::endl;
		outfile << "            <  >" << std::endl;
		outfile << "             \\/" << std::endl;
		outfile << "             /\\" << std::endl;
		outfile << "            /  \\" << std::endl;
		outfile << "           /++++\\" << std::endl;
		outfile << "          /  ()  \\" << std::endl;
		outfile << "          /      \\" << std::endl;
		outfile << "         /~`~`~`~`\\" << std::endl;
		outfile << "        /  ()  ()  \\" << std::endl;
		outfile << "        /          \\" << std::endl;
		outfile << "       /            \\" << std::endl;
		outfile << "      /  ()  ()  ()  \\" << std::endl;
		outfile << "      /              \\" << std::endl;
		outfile << "     /++++++++++++++++\\" << std::endl;
		outfile << "    /  ()  ()  ()  ()  \\" << std::endl;
		outfile << "    /                  \\" << std::endl;
		outfile << "   /~`~`~`~`~`~`~`~`~`~`\\" << std::endl;
		outfile << "  /  ()  ()  ()  ()  ()  \\" << std::endl;
		outfile << "  /                      \\" << std::endl;
		outfile << " /########################\\" << std::endl;
		outfile << "/,.,.,.,.,.,.,.,.,.,.,.,.,.\\" << std::endl;
		outfile << "           |   |" << std::endl;
		outfile << "          |`````|" << std::endl;
		outfile << "          \\_____/" << std::endl;
		outfile.close();
		return ;
	}
	throw AForm::GradeTooLowException();
	return ;
}

// Getter
const std::string	&ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}