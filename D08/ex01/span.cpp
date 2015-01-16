// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 18:25:29 by gmarais           #+#    #+#             //
//   Updated: 2015/01/15 18:25:29 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "span.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
span::span()
{
}

span::span(unsigned int n) :
	_n(n)
{
}

span::span(span const & src)
{
	*this = src;
}


span::~span()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
void	span::addNumber(int number)
{
	if (this->_lst.size() >= this->_n)
		throw std::runtime_error("Span list is full.");	
	if (*find(this->_lst.begin(), this->_lst.end(), number) != number)
	{
		this->_lst.push_back(number);
	}
	else
	{
		throw std::runtime_error("Number allready exists in the list.");
	}
}

unsigned int	span::getN() const
{
	return this->_n;
}

//-----------------------------------------------------------------/ FUNCTIONS /
int		span::shortestSpan()
{
	std::list<int>::iterator	it;
	it = min_element(this->_lst.begin(), this->_lst.end());
	if (this->_n > 1 && it != this->_lst.end())
		return *it;
	throw std::runtime_error("No span to find.");
}

int		span::longestSpan()
{
	std::list<int>::iterator	it;
	it = max_element(this->_lst.begin(), this->_lst.end());
	if (this->_n > 1 && it != this->_lst.end())
		return *it;
	throw std::runtime_error("No span to find.");
}

//-----------------------------------------------------------------/ OPERATORS /
span &	span::operator=(span const & rhs)
{
	this->_n = rhs.getN();
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
