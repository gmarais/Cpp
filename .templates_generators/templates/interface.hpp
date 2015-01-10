
#ifndef _ClassName_CLASS_
#define _ClassName_CLASS_

#include <iostream>

class	ClassName
{
private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	ClassName();
	ClassName(ClassName const & src);
	~ClassName();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	ClassName &	operator=(ClassName const & rhs);

};

#endif
