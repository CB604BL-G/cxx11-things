//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_CALLABLE_ARG_TUPLE_HPP
#define CB604BL_CXX11_THINGS_CALLABLE_ARG_TUPLE_HPP

#include "configs/namespace_macro.h"
#include <cstddef>

CB604BL_CXX11_NAMESPACE_START

template<typename... Args>
class arg_tuple
{
private:
	template<std::size_t leftover, typename Head, typename... Tail>
	struct get_type_at_impl
	{
		using type = typename get_type_at_impl<leftover - 1, Tail...>::type;
	};

	template<typename Head, typename... Tail>
	struct get_type_at_impl<0, Head, Tail...>
	{
		using type = Head;
	};

	template<std::size_t index, bool valid = (index < sizeof...(Args))>
	struct get_type_at_helper
	{
		using type = void;
	};

	template<std::size_t index>
	struct get_type_at_helper<index, true>
	{
		using type = typename get_type_at_impl<index, Args...>::type;
	};
	
public:
	static constexpr std::size_t size = sizeof...(Args);

	template<std::size_t index>
	struct get_type_at
	{
		static_assert(
			sizeof...(Args) != 0,
			"cb604bl::cxx11::arg_tuple::get_type_at: There is no any parameter to get");

		static_assert(
			index < sizeof...(Args),
			"cb604bl::cxx11::arg_tuple::get_type_at: Out of range");

		using type = typename get_type_at_helper<index>::type;
	};
};

template<typename... Args>
constexpr std::size_t arg_tuple<Args...>::size;

CB604BL_CXX11_NAMESPACE_END

#endif //CB604BL_CXX11_THINGS_CALLABLE_ARG_TUPLE_HPP
