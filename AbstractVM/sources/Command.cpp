// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Command.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/05/02 13:38:11 by gmarais           #+#    #+#             //
//   Updated: 2016/05/02 13:38:11 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Command.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//-----------------------------------------------------------------/ FUNCTIONS /
void Command::ParseCommand(std::string line)
{
	ft_ltrim(line);
	std::string::size_type	start = 0;
	std::string::size_type pos = line.find_first_of(" 	", start);
	if (pos != std::string::npos)
	{
		this->name_ = line.substr(start, pos);
		line = line.substr(pos+1, line.length() - (pos + 1));
		this->ParseParameter(line);
	}
	else
	{
		this->name_ = line;
		param_ = NULL;
	}
}

void Command::ParseParameter(std::string line)
{
	ft_ltrim(line);
	ft_rtrim(line);
	if (line.length() > 0)
	{
		std::string::size_type	start = 0;
		std::string::size_type pos = line.find_first_of(" 	(", start);
		std::string::size_type posValueStart = line.find_first_of("(", start);
		std::string::size_type posValueEnd = line.find_first_of(")", start);
		if (pos != std::string::npos
			&& posValueStart != std::string::npos
			&& posValueEnd != std::string::npos
			&& posValueEnd > posValueStart)
		{
			param_ = new Parameter_t();
			param_->type = line.substr(start, pos);
			param_->value = line.substr(posValueStart + 1, posValueEnd - posValueStart - 1);
			if (posValueEnd != line.length() - 1)
				throw std::logic_error( "Too many parameters provided for instruction." );
		}
		else
		{
			param_ = NULL;
			throw std::logic_error( "Syntax error near parameter definition." );
		}
	}
	else
		param_ = NULL;
}

//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Command::Command(std::string const line)
{
	ParseCommand(line);
}

Command::Command(Command const & src)
{
	*this = src;
}


Command::~Command()
{
	if (this->param_ != NULL)
	{
		delete this->param_;
		this->param_ = NULL;
	}
}

//---------------------------------------------------------/ GETTERS & SETTERS /
std::string Command::getName() const
{
	return name_;
}

Parameter_t const *Command::getParam() const
{
	return param_;
}

//-----------------------------------------------------------------/ OPERATORS /
Command &	Command::operator=(Command const & rhs)
{
	this->name_ = rhs.getName();
	if (rhs.getParam() != NULL)
	{
		this->param_ = new Parameter_t();
		this->param_->type = rhs.getParam()->type;
		this->param_->value = rhs.getParam()->value;
	}
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
