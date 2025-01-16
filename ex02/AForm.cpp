/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:55:37 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/16 18:25:24 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :
    m_name("Unnamed"),
    m_signed(false),
    m_sign_req(150),
    m_exec_req(150)
{
    std::cout << "Creating an \"Unnamed\" Form, grade requierment to sign : 150, grade requierment to execute : 150." << std::endl;
    return ;
}

AForm::AForm(std::string name, int sign_req, int exec_req) :
    m_name(name),
    m_signed(false),
    m_sign_req(sign_req),
    m_exec_req(exec_req)
{
    if (sign_req < 1)
        throw (AForm::GradeTooHighException());
    else if (sign_req > 150)
        throw (AForm::GradeTooLowException());
    else if (exec_req < 1)
        throw (AForm::GradeTooHighException());
    else if (exec_req > 150)
        throw (AForm::GradeTooLowException());
    std::cout << "Creating a AForm nammed : " << this->get_name() << " grade requierment to sign : " 
        << this->get_sign_req() << " grade requierment to execute : " 
        << this->get_exec_req() << "." << std::endl;
    return ;
}

AForm::AForm(const  AForm &src) :
    m_name(src.get_name()),
    m_sign_req(src.get_sign_req()),
    m_exec_req(src.get_exec_req())
{
    return ;
}

AForm &AForm::operator=(const AForm &src)
{
    if (this != &src)
    {
        this->m_name = src.get_name();
    }
    return (*this);
}

AForm::~AForm()
{
    return ;
}

std::string AForm::get_name(void) const
{
    return (this->m_name);
}

int AForm::get_sign_req(void) const
{
    return (this->m_sign_req);
}

int AForm::get_exec_req(void) const
{
    return (this->m_exec_req);
}

bool AForm::get_signed(void) const
{
    return (this->m_signed);
}

void AForm::set_name(std::string name)
{
    m_name = name;
}


void    AForm::set_signed(bool sign)
{
    this->m_signed = sign;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.get_grade() > this->get_sign_req())
		throw (AForm::GradeTooLowException());
	else
	{
		this->m_signed = true;
		std::cout << bureaucrat.get_name() << " successfully signed " << this->m_name << std::endl;
	}
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return("Grade too low.");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return("Grade too high.");
}

const char *AForm::FormNotSigned::what(void) const throw()
{
	return("Form not signed.");
}

std::ostream &operator<<(std::ostream &o, AForm const &a)
{
	o << a.get_name() << " AForm signed: " << (a.get_signed() ? "true" : "false") << ", sign grade : " 
		<< a.get_sign_req() << ", exec grade : " << a.get_exec_req() << std::endl;
	return (o);
}
