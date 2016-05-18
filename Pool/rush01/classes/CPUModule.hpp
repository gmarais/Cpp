/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:13:51 by brandazz          #+#    #+#             */
/*   Updated: 2015/01/18 19:22:33 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP

#include "IMonitorModule.hpp"

class CPUModule : public IMonitorModule {

public:
	CPUModule();
	CPUModule(const CPUModule& cm);
	virtual ~CPUModule();

	CPUModule& operator=(const CPUModule& cm);

	virtual void update();
	virtual std::string description();
	virtual std::vector<int> data();

private:
	std::vector<int> _data;
	unsigned long long _previousIdle;
	unsigned long long _previousTicks;
	int _ncpus;
	std::string _cpuModel;

	float _retrieveCPULoad();
	float _computeCPULoad(unsigned long long idle, unsigned long long ticks);
	int _retrieveNCPUs();
	std::string _retrieveCPUModel();
};

#endif /* !CPUMODULE_HPP */
