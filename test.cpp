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
	const auto& i = cb604bl::cxx11::arg_tuple<int>::size;
	printf("%lu\n", i);
	static_assert(std::is_same<void, cb604bl::cxx11::callable_traits<decltype(func)>::class_type>::value, "");
}
