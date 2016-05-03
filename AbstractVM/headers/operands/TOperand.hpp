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
# include <Exception.hpp>

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
				throw Exception( "Underflow." );
		}
		else
			throw Exception( "Overflow." );
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
	virtual IOperand const *CreateNew(double const value) const = 0;
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

	virtual IOperand const *createRightType(double value, IOperand const & rhs) const
	{
		if (rhs.getType() == INT8)
		{
			TOperand<int8_t> const *int8Container = dynamic_cast<TOperand<int8_t> const *>(&rhs);
			return int8Container->CreateNew(value);
		}
		if (rhs.getType() == INT16)
		{
			TOperand<int16_t> const *int16Container = dynamic_cast<TOperand<int16_t> const *>(&rhs);
			return int16Container->CreateNew(value);
		}
		if (rhs.getType() == INT32)
		{
			TOperand<int32_t> const *int32Container = dynamic_cast<TOperand<int32_t> const *>(&rhs);
			return int32Container->CreateNew(value);
		}
		if (rhs.getType() == FLOAT)
		{
			TOperand<float> const *floatContainer = dynamic_cast<TOperand<float> const *>(&rhs);
			return floatContainer->CreateNew(value);
		}
		if (rhs.getType() == DOUBLE)
		{
			TOperand<double> const *doubleContainer = dynamic_cast<TOperand<double> const *>(&rhs);
			return doubleContainer->CreateNew(value);
		}
		throw Exception( "Invalid right hand operand." );
		return NULL;
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
		return createRightType(result, rhs);
	}

	virtual IOperand const *	operator-( IOperand const & rhs ) const
	{
		double result;

		result = value_ - ft_atod(rhs.toString());
		if (precision_ >= rhs.getPrecision())
			return this->CreateNew(result);
		return createRightType(result, rhs);
	}

	virtual IOperand const *	operator*( IOperand const & rhs ) const
	{
		double result;

		result = value_ * ft_atod(rhs.toString());
		if (precision_ >= rhs.getPrecision())
			return this->CreateNew(result);
		return createRightType(result, rhs);
	}

	virtual IOperand const *	operator/( IOperand const & rhs ) const
	{
		double result;
		double rho = ft_atod(rhs.toString());

		if (rho == 0)
		{
			throw Exception( "Division by 0." );
			return NULL;
		}
		result = value_ / rho;
		if (precision_ >= rhs.getPrecision())
			return this->CreateNew(result);
		return createRightType(result, rhs);
	}

	virtual IOperand const *	operator%( IOperand const & rhs ) const
	{
		double result;
		double rho = ft_atod(rhs.toString());

		if (rho == 0)
			throw Exception( "Modulo by 0." );
		if (type_ == FLOAT || rhs.getType() == FLOAT )
			throw Exception( "Modulo with float." );
		if (type_ == DOUBLE || rhs.getType() == DOUBLE )
			throw Exception( "Modulo with double." );

		result = static_cast<int>(value_) % ft_atoi(rhs.toString());
		if (precision_ >= rhs.getPrecision())
			return this->CreateNew(result);
		return createRightType(result, rhs);
	}
};

#endif
