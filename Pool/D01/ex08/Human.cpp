// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 03:10:16 by gmarais           #+#    #+#             //
//   Updated: 2015/01/07 03:10:16 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "Human.hpp"
typedef  void (Human::*HumanMemFn)(std::string const & target);


//-----------------------------------------------------/ STATIC VARIABLES INIT /


//------------------------------------------------------/ CONSTRUCT / DESTRUCT /

//-----------------------------------------------------------------/ FUNCTIONS /
	void Human::meleeAttack(std::string const & target)
	{
		std::cout << "Human used melee attack on " << target << std::endl;
	}

	void Human::rangedAttack(std::string const & target)
	{
		std::cout << "Human used ranged attack on " << target << std::endl;
	}

	void Human::intimidatingShout(std::string const & target)
	{
		std::cout << "Human used intimidating shout on " << target << std::endl;
	}

	void Human::action(std::string const & action_name, std::string const & target)
	{
		HumanMemFn array_member_fn[] = { &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout };
		std::string const	action_names[] = { "meleeAttack", "rangedAttack", "intimidatingShout" };

		for (int i = 0; i < 3; i++)
		{
			if (action_names[i] == action_name)
				(this->*(array_member_fn[i]))(target);
		}
	}
