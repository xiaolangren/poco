//
// ExpirationDecorator.h
//
// $Id: //poco/1.4/Foundation/include/Poco/ExpirationDecorator.h#1 $
//
// Library: Foundation
// Package: Events
// Module:  ExpirationDecorator
//
// Implementation of the ExpirationDecorator template.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Foundation_ExpirationDecorator_INCLUDED
#define Foundation_ExpirationDecorator_INCLUDED


#include "Poco/Timestamp.h"
#include "Poco/Timespan.h"


namespace Poco {


template <typename TArgs>
class ExpirationDecorator
        /// ExpirationDecorator adds an expiration method to values so that they can be used
        /// with the UniqueExpireCache.
{
public:
        ExpirationDecorator():
		_value(),
		_expiresAt()
	{
	}

	ExpirationDecorator(const TArgs& p, const Poco::Timespan::TimeDiff& diffInMs):
			/// Creates an element that will expire in diff milliseconds
		_value(p),
		_expiresAt()
	{
		_expiresAt += (diffInMs*1000);
	}

	ExpirationDecorator(const TArgs& p, const Poco::Timespan& timeSpan):
		/// Creates an element that will expire after the given timeSpan
		_value(p),
		_expiresAt()
	{
		_expiresAt += timeSpan.totalMicroseconds();
	}

	ExpirationDecorator(const TArgs& p, const Poco::Timestamp& timeStamp):
		/// Creates an element that will expire at the given time point
		_value(p),
		_expiresAt(timeStamp)
	{
	}


	~ExpirationDecorator()
	{
	}
	
	const Poco::Timestamp& getExpiration() const
	{
		return _expiresAt;
	}

	const TArgs& value() const
	{
		return _value;
	}

	TArgs& value()
	{
		return _value;
	}

private:
	TArgs     _value;
	Timestamp _expiresAt;
};


} // namespace Poco


#endif // Foundation_ExpirationDecorator_INCLUDED
