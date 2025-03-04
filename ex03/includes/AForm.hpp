/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:12:37 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/16 19:41:30 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private :
		std::string const	m_name;
		bool			m_signed;
		const int		m_sign_req;
		const int		m_exec_req;

	public :
		AForm();
		AForm(std::string name, int sign_req, int exec_req);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();
	//get set
		std::string			get_name(void) const;
		int					get_sign_req(void) const;
		int					get_exec_req(void) const;
		bool				get_signed(void) const;
		void				set_signed(bool sign);
		void				beSigned(Bureaucrat &bureaucrat);
		void				execute(Bureaucrat const &executor) const;
		virtual void		doExec(Bureaucrat const &executor) const = 0;

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
	class FormNotSigned : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, AForm const &a);

#endif
