//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_CALLABLE_CALL_HPP
#define CB604BL_CXX11_THINGS_CALLABLE_CALL_HPP

#include "callable/call_result.hpp"
#include "configs/namespace_macro.h"
#include <type_traits>
#include <utility>

CB604BL_CXX11_NAMESPACE_START;

namespace callable
{
	template<typename Ret, bool is_void_ret = std::is_void<Ret>::value>
	struct is_void_return_type_impl {};

	template<typename Ret>
	struct is_void_return_type_impl<Ret, false>
	{
		using type = Ret;
	};

	template<typename T>
	struct is_void_return_type
		: is_void_return_type_impl<T>
	{};
}

//Not finished
template<typename F, typename... Args>
typename callable::is_void_return_type<typename call_result<F, Args...>::type>::type
call(F&& f, Args&&... args)
{
	return std::forward<F>(f)(std::forward<Args>(args)...);
}

template<typename F, typename... Args>
typename std::enable_if<std::is_void<typename call_result<F, Args...>::type>::value>::type
call(F&& f, Args&&... args)
{
	std::forward<F>(f)(std::forward<Args>(args)...);
}

CB604BL_CXX11_NAMESPACE_END;

#endif //CB604BL_CXX11_THINGS_CALLABLE_CALL_HPP
