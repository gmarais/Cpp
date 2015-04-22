// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AbstractVM.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 16:44:03 by gmarais           #+#    #+#             //
//   Updated: 2015/04/22 16:28:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AbstractVM.hpp"
#include <fstream>
#include <sstream>
#include "tools.hpp"
typedef  int (AbstractVM::*AbstractVMMember)(std::vector<std::string> args);

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
AbstractVM::AbstractVM()
{
}

AbstractVM::AbstractVM(int files_number, char **files) :
	_files_number(files_number),
	_files(files_number > 0 ? files : NULL)
{
}

AbstractVM::AbstractVM(AbstractVM const & src)
{
	*this = src;
}

AbstractVM::~AbstractVM()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
int				AbstractVM::getFilesNumber() const
{
	return this->_files_number;
}

const char**	AbstractVM::getFiles() const
{
	return const_cast<const char**>(this->_files);
}

//-------------------------------------------------------/ OPERATING FUNCTIONS /
int			AbstractVM::push(std::vector<std::string> args)
{
	args.erase(args.begin());
	if (!args.size() || args[0][0] == ';')
		std::cout << "ERROR: Missing argument." << std::endl;
	return 0;
}

int			AbstractVM::pop(std::vector<std::string> args)
{
	args.erase(args.begin());
	if (args.size() > 0 && args[0][0] != ';')
		std::cout << "ERROR: unexpected argument." << std::endl;
	return 0;
}

int			AbstractVM::dump(std::vector<std::string> args)
{
	args.erase(args.begin());
	if (args.size() > 0 && args[0][0] != ';')
		std::cout << "ERROR: unexpected argument." << std::endl;
	return 0;
}

int			AbstractVM::assert(std::vector<std::string> args)
{
	args.erase(args.begin());
	if (!args.size() || args[0][0] == ';')
		std::cout << "ERROR: Missing argument." << std::endl;
	return 0;
}

int			AbstractVM::add(std::vector<std::string> args)
{
	args.erase(args.begin());
	if (args.size() > 0 && args[0][0] != ';')
		std::cout << "ERROR: unexpected argument." << std::endl;
	return 0;
}

int			AbstractVM::sub(std::vector<std::string> args)
{
	args.erase(args.begin());
	if (args.size() > 0 && args[0][0] != ';')
		std::cout << "ERROR: unexpected argument." << std::endl;
	return 0;
}

int			AbstractVM::mul(std::vector<std::string> args)
{
	args.erase(args.begin());
	if (args.size() > 0 && args[0][0] != ';')
		std::cout << "ERROR: unexpected argument." << std::endl;
	return 0;
}

int			AbstractVM::div(std::vector<std::string> args)
{
	args.erase(args.begin());
	if (args.size() > 0 && args[0][0] != ';')
		std::cout << "ERROR: unexpected argument." << std::endl;
	return 0;
}

int			AbstractVM::mod(std::vector<std::string> args)
{
	args.erase(args.begin());
	if (args.size() > 0 && args[0][0] != ';')
		std::cout << "ERROR: unexpected argument." << std::endl;
	return 0;
}

int			AbstractVM::print(std::vector<std::string> args)
{
	args.erase(args.begin());
	if (args.size() > 0 && args[0][0] != ';')
		std::cout << "ERROR: unexpected argument." << std::endl;
	return 0;
}

int			AbstractVM::exit(std::vector<std::string> args)
{
	args.erase(args.begin());
	if (args.size() > 0 && args[0][0] != ';')
		std::cout << "ERROR: unexpected argument." << std::endl;
	this->_exited = true;
	return 0;
}

//-----------------------------------------------------------------/ FUNCTIONS /
int				AbstractVM::seekKeyword(std::string command, std::vector<std::string> words)
{
	std::vector<std::string> keywords;
	keywords.push_back("push");
	keywords.push_back("pop");
	keywords.push_back("dump");
	keywords.push_back("assert");
	keywords.push_back("add");
	keywords.push_back("sub");
	keywords.push_back("mul");
	keywords.push_back("div");
	keywords.push_back("mod");
	keywords.push_back("print");
	keywords.push_back("exit");
	std::vector<std::string>::iterator it;
	AbstractVMMember _commands[] = {
		&AbstractVM::push,
		&AbstractVM::pop,
		&AbstractVM::dump,
		&AbstractVM::assert,
		&AbstractVM::add,
		&AbstractVM::sub,
		&AbstractVM::mul,
		&AbstractVM::div,
		&AbstractVM::mod,
		&AbstractVM::print,
		&AbstractVM::exit
	};

	if ((it = find(keywords.begin(), keywords.end(), command)) != keywords.end())
	{
		return (this->*(_commands[std::distance(keywords.begin(), it)]))(words);
	}
	return 0;
}

void			AbstractVM::executeLine(std::string line)
{
	std::vector<std::string>	words = ft_split(line, std::string(" 	"));

	if (words.begin() != words.end() && this->seekKeyword(words[0], words))
	{
		std::cout << "\033[1;34m" << words[0] << "\033[0;0m";
		for (unsigned int i = 1; i < words.size(); i++)
			std::cout << " " << words[i];
		std::cout << std::endl;
	} else {
		
	}
}

int				AbstractVM::run()
{
	this->_exited = false;
	if (this->_files_number < 0)
	{
		std::cout << "\033[1;31mUsage error:\033[0;0m This program takes at least one argument." << std::endl;
		return 1;
	}
	else if (this->_files_number)
	{
		std::fstream	fs;
		std::string		line;

		for (int i = 0; !this->_exited && i < this->_files_number; ++i)
		{
			fs.open(this->_files[i], std::fstream::in);
			while (!this->_exited && std::getline(fs, line))
			{
				this->executeLine(line);
			}
			fs.close();
		}
	}
	else
	{
		std::string		line;

		while (!this->_exited && line.find(";;") == std::string::npos && std::getline(std::cin, line))
		{
			this->executeLine(line);
		}
	}
	return 0;
}

//-----------------------------------------------------------------/ OPERATORS /
AbstractVM &	AbstractVM::operator=(AbstractVM const & rhs)
{
	this->_files_number = rhs.getFilesNumber();
	this->_files = const_cast<char **>(rhs.getFiles());
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
