/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   XMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:30:24 by brandazz          #+#    #+#             */
/*   Updated: 2015/01/18 19:05:02 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XMONITORDISPLAY_HPP
#define XMONITORDISPLAY_HPP

#include <X11/Xlib.h>
#include <unistd.h>

#include "IMonitorDisplay.hpp"

class XMonitorDisplay : public IMonitorDisplay {

public:
	XMonitorDisplay(size_t max_index);
	XMonitorDisplay(const XMonitorDisplay& md);
	virtual ~XMonitorDisplay();

	XMonitorDisplay& operator=(const XMonitorDisplay& md);

	virtual void generateFrame(size_t idx);
	virtual void generateChart(std::vector<int> data);
	virtual void generateText(std::string s);
	virtual void render();
	virtual bool getStatus();

private:
	unsigned int _width;
	unsigned int _height;
	size_t _max_index;
	Display* _dis;
	Window _win;
	GC _gc;

	static const int WIDTH;
	static const int HEIGHT;

	static const int FRAME_WIDTH;
	static const int FRAME_HEIGHT;

	static const int FRAME_MARGIN;
	static const int CHART_OFFSET;

	size_t _index;
	std::vector<int> _data;
	unsigned int _currentLine;

	XMonitorDisplay();
	void _retrieveWinSize();
	void _setXColor(const char *color);
};

#endif /* !XMONITORDISPLAY_HPP */
