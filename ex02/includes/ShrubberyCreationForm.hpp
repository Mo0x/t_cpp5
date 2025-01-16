/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:07:20 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/16 17:11:41 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class ShurbberyCreationForm : public AForm
{
	ShurbberyCreationForm();
	ShurbberyCreationForm(std::string name);
	ShurbberyCreationForm(ShurbberyCreationForm &src);
	ShurbberyCreationForm &operator=(const ShurbberyCreationForm &src);
	~ShurbberyCreationForm();
};

#endif
