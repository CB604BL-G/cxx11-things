//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_CALLABLE_IS_CALLABLE_HPP
#define CB604BL_CXX11_THINGS_CALLABLE_IS_CALLABLE_HPP

#include "callable/call_category.hpp"
#include "configs/namespace_macro.h"
#include "template_tools/priority_tag.hpp"
#include <type_traits>

CB604BL_CXX11_NAMESPACE_START;

#define BASIC_CALL(F, Args) \
	CB604BL_CXX11_CALLABLE_CALL_CATEGORY_EXPR_BASIC_CALL(F, Args)

#define POINTER_TO_MEMBER_CALL_BY_OBJECT(F, Obj, Args) \
	CB604BL_CXX11_CALLABLE_CALL_CATEGORY_EXPR_POINTER_TO_MEMBER_CALL_BY_OBJECT(F, Obj, Args)

#define POINTER_TO_MEMBER_CALL_BY_POINTER(F, Ptr, Args) \
	CB604BL_CXX11_CALLABLE_CALL_CATEGORY_EXPR_POINTER_TO_MEMBER_CALL_BY_POINTER(F, Ptr, Args)

template<typename F, typename... Args>
struct is_callable
{
private:
	template<typename F_T, typename... Args_T>
	static auto test(priority_tag<2>) ->
		decltype(BASIC_CALL(F_T, Args_T),
		std::true_type{});

	template<typename F_O, typename Obj, typename... Args_O>
	static auto test(priority_tag<1>) ->
		decltype(
			POINTER_TO_MEMBER_CALL_BY_OBJECT(F_O, Obj, Args_O),
			std::true_type{});

	template<typename F_P, typename Ptr, typename... Args_P>
	static auto test(priority_tag<0>) ->
		decltype(
			POINTER_TO_MEMBER_CALL_BY_POINTER(F_P, Ptr, Args_P),
			std::true_type{});

	template<typename...>
	static std::false_type test(...);

public:
	static constexpr bool value = decltype(test<F, Args...>(priority_tag<2>{}))::value;
};

template<typename F, typename... Args>
struct is_nothrow_callable
{
private:
	template<typename F_T, typename... Args_T>
	static auto test(int) ->
		std::integral_constant<bool, noexcept(BASIC_CALL(F_T, Args_T))>;

	template<typename...>
	static std::false_type test(...);

	//In C++11/14, noexcept is not part of the function type, so
	//member function pointers and function pointers lose the
	//noexcept information. Detection via those categories always
	//yields false; only direct call expressions (functors, lambdas,
	//named functions) can be reliably checked.

public:
	static constexpr bool value = decltype(test<F, Args...>(1))::value;
};

template<typename F, typename... Args>
constexpr bool is_callable<F, Args...>::value;

template<typename F, typename... Args>
constexpr bool is_nothrow_callable<F, Args...>::value;

#undef BASIC_CALL
#undef POINTER_TO_MEMBER_CALL_BY_OBJECT
#undef POINTER_TO_MEMBER_CALL_BY_POINTER

CB604BL_CXX11_NAMESPACE_END;

#endif //CB604BL_CXX11_THINGS_CALLABLE_IS_CALLABLE_HPP
