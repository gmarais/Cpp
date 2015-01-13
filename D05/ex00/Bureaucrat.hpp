// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 22:11:51 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 22:11:51 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Bureaucrat_CLASS_
# define _Bureaucrat_CLASS_

# include <iostream>
# include <exception>

class	Bureaucrat
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	const std::string  	_name;
	int					_grade;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	Bureaucrat();
//------------------------------------------------------/ PRIVATE NESTED CLASS /
	class	GradeTooHighException;
	class	GradeTooLowException;

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat();
//---------------------------------------------------------/ GETTERS & SETTERS /
	const std::string &	getName() const;
	int					getGrade() const;
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	void				incrGrade();
	void				decrGrade();
//-----------------------------------------------------------------/ OPERATORS /
	Bureaucrat &	operator=(Bureaucrat const & rhs);

};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
