#include <iostream>

#include "ParmissionObject.h"

class TestObject {
public:
	bool Write(int N) {
		bool F = false;
		if (P.Test(1)) { V = N; F = true; }
		return F;
	}
	int Read() {
		return P.Test(0) ? V : 0;
	}

	bool Set(const std::size_t Pos) {
		P.Set(1 << Pos);
		return true;
	}
	bool UnSet(const std::size_t Pos) {
		P.UnSet(1 << Pos);
		return true;
	}
	int Get() {
		return V;
	}
	const ParmissionObject& Parmission() {
		return P;
	}
protected:
	ParmissionObject P;
	int V = 0;
};

int main() {
	{
		ParmissionObject PO;

		std::cout << (1 << 0) << std::endl;

		PO.Set(1 << 0);
		if (PO.Test(0)) {
			std::cout << "Set!" << std::endl;
		}
		PO.Set(1 << 1);
		if (PO.Test(1)) {
			std::cout << "Set!" << std::endl;
		}
		PO.Set(1 << 2);

		PO.UnSet(1 << 1);
		std::cout << (int)PO.Get() << std::endl;
		PO.UnSet(1 << 0 | 1 << 2);
		std::cout << (int)PO.Get() << std::endl;
	}
	std::cout << std::endl << "---" << std::endl << std::endl;
	{
		TestObject T;
		T.Set(1);
		T.Write(0xdeadbeef);
		T.UnSet(1);
		T.Write(0xBeef);

		std::cout << T.Read() << std::endl;
		T.Set(0);
		std::cout << T.Read() << std::endl;
		T.UnSet(0);
		std::cout << T.Read() << std::endl;		

	}
	return 0;
}