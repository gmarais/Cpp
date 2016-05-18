// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MonitorController.cpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 14:42:19 by gmarais           #+#    #+#             //
//   Updated: 2015/01/18 19:07:09 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MonitorController.hpp"
#include "HostnameModule.hpp"
#include "OSInfoModule.hpp"
#include "DateModule.hpp"
#include "CPUModule.hpp"
#include "RamModule.hpp"
#include "XMonitorDisplay.hpp"
#include "NCursesMonitorDisplay.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
MonitorController::MonitorController()
{
}

MonitorController::MonitorController(int ac, char** av)
{
//--------------------/ GET List of Monitor Modules /
	this->_modules.push_back(new HostnameModule());
	this->_modules.push_back(new OSInfoModule());
	this->_modules.push_back(new DateModule());
	this->_modules.push_back(new CPUModule());
	this->_modules.push_back(new RamModule());

//----------------------------/ GET Monitor Display /
	if (ac >= 2)
	{
		std::string	option(av[1]);

		if (option == "-gui")
		{
			this->_monitorDisplay = new XMonitorDisplay(this->_modules.size() - 1);
			return;
		}
	}
	this->_monitorDisplay = new NCursesMonitorDisplay(this->_modules.size() - 1);
}

MonitorController::MonitorController(MonitorController const & src)
{
	*this = src;
}


MonitorController::~MonitorController()
{
	delete this->_monitorDisplay;
}

//---------------------------------------------------------/ GETTERS & SETTERS /
//-----------------------------------------------------------------/ FUNCTIONS /
//

int					MonitorController::run()
{
	while (!this->_monitorDisplay->getStatus())
	{
		// Update
		for (size_t i=0; i < this->_modules.size(); i++)
		{
			this->_modules[i]->update();
		}
		// Render
		for (size_t i=0; i < this->_modules.size(); i++)
		{
			this->_monitorDisplay->generateFrame(i);
			this->_monitorDisplay->generateText(this->_modules[i]->description());
			this->_monitorDisplay->generateChart(this->_modules[i]->data());
			this->_monitorDisplay->render();
		}
	}
	return 0;
}

//-----------------------------------------------------------------/ OPERATORS /
MonitorController &	MonitorController::operator=(MonitorController const & rhs)
{
	static_cast<void>(rhs);
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
