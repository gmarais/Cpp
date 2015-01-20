/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:47:37 by brandazz          #+#    #+#             */
//   Updated: 2015/01/18 20:07:26 by gmarais          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "HostnameModule.hpp"
#include "tools.hpp"

HostnameModule::HostnameModule()
{
	this->_retrieveHostname();
	this->_retrieveUsername();
}

HostnameModule::HostnameModule(const HostnameModule& hm)
{
	*this = hm;
}

HostnameModule::~HostnameModule()
{
}

HostnameModule& HostnameModule::operator=(const HostnameModule& hm)
{
	if (this != &hm)
	{
		this->_hostname = hm._hostname;
		this->_username = hm._username;
	}
	return *this;
}

void HostnameModule::update()
{
}

std::string HostnameModule::description()
{
	return this->_username + "@" + this->_hostname;
}

std::vector<int> HostnameModule::data()
{
	return std::vector<int>();
}

void HostnameModule::_retrieveHostname()
{
	char buf[1024];
	gethostname(buf, 1024);
	this->_hostname = std::string(buf);
}

void HostnameModule::_retrieveUsername()
{
	char buf[1024];
	const char *path = "/usr/bin/whoami";
	char *const argv[] = {const_cast<char *>(path), reinterpret_cast<char *>(0)};

	command_output(buf, 1024, path, argv);
	this->_username = std::string(buf);
}
