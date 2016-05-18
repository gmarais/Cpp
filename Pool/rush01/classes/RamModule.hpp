// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RamModule.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/18 18:18:58 by gmarais           #+#    #+#             //
//   Updated: 2015/01/18 19:35:59 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _RamModule_CLASS_
# define _RamModule_CLASS_

# include <inttypes.h>

# include "IMonitorModule.hpp"

class	RamModule : public IMonitorModule
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	uint64_t			_physicalMem;
	std::vector<int>	_data;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	RamModule();
	RamModule(RamModule const & src);
	virtual ~RamModule();
//---------------------------------------------------------/ GETTERS & SETTERS /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual void				update();
	virtual std::string			description();
	virtual std::vector<int>	data();
//-----------------------------------------------------------------/ OPERATORS /
	RamModule &	operator=(RamModule const & rhs);

};

#endif
