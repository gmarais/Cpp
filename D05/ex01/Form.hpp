// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/13 05:30:57 by gmarais           #+#    #+#             //
//   Updated: 2015/01/13 05:30:57 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Form_CLASS_
# define _Form_CLASS_

# include <iostream>

class	Form
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	const std::string	_name;
	bool				_signed;
	const int			_grade_to_sign;
	const int			_grade_to_exec;
	
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Form();
	Form(Form const & src);
	~Form();
//---------------------------------------------------------/ GETTERS & SETTERS /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	Form &	operator=(Form const & rhs);

};

#endif
