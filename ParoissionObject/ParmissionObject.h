#pragma once
#include <cstdint>

//this is never "NOW TESTING".

class ParmissionObject {
public:

	typedef std::uint32_t Value;

	ParmissionObject() {}
	ParmissionObject(const Value& N) :P(N) {}

	bool Set(const Value& N) {
		P |= N;
		return 0;
	}
	bool UnSet(const Value& N) {
		P &= (~N);
		return true;
	}

	Value Equal(const Value& N)const {
		return ~(P^N);
	}
	bool Test(const std::size_t& Pos) const {
		return P & (1 << Pos)?true:false;
	}

	const Value& Get() const{
		return P;
	}

protected:
	Value P = 0;
};
