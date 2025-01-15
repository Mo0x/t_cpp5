/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:45:32 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/15 15:46:31 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try 
	{
		Form a;
		Form b("lol", 42, 156);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	try
	{
		Form form_0("47b", 42, 42);
		Bureaucrat jerome("jerome", 41);
		std::cout << form_0;
		jerome.signForm(form_0);
		std::cout << form_0;
		Form form_1("47c", 11, 5);
		jerome.signForm(form_1);
		std::cout << form_1;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form a("testo", 151, 5);
	}
	catch (std::exception &e)
	{
			std::cerr << e.what() << std::endl;
	}
	try
	{
		Form a("testo", 0, 5);
	}
	catch (std::exception &e)
	{
			std::cerr << e.what() << std::endl;
	}
	return (0);
}
