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
#include <iostream>

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
	return this->_files;
}

//-----------------------------------------------------------------/ FUNCTIONS /
int				AbstractVM::run()
{
	if (this->_files_number < 0)
	{
		std::cout << "\033[1;31mUsage error:\033[0;0m Invalid number of arguments."
		return 1;
	}
	else if (this->_files_number)
	{
	}
	else
	{
		
	}
}

//-----------------------------------------------------------------/ OPERATORS /
AbstractVM &	AbstractVM::operator=(AbstractVM const & rhs)
{
	this->_files_number = rhs.getFilesNumber();
	this->_files = rhs.getFiles();
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
