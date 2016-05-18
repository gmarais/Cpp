// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Array.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 12:13:51 by gmarais           #+#    #+#             //
//   Updated: 2015/01/14 14:00:10 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Array_CLASS_
# define _Array_CLASS_

# include <iostream>

template <typename T>
class	Array
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	T*				_elements;
	unsigned int	_size;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Array();
	Array(unsigned int n);
	Array(Array const & src);
	~Array();
//---------------------------------------------------------/ GETTERS & SETTERS /
	unsigned int	size() const;
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	Array &	operator=(Array const & rhs);
	T &	operator[](unsigned int i);

};

#endif
