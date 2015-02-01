// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AbstractVM.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 16:44:03 by gmarais           #+#    #+#             //
//   Updated: 2015/01/28 18:39:01 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AbstractVM.hpp"
#include <fstream>
#include <sstream>
#include <cstring>

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
AbstractVM::AbstractVM()
{
}

AbstractVM::AbstractVM(int files_number, char **files) :
	_files_number(files_number),
	_files(files_number > 0 ? files : NULL)
{
}

AbstractVM::AbstractVM(AbstractVM const & src)
{
	*this = src;
}

AbstractVM::~AbstractVM()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
int				AbstractVM::getFilesNumber() const
{
	return this->_files_number;
}

const char**	AbstractVM::getFiles() const
{
	return const_cast<const char**>(this->_files);
}

//-----------------------------------------------------------------/ FUNCTIONS /
void			AbstractVM::executeLine(std::string line)
{
	std::cout << line << std::endl;	
}

int				AbstractVM::run()
{
	if (this->_files_number < 0)
	{
		std::cout << "\033[1;31mUsage error:\033[0;0m This program takes his name as first argument." << std::endl;
		return 1;
	}
	else if (this->_files_number)
	{
		std::fstream	fs;
		std::string		line;

		for (int i = 0; i < this->_files_number; ++i)
		{
			fs.open(this->_files[i], std::fstream::in);
			while (std::getline(fs, line))
			{
				this->executeLine(line);
			}
			fs.close();
		}
	}
	else
	{
		std::string		line;

		while (line.find(";;") == std::string::npos && std::getline(std::cin, line))
		{
			this->executeLine(line);
		}
		std::cout << "Hello" << std::endl;
	}
	return 0;
}

//-----------------------------------------------------------------/ OPERATORS /
AbstractVM &	AbstractVM::operator=(AbstractVM const & rhs)
{
	this->_files_number = rhs.getFilesNumber();
	this->_files = const_cast<char **>(rhs.getFiles());
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
