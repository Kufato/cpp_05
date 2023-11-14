/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:53:36 by axcallet          #+#    #+#             */
/*   Updated: 2023/10/31 10:40:21 by axcallet         ###   ########.fr       */
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

class	Bureaucrat {
	
	private:
		const std::string	_name;
		int					_grade;

	public:
	// Constructors
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &toCopy);

	// Destructor
		~Bureaucrat(void);

	// Overload operator
		Bureaucrat &operator=(const Bureaucrat &toCopy);

	// Public methods
		void	incGrade(void);
		void	decGrade(void);

	// Getters
		const std::string	getName(void) const;
		int					getGrade(void) const;

	// Exeptions
		class	GradeTooHighException : public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);