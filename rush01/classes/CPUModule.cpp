/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:16:02 by brandazz          #+#    #+#             */
//   Updated: 2015/01/18 21:09:55 by gmarais          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <mach/mach_host.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include "CPUModule.hpp"
#include "tools.hpp"

CPUModule::CPUModule()
{
	this->update();
}

CPUModule::CPUModule(const CPUModule& cm)
{
	*this = cm;
}

CPUModule::~CPUModule()
{
}

CPUModule& CPUModule::operator=(const CPUModule& cm)
{
	(void)cm;
	return *this;
}

void CPUModule::update()
{
	this->_ncpus = this->_retrieveNCPUs();
	this->_cpuModel = this->_retrieveCPUModel();
	int load = static_cast<int>(this->_retrieveCPULoad() * 100);

	if (this->_data.size() >= 10)
		this->_data.pop_back();
	this->_data.insert(this->_data.begin(), load);
}

std::string CPUModule::description()
{
	std::stringstream stream;
	stream << "CPU (" << this->_ncpus << ") " << this->_cpuModel;
	return stream.str();
}

std::vector<int> CPUModule::data()
{
	return this->_data;
}

float CPUModule::_retrieveCPULoad()
{
	host_cpu_load_info_data_t cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	unsigned long long ticks;

	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, reinterpret_cast<host_info_t>(&cpuinfo), &count) == KERN_SUCCESS)
	{
		ticks = 0;
		for(int i=0; i<CPU_STATE_MAX; i++)
			ticks += cpuinfo.cpu_ticks[i];
		return this->_computeCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], ticks);
	}
	return -1.0;
}

float CPUModule::_computeCPULoad(unsigned long long idle, unsigned long long ticks)
{
	unsigned long long idleSinceLastTime = idle - this->_previousIdle;
	unsigned long long ticksSinceLastTime = ticks - this->_previousTicks;
	this->_previousIdle = idle;
	this->_previousTicks = ticks;

	float q = (ticksSinceLastTime > 0) ? static_cast<float>(idleSinceLastTime) / static_cast<float>(ticksSinceLastTime) : 0;

	return 1.0 - q;
}

int CPUModule::_retrieveNCPUs()
{
	size_t len = sizeof(int);
	int ret = 0;

	sysctlbyname("hw.ncpu", &ret, &len, 0, 0);
	return ret;
}

std::string CPUModule::_retrieveCPUModel()
{
	char buf[512];
	size_t len = 512;

	sysctlbyname("machdep.cpu.brand_string", buf, &len, 0, 0);
	return std::string(buf);
}
