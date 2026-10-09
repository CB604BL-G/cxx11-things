#include "callable/is_callable.hpp"
#include "callable/traits.hpp"
#include <cstdio>
#include <string>
#include <type_traits>
#include <utility>
#include <callable/call.hpp>

void func() noexcept {}

struct FuncType
{

	void operator()() noexcept
	{
		std::puts("123");
	}
};

auto main() -> int
{
	cepo::call(func);
	static_assert(cepo::is_nothrow_callable<decltype(func)>::value, "");
}
