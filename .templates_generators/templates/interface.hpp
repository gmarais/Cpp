
#ifndef _ClassName_CLASS_
#define _ClassName_CLASS_

#include <iostream>

class	ClassName
{
private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	ClassName();
	ClassName(ClassName const & src);

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	virtual ~ClassName();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	ClassName &	operator=(ClassName const & rhs);

};

#endif
