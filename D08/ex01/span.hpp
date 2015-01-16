// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 18:25:29 by gmarais           #+#    #+#             //
//   Updated: 2015/01/15 18:25:29 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _span_CLASS_
# define _span_CLASS_

# include <iostream>
# include <iterator>
# include <algorithm>
# include <list>
# include <stdexcept>

class	span
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	unsigned int	_n;
	std::list<int>	_lst;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	span();

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	span(unsigned int n);
	span(span const & src);
	~span();
//---------------------------------------------------------/ GETTERS & SETTERS /
unsigned int	getN() const;
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	void	addNumber(int number);
	int		shortestSpan();
	int		longestSpan();
//-----------------------------------------------------------------/ OPERATORS /
	span &	operator=(span const & rhs);

};

#endif
