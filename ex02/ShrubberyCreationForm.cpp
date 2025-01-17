/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:28:36 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/17 16:51:20 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm::AForm("ShrubberyCreationForm", 145, 137),
	m_target("no_target")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	AForm::AForm("ShrubberyCreationForm", 145, 137),
	m_target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
	AForm::AForm(src),
	m_target(src.m_target)
{
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->m_target = src.m_target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

void	ShrubberyCreationForm::doExec(Bureaucrat const &executor) const
{
	std::ostringstream oss;
	oss << this->m_target << "_shrubbery";
	std::string name = oss.str();
	std::ofstream file;
	file.open(name.c_str());
	if (file.fail())
	{
		std::cerr << "Couldnt open file: " << name << ". Action aborted." << std::endl;
	}
	file << TREE;
	file.close();
	std::cout << executor.get_name() <<" has done the Shrubberization." << std::endl;
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &a)
{
	o << "Shrubbery Creation Form named " << a.get_name() << 
		(a.get_signed() ? " is signed, " : "is not signed, ") << "sign grade : " 
		<< a.get_sign_req() << "exec grade : " << a.get_exec_req() << "." << std::endl;
	return (o);
}
