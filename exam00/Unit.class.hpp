// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Unit.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 19:00:30 by exam              #+#    #+#             //
//   Updated: 2015/01/09 22:54:06 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#ifndef _UNIT_CLASS_HPP_
#define _UNIT_CLASS_HPP_
#include <iostream>
#include <string>

class Unit
{
private:
//----------------------------------------------------------/ PRIVATE VARIABLES/
	static int	_instances_count;
//----------------------------------------------------------/ PRIVATE FUNCTIONS/
protected:
//--------------------------------------------------------/ PROTECTED VARIABLES/
	int			_index;
	std::string	_type;
	int			_x;
	int			_y;
	int			_damage;
	int			_hp;
	int			_max_hp;

//--------------------------------------------------------/ PROTECTED FUNCTIONS/
public:
//-----------------------------------------------------------/ PUBLIC VARIABLES/
//-----------------------------------------------------/ CONSTRUCTS & DESTRUCTS/
	Unit();
	Unit(std::string type, int x, int y, int damage, int hp, int max_hp);
	Unit(Unit & src);
	virtual ~Unit();
//------------------------------------------------------------------/ OPERATORS/
	Unit &				operator=(const Unit & src);
	void				operator+=(int rhs);
	void				operator-=(int rhs);
//--------------------------------------------------------------------/ GETTERS/
	int					getIndex() const;
	std::string const &	getType() const;
	int					getX() const;
	int					getY() const;
	int					getDam() const;
	int					getCHP() const;
	int					getMHP() const;
//-----------------------------------------------------------/ PUBLIC FUNCTIONS/
	virtual void		die();
	virtual void		move(int x, int y);
	void				attack( Unit & target ) const;
	
};

std::ostream &		operator<<(std::ostream & os, Unit & u);

#endif
