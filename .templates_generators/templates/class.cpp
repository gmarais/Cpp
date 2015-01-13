
#include "ClassName{exthpp}"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
ClassName::ClassName()
{
}

ClassName::ClassName(ClassName const & src)
{
	*this = src;
}


ClassName::~ClassName()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
//-----------------------------------------------------------------/ FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
ClassName &	ClassName::operator=(ClassName const & rhs)
{
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
