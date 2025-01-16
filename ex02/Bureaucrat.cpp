/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:20:18 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/16 19:11:13 by mgovinda         ###   ########.fr       */
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
	m_name(ft_unnamed()),
	m_grade(150)
{
	std::cout << "Default Bureaucrat constructor called: " << this->get_name() \
				<< " and lowest grade attributed (150)." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(int grade) :
	m_name(ft_unnamed()),
	m_grade(grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << "Unnamed but graded Bureaucrat constructor called: " << this->get_name() \
				<< " and with the grade of "<< grade << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name) :
	m_name(name),
	m_grade(150)
{
	std::cout << "Named but ungraded Bureaucrat constructor called: " << this->get_name() \
				<< " and with the lowest grade (150) "<< std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
	m_name(name),
	m_grade(grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << "Named and graded Bureaucrat constructor called : " << this->get_name() \
				<< " and grade: " << this->get_grade() << std::endl;
	return ;
}

Bureaucrat::Bureaucrat (const Bureaucrat &src) :
	m_name(src.get_name()),
	m_grade(src.get_grade())
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

void Bureaucrat::set_grade(int grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->m_grade = grade;
	return ;
}

void Bureaucrat::decrease_grade(void)
{
	if (this->get_grade() + 1 > 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->set_grade(this->get_grade() + 1);
}

void Bureaucrat::increase_grade(void)
{
	if (this->get_grade() - 1 < 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		this->set_grade(this->get_grade() - 1);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return("Grade too high");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &a)
{
	o << "Bureaucrat nammed " << a.get_name() << " graded : " << a.get_grade() << std::endl;
	return (o);
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->get_name() << " signs " << form.get_name() << "." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->get_name() << " cannot sign " << form.get_name() << " because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	if (!form.get_signed())
		throw(AForm::FormNotSigned());
	if (this->get_grade() > form.get_exec_req())
		throw(AForm::GradeTooLowException());
	form.execute(*this);
	std::cout << this->get_name() << " executed the form: " << form.get_name() << "." << std::endl;
	return ;
}
