// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RamModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/18 18:18:58 by gmarais           #+#    #+#             //
//   Updated: 2015/01/18 21:12:52 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RamModule.hpp"
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <iostream>

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
RamModule::RamModule()
{
	this->update();
}

RamModule::RamModule(RamModule const & src)
{
	*this = src;
}


RamModule::~RamModule()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
//-----------------------------------------------------------------/ FUNCTIONS /
void				RamModule::update()
{
    vm_size_t				page_size;
    mach_port_t				mach_port;
    mach_msg_type_number_t	count;
    vm_statistics64_data_t	vm_stats;
	int						result = 0;

    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
        KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
										  reinterpret_cast<host_info64_t>(&vm_stats), &count))
    {
        long long free_memory = static_cast<int64_t>(vm_stats.free_count) * static_cast<int64_t>(page_size);
        long long used_memory = (static_cast<int64_t>(vm_stats.active_count)
								 + static_cast<int64_t>(vm_stats.inactive_count)
								 + static_cast<int64_t>(vm_stats.wire_count)) *  static_cast<int64_t>(page_size);
		result = static_cast<int>( (static_cast<double>(used_memory) / static_cast<double>(used_memory + free_memory) * 100) );
    }
	this->_data.insert(this->_data.begin(), result);
	if (this->_data.size() > 10)
		this->_data.pop_back();
}

std::string			RamModule::description()
{
	return "Ram Usage";
}

std::vector<int>	RamModule::data()
{
	return this->_data;
}

//-----------------------------------------------------------------/ OPERATORS /
RamModule &	RamModule::operator=(RamModule const & rhs)
{
	static_cast<void>(rhs);
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
