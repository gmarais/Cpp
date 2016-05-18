// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 22:11:51 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 22:11:51 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"

//------------------------------------------------------------/ NESTED CLASSES /
class	Bureaucrat::GradeTooHighException : public std::exception
{
	virtual const char *what() const throw()
	{
		return "Grade is too hight!";
	}
};

class	Bureaucrat::GradeTooLowException : public std::exception
{
	virtual const char *what() const throw()
	{
		return "Grade is too low!";
	}
};

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
	_name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) :
	_name(src.getName())
{
	this->_grade = src.getGrade();
	*this = src;
}


Bureaucrat::~Bureaucrat()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
const std::string &	Bureaucrat::getName() const
{
	return this->_name;
}

int					Bureaucrat::getGrade() const
{
	return this->_grade;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void			Bureaucrat::incrGrade()
{
	if (this->_grade - 1 <= 0)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;	
}

void			Bureaucrat::decrGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

//-----------------------------------------------------------------/ OPERATORS /
Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	(void)rhs;
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}
