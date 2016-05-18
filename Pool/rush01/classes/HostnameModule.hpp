/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:42:30 by brandazz          #+#    #+#             */
/*   Updated: 2015/01/17 21:25:38 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEMODULE_HPP
#define HOSTNAMEMODULE_CPP

#include "IMonitorModule.hpp"

class HostnameModule : public IMonitorModule {

public:
	HostnameModule();
	HostnameModule(const HostnameModule& hm);
	virtual ~HostnameModule();

	HostnameModule& operator=(const HostnameModule& hm);

	virtual void update();
	virtual std::string description();
	virtual std::vector<int> data();

private:
	std::string _hostname;
	std::string _username;

	void _retrieveHostname();
	void _retrieveUsername();
};

#endif /* !HOSTNAMEMODULE_HPP */
