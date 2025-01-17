/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:56:21 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/17 17:38:47 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
	private:
	std::string m_target;

	public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
	~PresidentialPardonForm();

	void doExec(Bureaucrat const &executor) const;
};
std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &a);


#endif
