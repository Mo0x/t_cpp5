/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:17:10 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/17 16:46:21 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
	private:
	std::string m_target;

	public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
	~RobotomyRequestForm();

	void doExec(Bureaucrat const &executor) const;
};
std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &a);


#endif
