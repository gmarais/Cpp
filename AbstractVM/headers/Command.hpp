// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Command.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/05/02 13:38:11 by gmarais           #+#    #+#             //
//   Updated: 2016/05/02 13:38:11 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Command_CLASS_
# define _Command_CLASS_

# include "Tools.hpp"
# include <string>
# include <list>
# include <stdexcept>
# include "eOperandType.hpp"

typedef struct Parameter
{
	std::string type;
	std::string value;
} Parameter_t;

class	Command
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::string name_;
	Parameter_t *param_;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	void ParseCommand(std::string line);
	void ParseParameter(std::string line);

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Command(std::string const line);
	Command(Command const & src);
	virtual ~Command();
//---------------------------------------------------------/ GETTERS & SETTERS /
	std::string getName() const;
	Parameter_t const *getParam() const;
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	Command &	operator=(Command const & rhs);
};

#endif
