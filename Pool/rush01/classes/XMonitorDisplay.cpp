/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   XMonitorDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:33:22 by brandazz          #+#    #+#             */
//   Updated: 2015/01/18 19:50:25 by gmarais          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xutil.h>
#include <algorithm>
#include <unistd.h>

#include "XMonitorDisplay.hpp"

const int XMonitorDisplay::WIDTH = 976;
const int XMonitorDisplay::HEIGHT = 656;
const int XMonitorDisplay::FRAME_WIDTH = 320;
const int XMonitorDisplay::FRAME_HEIGHT = 320;
const int XMonitorDisplay::FRAME_MARGIN = 10;
const int XMonitorDisplay::CHART_OFFSET = 30;

XMonitorDisplay::XMonitorDisplay()
{
}

XMonitorDisplay::XMonitorDisplay(size_t max_index) : _width(WIDTH), _height(HEIGHT), _max_index(max_index), _currentLine(0)
{
	this->_dis = XOpenDisplay(0);
	this->_win = XCreateSimpleWindow(this->_dis, RootWindow(this->_dis, 0), 1,
			1, WIDTH, HEIGHT, 0, WhitePixel(this->_dis, 0), WhitePixel(this->_dis, 0));
	XMapWindow(this->_dis, this->_win);
	this->_gc = XCreateGC(this->_dis, this->_win, 0, 0);
}

XMonitorDisplay::XMonitorDisplay(const XMonitorDisplay& md)
{
	*this = md;
}

XMonitorDisplay::~XMonitorDisplay()
{
}

void XMonitorDisplay::_retrieveWinSize()
{
	int x, y;
	unsigned int bwidth, d;
	Window win;

	XGetGeometry(this->_dis, this->_win, &win, &x, &y, &this->_width,
			&this->_height, &bwidth, &d);
}

XMonitorDisplay& XMonitorDisplay::operator=(const XMonitorDisplay& md)
{
	(void)md;
	return *this;
}

void XMonitorDisplay::generateFrame(size_t idx)
{
	unsigned int colnumber = this->_width / FRAME_WIDTH;

	this->_index = idx;
	this->_retrieveWinSize();

	if (colnumber == 0) colnumber = 1;
	unsigned int col = idx % colnumber;
	if (idx != 0 && col == 0)
		this->_currentLine++;
	int startY = this->_currentLine * FRAME_HEIGHT + FRAME_MARGIN * 2;
	int startX = col * FRAME_WIDTH + FRAME_MARGIN * 2;
	this->_setXColor("#bed5f5");
	XFillRectangle(this->_dis, this->_win, this->_gc, startX, startY,
			FRAME_WIDTH - (FRAME_MARGIN * 2), FRAME_HEIGHT - (FRAME_MARGIN * 2));
	XSetForeground(this->_dis, this->_gc, WhitePixel(this->_dis, 0));
	startX -= FRAME_MARGIN;
	startY -= FRAME_MARGIN;
	this->_setXColor("#6c98d5");
	XFillRectangle(this->_dis, this->_win, this->_gc, startX, startY,
			FRAME_WIDTH - (FRAME_MARGIN * 2), FRAME_HEIGHT - (FRAME_MARGIN * 2));
}

void XMonitorDisplay::generateChart(std::vector<int> data)
{
	if (data.size() == 0) return;

	unsigned int colnumber = this->_width / FRAME_WIDTH;
	if (colnumber == 0) colnumber = 1;
	unsigned int col = this->_index % colnumber;

	const int max_height = FRAME_HEIGHT - (FRAME_MARGIN * 2) - CHART_OFFSET;
	const int max_width = (FRAME_WIDTH - (FRAME_MARGIN * 2)) / 10;
	const int max_value = *std::max_element(data.begin(), data.end());
	const int step = (max_value > 0) ? max_height / max_value : 0;
	int startY = this->_currentLine * FRAME_HEIGHT + FRAME_MARGIN + CHART_OFFSET;
	int startX = col * FRAME_WIDTH + FRAME_MARGIN;
	int n = 0;
	for (std::vector<int>::iterator it = data.begin(); it != data.end(); ++it)
	{
		if (n > 10) break;
		int h = *it * step;
		this->_setXColor("#dddd00");
		int y = startY + (max_height - h);
		XFillRectangle(this->_dis, this->_win, this->_gc, startX, y, max_width,
				h);
		startX += max_width;
		n++;
	}
}

void XMonitorDisplay::generateText(std::string s)
{
	unsigned int colnumber = this->_width / FRAME_WIDTH;
	if (colnumber == 0) colnumber = 1;
	unsigned int col = this->_index % colnumber;
	int startY = this->_currentLine * FRAME_HEIGHT + FRAME_MARGIN + CHART_OFFSET / 2;
	int startX = col * FRAME_WIDTH + FRAME_MARGIN * 2;
	const char *str = s.c_str();
	this->_setXColor("#ffffff");
	XDrawString(this->_dis, this->_win, this->_gc, startX, startY, str,
			s.length());
}

void XMonitorDisplay::render()
{
	XSync(this->_dis, false);
	if (this->_index >= this->_max_index)
	{
		sleep(1);
		XClearWindow(this->_dis, this->_win);
		this->_currentLine = 0;
	}
}

bool XMonitorDisplay::getStatus()
{
	return false;
}

void XMonitorDisplay::_setXColor(const char *color)
{
	Colormap colormap = DefaultColormap(this->_dis, 0);
	XColor col;

	XParseColor(this->_dis, colormap, color, &col);
	XAllocColor(this->_dis, colormap, &col);
	XSetForeground(this->_dis, this->_gc, col.pixel);
}
