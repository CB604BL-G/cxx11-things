//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_CALLABLE_CALL_RESULT_HPP
#define CB604BL_CXX11_THINGS_CALLABLE_CALL_RESULT_HPP

#include "callable/call_category.hpp"
#include "callable/is_callable.hpp"
#include "configs/namespace_macro.h"

CB604BL_CXX11_NAMESPACE_START

namespace callable
{
	//to avoid hard errors
	template<bool callable, typename F, typename... Args>
	struct call_result_impl {};

	template<typename F, typename... Args>
	struct call_result_impl<true, F, Args...>
	{
	private:
		template<typename F_T, typename... Args_T>
		static auto test() ->
			decltype(basic_call_category<F_T, Args_T...>());

		template<typename F_O, typename... Args_O>
		static auto test() ->
			decltype(pointer_to_member_call_by_object_category<F_O, Args_O...>());

		template<typename F_P, typename... Args_P>
		static auto test() ->
			decltype(pointer_to_member_call_by_pointer_category<F_P, Args_P...>());

	public:
		using type = decltype(test<F, Args...>());
	};
}

template<typename F, typename... Args>
struct call_result
	: callable::call_result_impl<is_callable<F, Args...>::value, F, Args...>
{};

CB604BL_CXX11_NAMESPACE_END

#endif //CB604BL_CXX11_THINGS_CALLABLE_CALL_RESULT_HPP
