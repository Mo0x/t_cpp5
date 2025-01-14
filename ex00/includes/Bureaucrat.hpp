/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:22:10 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/14 16:46:43 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	private:
	std::string const	m_name;
	int					m_grade;

	public:
	Bureaucrat();
	Bureaucrat(int grade);
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &src);
	~Bureaucrat();

	//get set
	std::string	get_name(void) const;
	int			get_grade(void) const;
	void		set_grade(int grade);

	//member fun
	void		increase_grade(void);
	void		decrease_grade(void);
	
	//Exceptions
	class GradeTooLow : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooHigh : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &a);

#endif
