#include "callable/traits.hpp"
#include <cstdio>

void func() {}

struct FuncType
{
	void operator()(int, int, bool) const & noexcept{}
	//void operator()() {};
};

auto main() -> int
{
	auto count = cb604bl::cxx11::callable_traits<FuncType>::fixed_arg_count;
	printf("%lu\n", count);
}
