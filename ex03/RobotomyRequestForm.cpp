/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:22:26 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/17 16:54:26 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm::AForm("RobotomyRequestForm", 72, 45),
	m_target("no_target")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	AForm::AForm("RobotomyRequestForm", 72, 45),
	m_target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
	AForm::AForm(src),
	m_target(src.m_target)
{
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->m_target = src.m_target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

void RobotomyRequestForm::doExec(Bureaucrat const &executor) const
{
	srand(time(0));
	int tail_o_face = rand() % 2;
	std::cout << tail_o_face <<std::endl;
	tail_o_face > 0 ? (std::cout << this->m_target << " successfully robotoized!" << std::endl) :
		 (std::cout << this->m_target << " robotization failed, he died :'(" << std::endl);
	std::cout << executor.get_name() << " has executed the robotomy." << std::endl;
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &a)
{
	o << "Robotomy request Form named " << a.get_name() << 
		(a.get_signed() ? " is signed, " : " is not signed, ") << "sign grade : " 
		<< a.get_sign_req() << "exec grade : " << a.get_exec_req() << "." << std::endl;
	return (o);
}
