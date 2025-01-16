/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:28:36 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/16 17:40:24 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
{
	return ;
}