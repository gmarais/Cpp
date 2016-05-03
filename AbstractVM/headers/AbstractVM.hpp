// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AbstractVM.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 16:44:03 by gmarais           #+#    #+#             //
//   Updated: 2015/04/22 14:37:25 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _AbstractVM_CLASS_
# define _AbstractVM_CLASS_

# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <list>
# include <map>
# include <algorithm>
# include "Tools.hpp"
# include "Command.hpp"
# include <Exception.hpp>
# include "IOperand.hpp"
# include "OperandFactory.hpp"

class	AbstractVM;
typedef  void (AbstractVM::*AbstractVMMember)(Parameter_t const *param);

class	AbstractVM
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	int		filesNumber_;
	char**	files_;
	bool	exited_;
	std::map<std::string, AbstractVMMember> commands_;
	std::map<std::string, eOperandType> typeNames_;
	std::list<IOperand const *> stack_;
	OperandFactory factory_;

//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	AbstractVM();
 	void			executeLine(std::string line, unsigned int lineNumber);
	void			fetchCommand(Command *cmd);
	void			push(Parameter_t const *param);
	void			pop(Parameter_t const *param);
	void			dump(Parameter_t const *param);
	void			assert(Parameter_t const *param);
	void			add(Parameter_t const *param);
	void			sub(Parameter_t const *param);
	void			mul(Parameter_t const *param);
	void			div(Parameter_t const *param);
	void			mod(Parameter_t const *param);
	void			print(Parameter_t const *param);
	void			exit(Parameter_t const *param);

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	AbstractVM(int files_number, char **files);
	AbstractVM(AbstractVM const & src);
	virtual	~AbstractVM();
//---------------------------------------------------------/ GETTERS & SETTERS /
	int				getFilesNumber() const;
	const char**	getFiles() const;
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	int				run();
//-----------------------------------------------------------------/ OPERATORS /
	AbstractVM &	operator=(AbstractVM const & rhs);

};

#endif
