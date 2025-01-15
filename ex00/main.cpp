/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:26:57 by mgovinda          #+#    #+#             */
/*   Updated: 2025/01/15 15:30:45 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat a("allo", 151);
			std::cout << a << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat b(0);
			std::cout << b << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat c(72);
			std::cout << c << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat d(151);
			std::cout << d << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat a(150);
			std::cout << a << std::endl;
			a.decrease_grade();
			std::cout << a << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat b(3);
			std::cout << b << std::endl;
			b.increase_grade();
			std::cout << b << std::endl;
			b.increase_grade();
			std::cout << b << std::endl;
			b.increase_grade();
			std::cout << b << std::endl;
			b.increase_grade();
			std::cout << b << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
