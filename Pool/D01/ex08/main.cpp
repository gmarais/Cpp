// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 04:30:26 by gmarais           #+#    #+#             //
//   Updated: 2015/01/07 04:30:26 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "Human.cpp"

int 	main()
{
	Human	human;

	human.action("meleeAttack", "Bob");
	human.action("rangedAttack", "Bob");
	human.action("intimidatingShout", "Bob");
	return 1;
}
