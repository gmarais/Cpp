/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:41:15 by brandazz          #+#    #+#             */
/*   Updated: 2015/01/18 18:14:44 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_HPP
#define OSINFOMODULE_HPP

#include "IMonitorModule.hpp"

class OSInfoModule : public IMonitorModule {

public:
	OSInfoModule();
	OSInfoModule(const OSInfoModule& osm);
	virtual ~OSInfoModule();

	OSInfoModule& operator=(const OSInfoModule& osm);

	virtual void update();
	virtual std::string description();
	virtual std::vector<int> data();

private:
	std::string _productName;
	std::string _productVersion;
	std::string _kernelInfo;

	void _retrieveOSInfo();
	void _retrieveKernelInfo();
	void _retrieveProductName();
	void _retrieveProductVersion();
};

#endif /* !OSINFOMODULE_HPP */
