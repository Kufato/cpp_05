/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:29:13 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/14 18:47:53 by axcallet         ###   ########.fr       */
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
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm {
	
	protected:
		bool				_signed;
		const int			_signedGrade;
		const int			_executeGrade;
		const std::string	_name;

	public:
	// Constructors
		AForm(void);
		AForm(std::string name, int si_grade, int ex_grade);
		AForm(const AForm &toCopy);

	// Destructor
		virtual ~AForm(void);

	// Overload operator
		AForm	&operator=(const AForm &toCopy);

	// Public method
		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;

	// Getters
		const bool			&getSigned(void) const;
		const int			&getSignedGrade(void) const;
		const int			&getExecuteGrade(void) const;
		const std::string	&getName(void) const;

	// Exceptions
		class	GradeTooHighException : public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};

		class	FormAlreadySigned : public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};

		class	FormNotSigned : public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &ostream, const AForm &form);
