
#ifndef _DATA_HPP_
#define _DATA_HPP_
#include <iostream>

struct Data
{
	std::string	s1;
	int 		n;
	std::string	s2;
};

void *		serialize();
Data *		deserialize( void * raw );

#endif
