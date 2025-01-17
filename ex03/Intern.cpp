/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:55:08 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/17 18:39:42 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	return ;
}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	(void) src;
	return (*this);
}

Intern::~Intern()
{
	return ;
}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string form, const std::string target)
{
	AForm *(*super_p[])(const std::string) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == form)
		{
			std::cout << "Random intern creates " << form << "." << std::endl;
			return (super_p[i](target));
		}
	}
	std::cout << "Couldnt find " << form << " form from the existing forms." << std::endl;
	return (NULL);
}
