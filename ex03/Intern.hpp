/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:15:31 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/02 14:02:30 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define _END		"\033[0m"
#define _BLACK		"\033[0;30m"
#define _RED		"\033[0;31m"
#define _GREEN		"\033[0;32m"
#define _YELLOW		"\033[0;33m"
#define _BLUE		"\033[0;34m"
#define _PURPLE		"\033[0;35m"
#define _CYAN		"\033[0;36m"

#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern {
	
	private:

	public:
	// Constructors
		Intern(void);
		Intern(const Intern &toCopy);

	// Destructor
		~Intern(void);

	// Overload operator
		Intern &operator=(const Intern &toCopy);

	// Public method
		AForm	*makeForm(std::string form, std::string target);

	// Exceptions
		class	WrongNameException : public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
};