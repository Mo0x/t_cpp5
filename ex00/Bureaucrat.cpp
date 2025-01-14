/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:20:18 by mgovinda          #+#    #+#             */
/*   Updated: 2024/12/18 19:15:25 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>
#include <iostream>

std::string ft_unnamed(void)
{
	static unsigned int count = 0;
	std::ostringstream oss;
	oss << "Unnamed" << count;
	std::string const name(oss.str());
	count++;
	return (name);
}

Bureaucrat::Bureaucrat() :
	m_grade(150),
	m_name(ft_unnamed())
{
	std::cout << "Default Bureaucrat constructor called: " << this->get_name() \
				<< "and lowest grade attributed (150)." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(int grade) :
	m_grade(grade),
	m_name(ft_unnamed())
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHigh());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLow());
	std::cout << "Unnamed but graded Bureaucrat constructor called: " << this->get_name() \
				<< "and with the grade of "<< grade << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name) :
	m_grade(150),
	m_name(name)
{
	std::cout << "Named but ungraded Bureaucrat constructor called: " << this->get_name() \
				<< "and with the lowest grade (150) "<< std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
	m_grade(grade),
	m_name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHigh());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLow());
	std::cout << "Named and graded Bureaucrat constructor called : " << this->get_name() \
				<< "and grade: " << this->get_grade() << std::endl;
	return ;
}

Bureaucrat::Bureaucrat (const Bureaucrat &src) :
	m_grade(src.get_grade()),
	m_name(src.get_name())
{
	return ;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		this->m_grade = src.get_grade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

std::string Bureaucrat::get_name(void) const
{
	return (this->m_name);
}

int Bureaucrat::get_grade(void) const
{
	return (this->m_grade);
}

void Bureaucrat::set_grade(int grade) :
{
	if (grade > 1 || grade < 151)
		m_grade = grade;
	else
		std::cout << "Error grade isnt between 1 and 150" << std::endl;
	return ;
}

const char *Bureaucrat::GradeTooLow::what(void) const throw()
{
	return("Grade too low");
}

const char *Bureaucrat::GradeTooHigh::what(void) const throw()
[
	return ("Grade too high");
]

std::ostream &operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat nammed " << a->get_name() << "graded : " << a->get_grade() << std::endl;
	return (o);
}
