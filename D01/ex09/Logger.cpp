// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Logger.cpp	                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 05:26:37 by gmarais           #+#    #+#             //
//   Updated: 2015/01/07 05:26:37 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <ctime>
#include "Logger.hpp"

typedef  void (Logger::*LoggerMemFn)(std::string const & message);

//-----------------------------------------------------/ STATIC VARIABLES INIT /

//------------------------------------------------------/ CONSTRUCT / DESTRUCT /
	Logger::Logger(std::string file) : _filename(file)
	{
	}

	Logger::~Logger()
	{
	}

//-----------------------------------------------------------------/ FUNCTIONS /
	void	Logger::log(std::string const & dest, std::string const & message)
	{
		std::string	log_message = this->makeLogEntry(message);
		LoggerMemFn array_member_fn[] = { &Logger::logToFile, &Logger::logToConsole };
		std::string const	action_names[] = { "toFile", "toConsole" };

		for (int i = 0; i < 2; i++)
		{
			if (action_names[i] == dest)
				(this->*(array_member_fn[i]))(message);
		}
	}

	void	Logger::logToFile(std::string const & message)
	{
		std::ofstream	outfile;

		outfile.open((char *)this->_filename.c_str(), std::ios::out | std::ios::app );
		outfile << message << std::endl;
		outfile.close();
	}

	void	Logger::logToConsole(std::string const & message)
	{
		std::cout << message << std::endl;
	}

	std::string	Logger::makeLogEntry(std::string message)
	{
		std::time_t	rawtime;
		std::string	time_string;

		std::time(&rawtime);
		time_string = ctime(&rawtime);
		time_string[time_string.length() - 1] = ' ';
		time_string.resize(time_string.length() + 2 + message.length());
		time_string += ": " + message;
		return time_string;
	}
