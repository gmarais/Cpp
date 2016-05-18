// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mutantstack.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 20:04:17 by gmarais           #+#    #+#             //
//   Updated: 2015/01/15 20:04:17 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _MutantStack_CLASS_
# define _MutantStack_CLASS_

# include <iostream>
# include <iterator>
# include <algorithm>
# include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	MutantStack();
	MutantStack(MutantStack const & src);
	~MutantStack();
//---------------------------------------------------------/ GETTERS & SETTERS /
//------------------------------------------------------------/ NESTED CLASSES /
	class iterator
	{
		private:
			iterator() {}
		public:
			T*	current;

			iterator(T* curr) :
				current(curr)
			{
			}

			~iterator() {}
			bool		operator!=(const iterator & rhs)
			{
				return this->current != rhs.current();
			}

			iterator&	operator--()
			{
				this->current--;
				return *this;
			}

			iterator	operator--(int postfix)
			{
				iterator old_state = this->current;
				this->current--;
				return old_state;
			}

			iterator&	operator++()
			{
				this->current++;
				return *this;
			}

			iterator	operator++(int postfix)
			{
				iterator old_state = this->current;
				this->current++;
				return old_state;
			}

			iterator&	operator*()
			{
				return *current;
			}
	};
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	iterator	begin();
	iterator	end();
//-----------------------------------------------------------------/ OPERATORS /

};

template <typename T>
template <typename T>
std::ostream&	operator<<(std::ostream & os, const typename MutantStack<T>::iterator & rhs)
{
	return os << *rhs << std::endl;
}
;

#endif
