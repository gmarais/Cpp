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

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
AbstractVM::AbstractVM()
{
}

AbstractVM::AbstractVM(int filesNumber, char **files) :
	filesNumber_(filesNumber),
	files_(filesNumber_ > 0 ? files : NULL)
{
	this->commands_["push"] = &AbstractVM::push;
	this->commands_["pop"] = &AbstractVM::pop;
	this->commands_["dump"] = &AbstractVM::dump;
	this->commands_["assert"] = &AbstractVM::assert;
	this->commands_["add"] = &AbstractVM::add;
	this->commands_["sub"] = &AbstractVM::sub;
	this->commands_["mul"] = &AbstractVM::mul;
	this->commands_["div"] = &AbstractVM::div;
	this->commands_["mod"] = &AbstractVM::mod;
	this->commands_["print"] = &AbstractVM::print;
	this->commands_["exit"] = &AbstractVM::exit;
	this->typeNames_["int8"] = INT8;
	this->typeNames_["int16"] = INT16;
	this->typeNames_["int32"] = INT32;
	this->typeNames_["float"] = FLOAT;
	this->typeNames_["double"] = DOUBLE;
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
	return this->filesNumber_;
}

const char**	AbstractVM::getFiles() const
{
	return const_cast<const char**>(this->files_);
}

//-------------------------------------------------------/ OPERATING FUNCTIONS /
void		AbstractVM::push(Parameter_t const *param)
{
	if (param == NULL)
		throw Exception( "Missing argument." );
	if (this->typeNames_.count(param->type) <= 0)
		throw Exception( "Unknown variable type." );
	if (param->value.empty())
		throw Exception( "Empty value." );
	if (ft_isANumber(param->value) == false)
		throw Exception( "Value is NAN." );
	IOperand const *operand = factory_.createOperand(this->typeNames_[param->type], param->value);
	if (operand != NULL)
		stack_.push_front(operand);
}

void		AbstractVM::pop(Parameter_t const *param)
{
	if (param != NULL)
		throw Exception( "Unexpected argument." );
	if (stack_.size() <= 0)
		throw Exception( "Pop on empty stack." );
	IOperand const *nb = stack_.front();
	stack_.pop_front();
	delete nb;
}

void		AbstractVM::dump(Parameter_t const *param)
{
	if (param != NULL)
		throw Exception( "Unexpected argument." );
	for (std::list<IOperand const *>::iterator i = stack_.begin(); i != stack_.end(); ++i)
	{
		std::cout << (*i)->toString() << std::endl;
	}
}

void		AbstractVM::assert(Parameter_t const *param)
{
	if (param == NULL)
		throw Exception( "Missing argument." );
	if (this->typeNames_.count(param->type) <= 0)
		throw Exception( "Unknown variable type." );
	if (param->value.empty())
		throw Exception( "Empty value." );
	if (ft_isANumber(param->value) == false)
		throw Exception( "Value is NAN." );
	IOperand const *operand = factory_.createOperand(this->typeNames_[param->type], param->value);
	IOperand const *nb1 = stack_.front();
	if (operand->getType() != nb1->getType())
		throw Exception( "Value has different type." );
	if (operand->getPrecision() != nb1->getPrecision())
		throw Exception( "Value has different precision." );
	if (operand->toString().compare(nb1->toString()) != 0)
		throw Exception( "Unequal values." );
}

void		AbstractVM::add(Parameter_t const *param)
{
	if (param != NULL)
		throw Exception( "Unexpected argument." );
	if (stack_.size() < 2)
		throw Exception( "Not enough elements in the stack." );
	IOperand const *nb1 = stack_.front();
	stack_.pop_front();
	IOperand const *nb2 = stack_.front();
	try
	{
		IOperand const *result = *nb1 + *nb2;
		stack_.pop_front();
		stack_.push_front(result);
		delete nb1;
		delete nb2;
	}
	catch (const Exception &e)
	{
		stack_.push_front(nb1);
		throw e;
	}
}

void		AbstractVM::sub(Parameter_t const *param)
{
	if (param != NULL)
		throw Exception( "Unexpected argument." );
	if (stack_.size() < 2)
		throw Exception( "Not enough elements in the stack." );
	IOperand const *nb1 = stack_.front();
	stack_.pop_front();
	IOperand const *nb2 = stack_.front();
	try
	{
		IOperand const *result = *nb1 - *nb2;
		stack_.pop_front();
		stack_.push_front(result);
		delete nb1;
		delete nb2;
	}
	catch (const Exception &e)
	{
		stack_.push_front(nb1);
		throw e;
	}
}

void		AbstractVM::mul(Parameter_t const *param)
{
	if (param != NULL)
		throw Exception( "Unexpected argument." );
	if (stack_.size() < 2)
		throw Exception( "Not enough elements in the stack." );
	IOperand const *nb1 = stack_.front();
	stack_.pop_front();
	IOperand const *nb2 = stack_.front();
	try
	{
		IOperand const *result = *nb1 * *nb2;
		stack_.pop_front();
		stack_.push_front(result);
		delete nb1;
		delete nb2;
	}
	catch (const Exception &e)
	{
		stack_.push_front(nb1);
		throw e;
	}
}

void		AbstractVM::div(Parameter_t const *param)
{
	if (param != NULL)
		throw Exception( "Unexpected argument." );
	if (stack_.size() < 2)
		throw Exception( "Not enough elements in the stack." );
	IOperand const *nb1 = stack_.front();
	stack_.pop_front();
	IOperand const *nb2 = stack_.front();
	try
	{
		IOperand const *result = *nb1 / *nb2;
		stack_.pop_front();
		stack_.push_front(result);
		delete nb1;
		delete nb2;
	}
	catch (const Exception &e)
	{
		stack_.push_front(nb1);
		throw e;
	}
}

void		AbstractVM::mod(Parameter_t const *param)
{
	if (param != NULL)
		throw Exception( "Unexpected argument." );
	if (stack_.size() < 2)
		throw Exception( "Not enough elements in the stack." );
	IOperand const *nb1 = stack_.front();
	stack_.pop_front();
	IOperand const *nb2 = stack_.front();
	try
	{
		IOperand const *result = *nb1 % *nb2;
		stack_.pop_front();
		stack_.push_front(result);
		delete nb1;
		delete nb2;
	}
	catch (const Exception &e)
	{
		stack_.push_front(nb1);
		throw e;
	}
}

void		AbstractVM::print(Parameter_t const *param)
{
	if (param != NULL)
		throw Exception( "Unexpected argument." );
	if (stack_.size() < 1)
		throw Exception( "Not enough elements in the stack." );
	IOperand const *nb1 = stack_.front();
	if (nb1->getType() != INT8)
		throw Exception( "Value is not of type INT8." );
	std::cout << static_cast<char>(ft_atod(nb1->toString()));
}

void		AbstractVM::exit(Parameter_t const *param)
{
	if (param != NULL)
		throw Exception( "Unexpected argument." );
	this->exited_ = true;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void			AbstractVM::fetchCommand(Command *cmd)
{
	if (this->commands_[cmd->getName()] != NULL)
		(this->*(this->commands_[cmd->getName()]))(cmd->getParam());
	else
		throw Exception( "Unknown instruction." );
}

void			AbstractVM::executeLine(std::string line, unsigned int lineNumber)
{
	Command *cmd = NULL;
	ft_ltrim(line);
	std::string::size_type	start = 0;
	std::string::size_type pos = line.find_first_of(";", start);
	if (pos != std::string::npos)
		line = line.substr(start, pos);
	if (line.length() > 0)
	{
		try
		{
			cmd = new Command(line);
			if (!cmd->getName().empty())
			{
				this->fetchCommand(cmd);
			}
			delete cmd;
			cmd = NULL;
		}
		catch (const Exception &e)
		{
			if (cmd != NULL)
			{
				delete cmd;
				cmd = NULL;
			}
			std::cerr << "\033[1;31mError line " << lineNumber << ": \033[0;31m" << e.what() << "\033[0;0m" << std::endl;
		}
	}
}

int				AbstractVM::run()
{
	this->exited_ = false;
	std::string	line;
	std::list<std::string> lines;

	if (this->filesNumber_ < 0)
	{
		std::cout << "\033[1;31mUsage Error:\033[0;31m This program takes at least one argument.\033[0;0m" << std::endl;
		return 1;
	}
	else if (this->filesNumber_)
	{
		std::fstream	fs;
		for (int i = 0; i < this->filesNumber_; ++i)
		{
			fs.open(this->files_[i], std::fstream::in);
			while (std::getline(fs, line))
			{
				lines.push_back(line);
			}
			fs.close();
		}
	}
	else
	{
		while (line.find(";;") == std::string::npos && std::getline(std::cin, line))
		{
			lines.push_back(line);
		}
	}
	for (std::list<std::string>::iterator i = lines.begin(); !this->exited_ && i != lines.end(); ++i)
	{
		this->executeLine(*i, std::distance(lines.begin(), i) + 1);
	}
	if (!this->exited_)
		std::cerr << "\033[1;31m" << "Error:\033[0;31m The program doesn't have an exit instruction.\033[0;0m" << std::endl;
	return 0;
}

//-----------------------------------------------------------------/ OPERATORS /
AbstractVM &	AbstractVM::operator=(AbstractVM const & rhs)
{
	this->filesNumber_ = rhs.getFilesNumber();
	this->files_ = const_cast<char **>(rhs.getFiles());
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
