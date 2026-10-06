//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_CALLABLE_IS_CALLABLE_HPP
#define CB604BL_CXX11_THINGS_CALLABLE_IS_CALLABLE_HPP

#include "callable/call_category.hpp"
#include "configs/namespace_macro.h"
#include <type_traits>

CB604BL_CXX11_NAMESPACE_START

template<typename F, typename... Args>
struct is_callable
{
private:
	template<typename F_T, typename... Args_T>
	static auto test(int) ->
		decltype(callable::basic_call_category<F_T, Args_T...>(),
		std::true_type{});

	template<typename F_O, typename... Args_O>
	static auto test(int) ->
		decltype(
			callable::pointer_to_member_call_by_object_category<F_O, Args_O...>(),
			std::true_type{});

	template<typename F_P, typename... Args_P>
	static auto test(int) ->
		decltype(
			callable::pointer_to_member_call_by_pointer_category<F_P, Args_P...>(),
			std::true_type{});

	template<typename F_U, typename... Args_U>
	static std::false_type test(...);

public:
	static constexpr bool value = decltype(test<F, Args...>(1))::value;
};

template<typename F, typename... Args>
constexpr bool is_callable<F, Args...>::value;

CB604BL_CXX11_NAMESPACE_END

#endif //CB604BL_CXX11_THINGS_CALLABLE_IS_CALLABLE_HPP
