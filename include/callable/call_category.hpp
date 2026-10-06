//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_CALLABLE_CALL_CATEGORY_HPP
#define CB604BL_CXX11_THINGS_CALLABLE_CALL_CATEGORY_HPP

#include "configs/namespace_macro.h"
#include <utility>

CB604BL_CXX11_NAMESPACE_START

namespace callable
{
	//These category types actually represent
	//the return value types corresponding
	//to the respective call categories

	//They're written as template functions
	//because they're naturally SFINAE-friendly
	
	template<typename F, typename... Args>
	auto basic_call_category() ->
		decltype(std::declval<F>()(std::declval<Args>()...));

	template<typename F, typename Obj, typename... Args>
	auto pointer_to_member_call_by_object_category() ->
		decltype((std::declval<Obj>().*std::declval<F>())(std::declval<Args>()...));

	template<typename F, typename Ptr, typename... Args>
	auto pointer_to_member_call_by_pointer_category() ->
		decltype((std::declval<Ptr>()->*std::declval<F>())(std::declval<Args>()...));
}

CB604BL_CXX11_NAMESPACE_END

#endif //CB604BL_CXX11_THINGS_CALLABLE_CALL_CATEGORY_HPP
