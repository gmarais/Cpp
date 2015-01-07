// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Logger.hpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 05:26:03 by gmarais           #+#    #+#             //
//   Updated: 2015/01/07 05:26:03 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>

#ifndef _LOGGER_
#define _LOGGER_

class Logger
{
	public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	Logger(std::string file);
	~Logger();
	void		log(std::string const & dest, std::string const & message);

	private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::string	_filename;

//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	void		logToFile(std::string const & message);
	void		logToConsole(std::string const & message);
	std::string	makeLogEntry(std::string message);

};

#endif
