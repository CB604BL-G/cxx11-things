#include "callable/call.hpp"
#include "callable/is_callable.hpp"
#include "callable/traits.hpp"
#include <cstdio>
#include <string>
#include <type_traits>
#include <utility>

void func() noexcept {}

struct FuncType
{

	void operator()() noexcept
	{}
};

auto main() -> int
{
	auto foo = [](int) -> std::string {};
	//auto i = cb604bl::cxx11::call(foo, 10);
	//static_assert(cb604bl::cxx11::is_nothrow_callable<decltype(foo), int>::value, "");
}
