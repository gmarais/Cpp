// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mutantstack.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 20:04:17 by gmarais           #+#    #+#             //
//   Updated: 2015/01/15 20:04:17 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "mutantstack.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
template <typename T>
MutantStack<T>::MutantStack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack<T>(MutantStack<T> const & src)
{
	*this = src;
}


template <typename T>
MutantStack<T>::~MutantStack<T>()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
//-----------------------------------------------------------------/ FUNCTIONS /
template <typename T>
iterator	MutantStack<T>::begin()
{
	return iterator(&this->top());
}

template <typename T>
iterator	MutantStack<T>::end()
{
	return iterator(&this->top() + this->size());
}

//-----------------------------------------------------------------/ OPERATORS /
template <typename T>
MutantStack<T> &	MutantStack<T>::operator=(MutantStack<T> const & rhs)
{
	
	void(rhs);
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
template <typename T>
std::ostream&	operator<<(std::ostream & os, const typename MutantStack<T>::iterator & rhs)
{
	return os << *rhs << std::endl;
}

