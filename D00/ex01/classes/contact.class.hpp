// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   contact.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 21:06:14 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 02:33:25 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#ifndef _CONTACT_
#define _CONTACT_

#include <iostream>

class Contact
{
public:
	static int instance_nbr;
	bool is_registered;

	Contact(int const _buff_size);
	~Contact();
	void registerContact( void );
	void printInfos(bool truncated) const;
	std::string printTruncated(std::string value) const;

private:
	int const _buff_size;
	int _index;
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _login;
	std::string _postal_address;
	std::string _email_address;
	std::string _phone_number;
	std::string _birthday_date;
	std::string _favourite_meal;
	std::string _underwear_color;
	std::string _darkest_secret;

	void _askInfos();
	void _readInfo(std::string *value, std::string message);
};

#endif
