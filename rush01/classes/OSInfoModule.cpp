/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:42:26 by brandazz          #+#    #+#             */
/*   Updated: 2015/01/18 18:22:29 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfoModule.hpp"
#include "tools.hpp"

OSInfoModule::OSInfoModule()
{
	this->_retrieveOSInfo();
}

OSInfoModule::OSInfoModule(const OSInfoModule& osm)
{
	*this = osm;
}

OSInfoModule::~OSInfoModule()
{
}

OSInfoModule& OSInfoModule::operator=(const OSInfoModule& osm)
{
	if (this != &osm)
	{
		this->_productName = osm._productName;
		this->_productVersion = osm._productVersion;
		this->_kernelInfo = osm._kernelInfo;
	}
	return *this;
}

void OSInfoModule::update()
{
}

std::string OSInfoModule::description()
{
	return this->_productName + " " + this->_productVersion + " - " + this->_kernelInfo;
}

std::vector<int> OSInfoModule::data()
{
	return std::vector<int>();
}

void OSInfoModule::_retrieveOSInfo()
{
	this->_retrieveProductName();
	this->_retrieveProductVersion();
	this->_retrieveKernelInfo();
}

void OSInfoModule::_retrieveProductName()
{
	char buf[512];
	const char *path = "/usr/bin/sw_vers";
	char *const argv[] = {const_cast<char *>(path), const_cast<char *>("-productName"), reinterpret_cast<char *>(0)};

	command_output(buf, 512, path, argv);
	this->_productName = std::string(buf);
}

void OSInfoModule::_retrieveProductVersion()
{
	char buf[512];
	const char *path = "/usr/bin/sw_vers";
	char *const argv[] = {const_cast<char *>(path), const_cast<char *>("-productVersion"), reinterpret_cast<char *>(0)};

	command_output(buf, 512, path, argv);
	this->_productVersion = std::string(buf);
}

void OSInfoModule::_retrieveKernelInfo()
{
	char buf[512];
	const char *path = "/usr/bin/uname";
	char *const argv[] = {const_cast<char *>(path), const_cast<char *>("-rs"), reinterpret_cast<char *>(0)};

	command_output(buf, 512, path, argv);
	this->_kernelInfo = std::string(buf);
}
