// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Array.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 12:13:51 by gmarais           #+#    #+#             //
//   Updated: 2015/01/14 16:42:39 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Array.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
template <typename T>
Array<T>::Array() :
	_elements(new T[0]),
	_size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) :
	_elements(new T[n]),
	_size(n)
{
}

template <typename T>
Array<T>::Array(Array<T> const & src) :
	_elements(new T[src.size()]),
	_size(src.size())
{
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] = src[i];
	}
	*this = src;
}


template <typename T>
Array<T>::~Array()
{
	delete [] this->_elements;
}

//---------------------------------------------------------/ GETTERS & SETTERS /
template <typename T>
unsigned int	Array<T>::size() const
{
	return this->_size;
}

//-----------------------------------------------------------------/ FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
template <typename T>
Array<T> &	Array<T>::operator=(Array const & rhs)
{
	delete [] this->_elements;
	this->_size = rhs.size();
	this->_elements = new T[this->_size];
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] = rhs[i];
	}
	return *this;
}

template <typename T>
T & Array<T>::operator[](unsigned int i)
{
	if(i > this->_size)
	{
		throw std::exception();
	}
	return this->_elements[i];
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
