/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:33:21 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/17 17:44:52 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm::AForm("PresidentialPardonForm", 25, 5),
	m_target("no_target")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	AForm::AForm("PresidentialPardonForm", 25, 5),
	m_target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
	AForm::AForm(src),
	m_target(src.m_target)
{
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->m_target = src.m_target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

void	PresidentialPardonForm::doExec(Bureaucrat const &executor) const
{
	std::cout << this->m_target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
	std::cout << executor.get_name() << " has executed the form." << std::endl;
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &a)
{
	o << "Presidential Pardon Form named " << a.get_name() << 
		(a.get_signed() ? " is signed, " : " is not signed, ") << "sign grade : " 
		<< a.get_sign_req() << "exec grade : " << a.get_exec_req() << "." << std::endl;
	return (o);
}

