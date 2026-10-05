//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_CALLABLE_TRAITS_HPP
#define CB604BL_CXX11_THINGS_CALLABLE_TRAITS_HPP

#include "callable/has_unoverloaded_operator.hpp"
#include "callable/t_tags.hpp"
#include "configs/namespace_macro.h"
#include "template_tools/always_false.hpp"
#include <cstddef>
#include <type_traits>

CB604BL_CXX11_NAMESPACE_START

template<typename... Ts>
struct callable_traits
{
	static_assert(
		detail::always_false<Ts...>::value,
		"cb604bl::cxx11::callable_traits: Bro, how the hell did you match up with the master template?"
	);
};

//For function type
template<typename Ret, typename... Args>
struct callable_traits<Ret(Args...)>
{
	static constexpr bool is_c_style_variadic_function = false;
	static constexpr bool is_pointer_to_function = false;
	static constexpr bool is_pointer_to_member_function = false;

	//qualifiers
	static constexpr bool is_const_qualified = false;
	static constexpr bool is_volatile_qualified = false;
	static constexpr bool is_ref_qualified = false;
	static constexpr bool is_lvalue_ref_qualified = false;
	static constexpr bool is_rvalue_ref_qualified = false;

	static constexpr std::size_t fixed_arg_count = sizeof...(Args);
	using return_type = Ret;
};

/*For abominable function type*/
//only-cv qualified
template<typename Ret, typename... Args>
struct callable_traits<Ret(Args...) const>
	: callable_traits<Ret(Args...)>
{
	static constexpr bool is_const_qualified = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args...) volatile>
	: callable_traits<Ret(Args...)>
{
	static constexpr bool is_volatile_qualified = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args...) const volatile>
	: callable_traits<Ret(Args...) const>
{
	static constexpr bool is_volatile_qualified = true;
};

//lvalue-ref qualified
template<typename Ret, typename... Args>
struct callable_traits<Ret(Args...) &>
	: callable_traits<Ret(Args...)>
{
	static constexpr bool is_ref_qualified = true;
	static constexpr bool is_lvalue_ref_qualified = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args...) const &>
	: callable_traits<Ret(Args...) const>
{
	static constexpr bool is_ref_qualified = true;
	static constexpr bool is_lvalue_ref_qualified = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args...) volatile &>
	: callable_traits<Ret(Args...) volatile>
{
	static constexpr bool is_ref_qualified = true;
	static constexpr bool is_lvalue_ref_qualified = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args...) const volatile &>
	: callable_traits<Ret(Args...) const volatile>
{
	static constexpr bool is_ref_qualified = true;
	static constexpr bool is_lvalue_ref_qualified = true;
};

//rvalue-ref qualified
template<typename Ret, typename... Args>
struct callable_traits<Ret(Args...) &&>
	: callable_traits<Ret(Args...)>
{
	static constexpr bool is_ref_qualified = true;
	static constexpr bool is_rvalue_ref_qualified = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args...) const &&>
	: callable_traits<Ret(Args...) const>
{
	static constexpr bool is_ref_qualified = true;
	static constexpr bool is_rvalue_ref_qualified = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args...) volatile &&>
	: callable_traits<Ret(Args...) volatile>
{
	static constexpr bool is_ref_qualified = true;
	static constexpr bool is_rvalue_ref_qualified = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args...) const volatile &&>
	: callable_traits<Ret(Args...) const volatile>
{
	static constexpr bool is_ref_qualified = true;
	static constexpr bool is_rvalue_ref_qualified = true;
};

/*For c-style variadic function type*/
template<typename Ret, typename... Args>
struct callable_traits<Ret(Args..., ...)>
	: callable_traits<Ret(Args...)>
{
	static constexpr bool is_c_style_variadic_function = true;
};

//only-cv qualified
template<typename Ret, typename... Args>
struct callable_traits<Ret(Args..., ...) const>
	: callable_traits<Ret(Args...) const>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args..., ...) volatile>
	: callable_traits<Ret(Args...) volatile>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args..., ...) const volatile>
	: callable_traits<Ret(Args...) const volatile>
{
	static constexpr bool is_c_style_variadic_function = true;
};

//lvalue-ref qualified
template<typename Ret, typename... Args>
struct callable_traits<Ret(Args..., ...) &>
	: callable_traits<Ret(Args...) &>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args..., ...) const &>
	: callable_traits<Ret(Args...) const &>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args..., ...) volatile &>
	: callable_traits<Ret(Args...) volatile &>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args..., ...) const volatile &>
	: callable_traits<Ret(Args...) const volatile &>
{
	static constexpr bool is_c_style_variadic_function = true;
};

//rvalue-ref qualified
template<typename Ret, typename... Args>
struct callable_traits<Ret(Args..., ...) &&>
	: callable_traits<Ret(Args...) &&>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args..., ...) const &&>
	: callable_traits<Ret(Args...) const &&>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args..., ...) volatile &&>
	: callable_traits<Ret(Args...) volatile &&>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(Args..., ...) const volatile &&>
	: callable_traits<Ret(Args...) const volatile &&>
{
	static constexpr bool is_c_style_variadic_function = true;
};

/*For pointer to function type*/
//the type cannot be with any function-qualifiers
template<typename Ret, typename... Args>
struct callable_traits<Ret(*)(Args...)>
	: callable_traits<Ret(Args...)>
{
	static constexpr bool is_pointer_to_function = true;
};

template<typename Ret, typename... Args>
struct callable_traits<Ret(*)(Args..., ...)>
	: callable_traits<Ret(*)(Args...)>
{
	static constexpr bool is_c_style_variadic_function = true;
};

/*For pointer to member function type*/
template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args...)>
	: callable_traits<Ret(Args...)>
{
	static constexpr bool is_pointer_to_member_function = true;
};

//only-cv qualified
template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args...) const>
	: callable_traits<Ret(Args...) const>
{
	static constexpr bool is_pointer_to_member_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args...) volatile>
	: callable_traits<Ret(Args...) volatile>
{
	static constexpr bool is_pointer_to_member_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args...) const volatile>
	: callable_traits<Ret(Args...) const volatile>
{
	static constexpr bool is_pointer_to_member_function = true;
};

//lvalue-ref qualified
template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args...) &>
	: callable_traits<Ret(Args...) &>
{
	static constexpr bool is_pointer_to_member_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args...) const &>
	: callable_traits<Ret(Args...) const &>
{
	static constexpr bool is_pointer_to_member_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args...) volatile &>
	: callable_traits<Ret(Args...) volatile &>
{
	static constexpr bool is_pointer_to_member_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args...) const volatile &>
	: callable_traits<Ret(Args...) const volatile &>
{
	static constexpr bool is_pointer_to_member_function = true;
};

//rvalue-ref qualified
template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args...) &&>
	: callable_traits<Ret(Args...) &&>
{
	static constexpr bool is_pointer_to_member_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args...) const &&>
	: callable_traits<Ret(Args...) const &&>
{
	static constexpr bool is_pointer_to_member_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args...) volatile &&>
	: callable_traits<Ret(Args...) volatile &&>
{
	static constexpr bool is_pointer_to_member_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args...) const volatile &&>
	: callable_traits<Ret(Args...) const volatile &&>
{
	static constexpr bool is_pointer_to_member_function = true;
};

/*For c-style variadic pointer to member function type*/
template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args..., ...)>
	: callable_traits<Ret(T::*)(Args...)>
{
	static constexpr bool is_c_style_variadic_function = true;
};

//only-cv qualified
template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args..., ...) const>
	: callable_traits<Ret(T::*)(Args...) const>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args..., ...) volatile>
	: callable_traits<Ret(T::*)(Args...) volatile>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args..., ...) const volatile>
	: callable_traits<Ret(T::*)(Args...) const volatile>
{
	static constexpr bool is_c_style_variadic_function = true;
};

//lvalue-ref qualified
template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args..., ...) &>
	: callable_traits<Ret(T::*)(Args...) &>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args..., ...) const &>
	: callable_traits<Ret(T::*)(Args...) const &>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args..., ...) volatile &>
	: callable_traits<Ret(T::*)(Args...) volatile &>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args..., ...) const volatile &>
	: callable_traits<Ret(T::*)(Args...) const volatile &>
{
	static constexpr bool is_c_style_variadic_function = true;
};

//rvalue-ref qualified
template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args..., ...) &&>
	: callable_traits<Ret(T::*)(Args...) &&>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args..., ...) const &&>
	: callable_traits<Ret(T::*)(Args...) const &&>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args..., ...) volatile &&>
	: callable_traits<Ret(T::*)(Args...) volatile &&>
{
	static constexpr bool is_c_style_variadic_function = true;
};

template<typename T, typename Ret, typename... Args>
struct callable_traits<Ret(T::*)(Args..., ...) const volatile &&>
	: callable_traits<Ret(T::*)(Args...) const volatile &&>
{
	static constexpr bool is_c_style_variadic_function = true;
};

/*For class types with operator() (functors, lambdas, etc.)*/
template<typename T>
struct callable_traits<T>
	: callable_traits<
		typename std::conditional<std::is_class<T>::value,
			callable_tags::is_class_type, callable_tags::is_not_class_type
		>::type,
		T
	>
{};

template<typename T>
struct callable_traits<callable_tags::is_class_type, T>
	: callable_traits<
		typename std::conditional<has_unoverloaded_operator<T>::value,
			callable_tags::is_with_a_unique_operator, callable_tags::is_not_with_a_unique_operator
		>::type,
		T
	>
{};

template<typename T>
struct callable_traits<callable_tags::is_not_class_type, T>
{
	static_assert(
		detail::always_false<T>::value,
		"cb604bl::cxx11::callable_traits: T is not a callable type");
};

template<typename T>
struct callable_traits<callable_tags::is_not_with_a_unique_operator, T>
{
	static_assert(
		detail::always_false<T>::value,
		"cb604bl::cxx11::callable_traits: T is not a callable type with a unique operator()");
};

template<typename T>
struct callable_traits<callable_tags::is_with_a_unique_operator, T>
	: callable_traits<decltype(&T::operator())>
{};

CB604BL_CXX11_NAMESPACE_END

#endif //CB604BL_CXX11_THINGS_CALLABLE_TRAITS_HPP