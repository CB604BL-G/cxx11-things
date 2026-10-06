//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_CALLABLE_IS_CALLABLE_HPP
#define CB604BL_CXX11_THINGS_CALLABLE_IS_CALLABLE_HPP

#include "configs/namespace_macro.h"
#include <type_traits>
#include <utility>

CB604BL_CXX11_NAMESPACE_START

template<typename F, typename... Args>
struct is_callable
{
private:
	template<typename F_T, typename... Args_T>
	static auto test(int) ->
		decltype(std::declval<F_T>()(std::declval<Args_T>()...),
		std::true_type{});

	template<typename F_CO, typename Obj, typename... Args_CO>
	static auto test(int) ->
		decltype(
			(std::declval<Obj>().*std::declval<F_CO>())(std::declval<Args_CO>()...),
			std::true_type{});

	template<typename F_CP, typename Ptr, typename... Args_CP>
	static auto test(int) ->
		decltype(
			(std::declval<Ptr>()->*std::declval<F_CP>())(std::declval<Args_CP>()...),
			std::true_type{});

	template<typename F_U, typename... Args_U>
	static std::false_type test(...);

public:
	static constexpr bool value = decltype(test<F, Args...>(1))::value;
};

CB604BL_CXX11_NAMESPACE_END

#endif //CB604BL_CXX11_THINGS_CALLABLE_IS_CALLABLE_HPP
