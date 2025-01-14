/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:12:37 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/14 17:33:50 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private :
        std::string m_name;
        bool        m_signed = false;
        const int   m_sign_req;
        const int   m_exec_req;
    
    public :
        Form();
        Form(std::string name, int sign_req, int exec_req);
        Form(const &src);
        Form const &operator=(Form const &copy);
        ~Form();
    //get set
        std::string get_name();
        int         get_sign_req();
        int         get_exec_req();
        int         get_signed();
        void        set_name(std::string name);
        void        set_sign_req(int sign_req);
        void        set_exec_req(int exec_req);
        void        set_signed(bool signed);
        void        beSigned(Bureaucrat Bureaucrat);

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
