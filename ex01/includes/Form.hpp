/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:12:37 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/16 19:02:05 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		std::string const	m_name;
		bool				m_signed;
		const int			m_sign_req;
		const int			m_exec_req;

	public :
		Form();
		Form(std::string name, int sign_req, int exec_req);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();
	//get set
		std::string get_name(void) const;
		int         get_sign_req(void) const;
		int         get_exec_req(void) const;
		bool        get_signed(void) const;
		void        set_signed(bool sign);
		void        beSigned(Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &o, Form const &a);

#endif
