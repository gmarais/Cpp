/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:17:04 by brandazz          #+#    #+#             */
/*   Updated: 2015/01/17 21:29:16 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include <cstdlib>
#include <string>
#include <vector>

class IMonitorDisplay {

public:
	virtual ~IMonitorDisplay();

	virtual void generateFrame(size_t idx) = 0;
	virtual void generateChart( std::vector<int> data) = 0;
	virtual void generateText(std::string s) = 0;
	virtual void render() = 0;
	virtual bool getStatus() = 0;
};

#endif /* !IMONITORDISPLAY_HPP */

