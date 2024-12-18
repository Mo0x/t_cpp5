/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:22:10 by mgovinda          #+#    #+#             */
/*   Updated: 2024/12/18 17:28:34 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	private:
	std::string const	m_name;
	int					m_grade;

	public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat(std::string name, int grade);
	Bureaucrat &operator=(const Bureaucrat &src);
	~Bureaucrat();

	//get set
	std::string	get_name(void) const;
	int			get_grade(void) const;
	void		set_grade(int grade);

};

#endif
