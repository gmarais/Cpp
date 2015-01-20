/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:17:10 by brandazz          #+#    #+#             */
/*   Updated: 2015/01/17 21:26:28 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATEMODULE_HPP
#define DATEMODULE_HPP

#include "IMonitorModule.hpp"

class DateModule : public IMonitorModule {

public:
	DateModule();
	DateModule(const DateModule& dm);
	virtual ~DateModule();

	DateModule& operator=(const DateModule& dm);

	virtual void update();
	virtual std::string description();
	virtual std::vector<int> data();

private:
	std::string _currentDate;

	void _retrieveCurrentDate();
};

#endif /* !DATEMODULE_HPP */
