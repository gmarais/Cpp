// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 14:16:34 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 03:42:36 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <iomanip>
#include "classes/contact.class.cpp"
#include "ft_isdigit.cpp"

int main()
{
	std::string user_input;
	Contact contact_list[8];

	while (user_input != "EXIT")
	{
		if (user_input == "ADD")
		{
			if (Contact::instance_nbr < 8)
			{
				contact_list[Contact::instance_nbr].registerContact();
			}
			else
			{
				std::cout << "\033[1;31mMUAHAHAHA Your contact list is already full summoner!\033[0m" << std::endl;
			}
		}
		else if (user_input == "SEARCH")
		{
			for (int i=0; i < 8 && contact_list[i].is_registered; i++)
			{
				contact_list[i].printInfos(true);
			}
			std::cout << "\033[1;35m" << "Enter the desired index :" << "\033[0m" << std::endl;
			std::getline(std::cin, user_input);
			if (user_input.length() && ft_isdigit(user_input[0]) && (user_input[0] - 48) < 8 && contact_list[user_input[0] - 48].is_registered)
			{
				contact_list[user_input[0] - 48].printInfos();
			}
			else
			{
				std::cout << "\033[1;31m" << "This index is not valid sorry!" << "\033[0m" << std::endl;				
			}
		}
		std::getline(std::cin, user_input);
	}
	return 1;
}
