//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_CALLABLE_CALL_RESULT_HPP
#define CB604BL_CXX11_THINGS_CALLABLE_CALL_RESULT_HPP

#include "callable/is_callable.hpp"
#include "configs/namespace_macro.h"
#include <utility>

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
			decltype(std::declval<F_T>()(std::declval<Args_T>()...));

		template<typename F_CO, typename Obj, typename... Args_CO>
		static auto test() ->
			decltype((std::declval<Obj>().*std::declval<F_CO>())(std::declval<Args_CO>()...));

		template<typename F_CP, typename Ptr, typename... Args_CP>
		static auto test() ->
			decltype((std::declval<Ptr>()->*std::declval<F_CP>())(std::declval<Args_CP>()...));

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
