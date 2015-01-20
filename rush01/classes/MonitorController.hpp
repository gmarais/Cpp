// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MonitorController.hpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 14:42:19 by gmarais           #+#    #+#             //
/*   Updated: 2015/01/17 16:28:42 by brandazz         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#ifndef _MonitorController_CLASS_
# define _MonitorController_CLASS_

# include <iostream>
# include <list>
# include "../interfaces/IMonitorModule.hpp"
# include "../interfaces/IMonitorDisplay.hpp"

class	MonitorController
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::vector<IMonitorModule*>	_modules;
	IMonitorDisplay		*_monitorDisplay;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	MonitorController();

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	MonitorController(int ac, char** av);
	MonitorController(MonitorController const & src);
	virtual ~MonitorController();
//---------------------------------------------------------/ GETTERS & SETTERS /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	int		run();
//-----------------------------------------------------------------/ OPERATORS /
	MonitorController &	operator=(MonitorController const & rhs);

};

#endif
