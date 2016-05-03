// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Exception.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/05/03 16:56:35 by gmarais           #+#    #+#             //
//   Updated: 2016/05/03 16:56:35 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Exception.hpp"

//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Exception::Exception(std::string const & msg) throw() : msg_(msg)
{
}

Exception::Exception(Exception const & src)
{
	*this = src;
}


Exception::~Exception() throw()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
const char *Exception::what() const throw()
{
	return msg_.c_str();
}

//-----------------------------------------------------------------/ OPERATORS /
Exception &	Exception::operator=(Exception const & rhs)
{
	msg_ = rhs.what();
	return *this;
}
