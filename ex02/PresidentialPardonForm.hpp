/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:56:10 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/01 14:59:37 by axcallet         ###   ########.fr       */
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

class	PresidentialPardonForm : public AForm {
	
	private:
		const std::string	_target;

	public:
	// Constructors
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &toCopy);

	// Destructor
		~PresidentialPardonForm(void);

	// Overload operator
		PresidentialPardonForm &operator = (const PresidentialPardonForm &toCopy);

	// Public method
		void	execute(const Bureaucrat &executor) const;

	// Getter
		const std::string	&getTarget(void) const;
};
