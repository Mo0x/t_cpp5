/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:45:32 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/17 16:49:19 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	//AForm test; //test to show AForm is abstract
	{
		ShrubberyCreationForm shrub("super_test_3000");
		Bureaucrat alphonse("Big Al", 42);

		std::cout << shrub << std::endl;
		alphonse.signForm(shrub);
		alphonse.executeForm(shrub);

		Bureaucrat gros_nullos("nul", 150);
		gros_nullos.executeForm(shrub);
	}
	{
		RobotomyRequestForm robot("Iron cock wanabe");
		Bureaucrat bl("Big L", 42);
		std::cout << std::endl <<std::endl;
		std::cout << bl << std::endl << robot << std::endl;

		bl.signForm(robot);
		bl.executeForm(robot);

	}
}
