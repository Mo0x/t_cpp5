/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:55:37 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/15 16:53:23 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
    m_name("Unnamed"),
    m_signed(false),
    m_sign_req(150),
    m_exec_req(150)
{
    std::cout << "Creating an \"Unnamed\" Form, grade requierment to sign : 150, grade requierment to execute : 150." << std::endl;
    return ;
}

Form::Form(std::string name, int sign_req, int exec_req) :
    m_name(name),
    m_signed(false),
    m_sign_req(sign_req),
    m_exec_req(exec_req)
{
    if (sign_req < 1)
        throw (Form::GradeTooHighException());
    else if (sign_req > 150)
        throw (Form::GradeTooLowException());
    else if (exec_req < 1)
        throw (Form::GradeTooHighException());
    else if (exec_req > 150)
        throw (Form::GradeTooLowException());
    std::cout << "Creating a Form nammed : " << this->get_name() << " grade requierment to sign : " 
        << this->get_sign_req() << " grade requierment to execute : " 
        << this->get_exec_req() << "." << std::endl;
    return ;
}

Form::Form(const  Form &src) :
    m_name(src.get_name()),
    m_sign_req(src.get_sign_req()),
    m_exec_req(src.get_exec_req())
{
    return ;
}

Form &Form::operator=(const Form &src)
{
    if (this != &src)
    {
        this->m_name = src.get_name();
    }
    return (*this);
}

Form::~Form()
{
    return ;
}

std::string Form::get_name(void) const
{
    return (this->m_name);
}

int Form::get_sign_req(void) const
{
    return (this->m_sign_req);
}

int Form::get_exec_req(void) const
{
    return (this->m_exec_req);
}

bool Form::get_signed(void) const
{
    return (this->m_signed);
}

void Form::set_name(std::string name)
{
    m_name = name;
}


void    Form::set_signed(bool sign)
{
    this->m_signed = sign;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.get_grade() > this->get_sign_req())
		throw (Form::GradeTooLowException());
	else
	{
		this->m_signed = true;
		std::cout << bureaucrat.get_name() << " successfully signed " << this->m_name << std::endl;
	}
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return("Grade too low");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return("Grade too high");
}

std::ostream &operator<<(std::ostream &o, Form const &a)
{
	o << a.get_name() << " form signed: " << (a.get_signed() ? "true" : "false") << ", sign grade : " 
		<< a.get_sign_req() << ", exec grade : " << a.get_exec_req() << std::endl;
	return (o);
}
