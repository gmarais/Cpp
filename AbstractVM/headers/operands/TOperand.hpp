// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TOperand.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/26 20:07:08 by gmarais           #+#    #+#             //
//   Updated: 2016/04/26 20:07:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _TOperand_CLASS_
# define _TOperand_CLASS_

# include "Tools.hpp"
# include "IOperand.hpp"
# include "eOperandType.hpp"
# include <stdexcept>

/*
typedef struct s_operand {
	eOperandType	type;
	std::string   name;
	int		precision;
	long		min;
	long		max;
} t_operand;

static t_operand operands[] =
{
	{Int8, "int8", 0 , -128, 127},
	{Int16, "int16", 1, -32768, 32767},
	{Int32, "int32", 2, -2147483648, 2147483647},
	{Float, "float", 3, -32768, 32767},
	{Double, "double", 4, -2147483648, 2147483647},
};
*/

template <typename T>
class	TOperand : public IOperand
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /

//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
	eOperandType type_;
	T value_;
	long minValue_;
	long maxValue_;
	int precision_;


//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	virtual IOperand const *CreateNew(double const value) const = 0;

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	explicit TOperand( eOperandType const type, double const value, long const minValue, long const maxValue, int const precision )
	{
		type_ = type;
		maxValue_ = maxValue;
		minValue_ = minValue;
		minValue_ = minValue;
		precision_ = precision;
		if (value < this->maxValue_)
		{
			if (value < this->minValue_)
				throw std::logic_error( "Underflow." );
		}
		else
			throw std::logic_error( "Overflow." );
		value_ = value;
	}

	TOperand( TOperand const & src )
	{
		*this = src;
	}

	virtual ~TOperand( void )
	{
	}

//---------------------------------------------------------/ GETTERS & SETTERS /
	virtual long				getMinValue() const
	{
		return minValue_;
	}

	virtual long				getMaxValue() const
	{
		return maxValue_;
	}

	virtual int					getPrecision( void ) const
	{
		return precision_;
	}

	virtual eOperandType		getType( void ) const
	{
		return type_;
	}

//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual std::string const &	toString( void ) const
	{
		std::string *str = new std::string();
		std::ostringstream ss;
		if (type_ == INT8)
			ss << (int)value_;
		else
			ss << value_;
		str->append(ss.str());
		return (*str);
	}

//-----------------------------------------------------------------/ OPERATORS /
	TOperand &	operator=( TOperand const & rhs )
	{
		value_ = static_cast<T>(ft_atod(rhs.toString()));
		type_ = rhs.getType();
		precision_ = rhs.getPrecision();
		return *this;
	}

	virtual IOperand const *	operator+( IOperand const & rhs ) const
	{
		double result;

		result = value_ + ft_atod(rhs.toString());
		if (precision_ >= rhs.getPrecision())
			return this->CreateNew(result);
		TOperand const *rhsp = dynamic_cast<TOperand const *>(&rhs);
		if (rhsp != NULL)
			return rhsp->CreateNew(result);
		throw std::logic_error( "Invalid right hand operand." );
		return NULL;
	}

	virtual IOperand const *	operator-( IOperand const & rhs ) const
	{
		double result;

		result = value_ - ft_atod(rhs.toString());
		if (precision_ >= rhs.getPrecision())
			return this->CreateNew(result);
		TOperand const *rhsp = dynamic_cast<TOperand const *>(&rhs);
		if (rhsp != NULL)
			return rhsp->CreateNew(result);
		throw std::logic_error( "Invalid right hand operand." );
		return NULL;
	}

	virtual IOperand const *	operator*( IOperand const & rhs ) const
	{
		double result;

		result = value_ * ft_atod(rhs.toString());
		if (precision_ >= rhs.getPrecision())
			return this->CreateNew(result);
		TOperand const *rhsp = dynamic_cast<TOperand const *>(&rhs);
		if (rhsp != NULL)
			return rhsp->CreateNew(result);
		throw std::logic_error( "Invalid right hand operand." );
		return NULL;
	}

	virtual IOperand const *	operator/( IOperand const & rhs ) const
	{
		double result;
		double rho = ft_atod(rhs.toString());

		if (rho == 0)
		{
			throw std::logic_error( "Division by 0." );
			return NULL;
		}
		result = value_ / rho;
		if (precision_ >= rhs.getPrecision())
			return this->CreateNew(result);
		TOperand const *rhsp = dynamic_cast<TOperand const *>(&rhs);
		if (rhsp != NULL)
			return rhsp->CreateNew(result);
		throw std::logic_error( "Invalid right hand operand." );
		return NULL;
	}

	virtual IOperand const *	operator%( IOperand const & rhs ) const
	{
		double result;
		double rho = ft_atod(rhs.toString());

		if (rho == 0)
			throw std::logic_error( "Modulo by 0." );
		if (type_ == FLOAT || rhs.getType() == FLOAT )
			throw std::logic_error( "Modulo with float." );
		if (type_ == DOUBLE || rhs.getType() == DOUBLE )
			throw std::logic_error( "Modulo with double." );

		result = value_ * ft_atod(rhs.toString());
		if (precision_ >= rhs.getPrecision())
			return this->CreateNew(result);
		TOperand const *rhsp = dynamic_cast<TOperand const *>(&rhs);
		if (rhsp != NULL)
			return rhsp->CreateNew(result);
		throw std::logic_error( "Invalid right hand operand." );
		return NULL;
	}
};

#endif
