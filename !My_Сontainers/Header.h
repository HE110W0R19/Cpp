#pragma once
#include <iostream>
namespace gui {
	class A {
	public:
		void print()const { std::cout << "module gui\n"; }
	};
}
namespace MPC {
	class A {
	public:
		void print()const { std::cout << "module MPC\n"; }
	};
}