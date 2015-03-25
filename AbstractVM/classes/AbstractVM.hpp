// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AbstractVM.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 16:44:03 by gmarais           #+#    #+#             //
//   Updated: 2015/03/25 17:23:31 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _AbstractVM_CLASS_
# define _AbstractVM_CLASS_

#include <iostream>
#include <vector>
#include <algorithm>

class	AbstractVM
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	int		_files_number;
	char**	_files;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	AbstractVM();
	int				seekKeyword(std::string command, std::vector<std::string> words);
 	void			executeLine(std::string line);
	int				push(std::vector<std::string> args);
	int				mov(std::vector<std::string> args);

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
