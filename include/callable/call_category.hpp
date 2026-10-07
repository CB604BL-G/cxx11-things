//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_CALLABLE_CALL_CATEGORY_HPP
#define CB604BL_CXX11_THINGS_CALLABLE_CALL_CATEGORY_HPP

#include "configs/namespace_macro.h"
#include "template_tools/priority_tag.hpp"
#include <utility>		// IWYU pragma: keep

//These are macros that store expressions
#define CB604BL_CXX11_CALLABLE_CALL_CATEGORY_EXPR_BASIC_CALL(F, Args) \
	(std::declval<F>()(std::declval<Args>()...))

#define CB604BL_CXX11_CALLABLE_CALL_CATEGORY_EXPR_POINTER_TO_MEMBER_CALL_BY_OBJECT(F, Obj, Args) \
	((std::declval<Obj>().*std::declval<F>())(std::declval<Args>()...))

#define CB604BL_CXX11_CALLABLE_CALL_CATEGORY_EXPR_POINTER_TO_MEMBER_CALL_BY_POINTER(F, Ptr, Args) \
	((std::declval<Ptr>()->*std::declval<F>())(std::declval<Args>()...))

CB604BL_CXX11_NAMESPACE_START;

namespace callable
{
	struct basic_call_category{};
	struct pointer_to_member_call_by_object{};
	struct pointer_to_member_call_by_pointer{};

	//Use is_callable to check it first before using
	template<typename F, typename... Args>
	struct get_call_category
	{
	private:
		template<typename F_T, typename... Args_T>
		static auto test(priority_tag<2>) ->
			decltype(
				CB604BL_CXX11_CALLABLE_CALL_CATEGORY_EXPR_BASIC_CALL(F_T, Args_T),
				basic_call_category{});

		template<typename F_O, typename Obj, typename... Args_O>
		static auto test(priority_tag<1>) ->
			decltype(
				CB604BL_CXX11_CALLABLE_CALL_CATEGORY_EXPR_POINTER_TO_MEMBER_CALL_BY_OBJECT(F_O, Obj, Args_O),
				pointer_to_member_call_by_object{});

		template<typename F_P, typename Ptr, typename... Args_P>
		static auto test(priority_tag<0>) ->
			decltype(
				CB604BL_CXX11_CALLABLE_CALL_CATEGORY_EXPR_POINTER_TO_MEMBER_CALL_BY_POINTER(F_P, Ptr, Args_P),
				pointer_to_member_call_by_pointer{});

	public:
		using type = decltype(test<F, Args...>(priority_tag<2>{}));
	};
}

CB604BL_CXX11_NAMESPACE_END;

#endif //CB604BL_CXX11_THINGS_CALLABLE_CALL_CATEGORY_HPP
