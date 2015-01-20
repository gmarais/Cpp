/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:09:20 by brandazz          #+#    #+#             */
/*   Updated: 2015/01/17 21:25:11 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <string>
#include <vector>

class IMonitorModule {

public:
	virtual ~IMonitorModule();

	virtual void update() = 0;
	virtual std::string description() = 0;
	virtual std::vector<int> data() = 0;
};

#endif /* !IMONITORMODULE_HPP */
