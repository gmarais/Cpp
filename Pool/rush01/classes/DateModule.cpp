/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:18:52 by brandazz          #+#    #+#             */
//   Updated: 2015/01/18 20:12:57 by gmarais          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstring>

#include "DateModule.hpp"
#include "tools.hpp"

DateModule::DateModule()
{
	this->_retrieveCurrentDate();
}

DateModule::DateModule(const DateModule& dm)
{
	*this = dm;
}

DateModule::~DateModule()
{
}

DateModule& DateModule::operator=(const DateModule& dm)
{
	if (this != &dm)
		this->_currentDate = dm._currentDate;
	return *this;
}

void DateModule::update()
{
	this->_retrieveCurrentDate();
}

std::string DateModule::description()
{
	return this->_currentDate;
}

std::vector<int> DateModule::data()
{
	return std::vector<int>();
}

#include <stdio.h>
void DateModule::_retrieveCurrentDate()
{
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	char *str = asctime(timeinfo);
	char *ptr = strrchr(str, '\n');
	if (ptr) *ptr = '\0';
	this->_currentDate = std::string(str);
}
