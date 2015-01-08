// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   contact.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 21:06:07 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 02:32:57 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "contact.class.hpp"

int Contact::instance_nbr = 0;

// PUBLIC //

Contact::Contact(int const _buff_size = 10) : _buff_size(10)
{
	this->is_registered = false;
	(void)_buff_size;
}

Contact::~Contact() {}

std::string Contact::printTruncated(std::string value) const
{
	if (value.length() > 10)
	{
		value[9] = '.';
		value.resize(10);
	}
	return value;
}

void Contact::registerContact()
{
	this->_index = Contact::instance_nbr;
  	Contact::instance_nbr++;
	std::cout << "\033[1;34mNew demon has arrived : \033[1;31mEnter your demon's informations MUAHAHA\033[0m" << std::endl;
	this->_askInfos();
	this->is_registered = true;
}

void Contact::printInfos(bool truncated = false) const
{
	if (truncated)
	{
		std::cout << std::setw(10);
		std::cout << this->_index << "|";
		std::cout << std::setw(10);
		std::cout << Contact::printTruncated(this->_firstname) << "|";
		std::cout << std::setw(10);
		std::cout << Contact::printTruncated(this->_lastname) << "|";
		std::cout << std::setw(10);
		std::cout << Contact::printTruncated(this->_nickname) << std::endl;
	}
	else
	{
		std::cout << "Firstname : " << this->_firstname << std::endl;
		std::cout << "Lastname : " << this->_lastname << std::endl;
		std::cout << "Nickname : " << this->_nickname << std::endl;
		std::cout << "Login : " << this->_login << std::endl;
		std::cout << "Postal address : " << this->_postal_address << std::endl;
		std::cout << "Email address : " << this->_email_address << std::endl;
		std::cout << "Phone number : " << this->_phone_number << std::endl;
		std::cout << "Birthday date : " << this->_birthday_date << std::endl;
		std::cout << "Favourite meal : " << this->_favourite_meal << std::endl;
		std::cout << "Underwear color : " << this->_underwear_color << std::endl;
		std::cout << "Darkest secret : " << this->_darkest_secret << std::endl;
	}
}

// PRIVATE //

void Contact::_readInfo(std::string *value, std::string message)
{
	std::cout << "\033[1;35m" << message << "\033[0m" << std::endl;
	std::getline(std::cin, *value);
}

void Contact::_askInfos()
{
	this->_readInfo(&this->_firstname, "Demon's firstname :");
	this->_readInfo(&this->_lastname, this->_firstname + "'s lastname :");
	this->_readInfo(&this->_nickname, this->_firstname + "'s nickname :");
	this->_readInfo(&this->_login, this->_firstname + "'s login :");
	this->_readInfo(&this->_postal_address, this->_firstname + "'s postal address :");
	this->_readInfo(&this->_email_address, this->_firstname + "'s email address :");
	this->_readInfo(&this->_phone_number, this->_firstname + "'s phone number :");
	this->_readInfo(&this->_birthday_date, this->_firstname + "'s birthday date :");
	this->_readInfo(&this->_favourite_meal, this->_firstname + "'s favourite meal :");
	this->_readInfo(&this->_underwear_color, this->_firstname + "'s underwear color :");
	this->_readInfo(&this->_darkest_secret, this->_firstname + "'s darkest secret :");
}

