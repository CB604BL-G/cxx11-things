#include "callable/arg_tuple.hpp"
#include "callable/call_result.hpp"
#include "callable/is_callable.hpp"
#include "callable/traits.hpp"
#include <cstdio>
#include <type_traits>
void func() {}

struct FuncType
{

	void operator()() const & noexcept;
/*	{
		
	}*/
	//void operator()() {};
};

auto main() -> int
{
	auto foo = [&](){};
	auto mem = &FuncType::operator();
	//printf("%lu\n", i);
	static_assert(std::is_same<void, cb604bl::cxx11::call_result<decltype(foo)>::type>::value, "");
}
