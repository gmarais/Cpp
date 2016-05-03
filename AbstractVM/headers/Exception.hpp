// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Exception.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/05/03 16:56:35 by gmarais           #+#    #+#             //
//   Updated: 2016/05/03 16:56:35 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Exception_CLASS_
# define _Exception_CLASS_

# include <string>
# include <exception>

class	Exception : public std::exception
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::string msg_;

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Exception(std::string const & msg) throw();
	Exception(Exception const & src);
	virtual ~Exception() throw();
//---------------------------------------------------------/ GETTERS & SETTERS /
	virtual const char *what() const throw();
//-----------------------------------------------------------------/ OPERATORS /
	Exception &	operator=(Exception const & rhs);

};

#endif
