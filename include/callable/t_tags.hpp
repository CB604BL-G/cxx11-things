//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_CALLABLE_T_TAGS_HPP
#define CB604BL_CXX11_THINGS_CALLABLE_T_TAGS_HPP

#include "configs/namespace_macro.h"

CB604BL_CXX11_NAMESPACE_START

namespace callable
{
	struct is_not_class_type{};
	struct is_class_type{};
	struct is_not_with_a_unique_operator{};
	struct is_with_a_unique_operator{};
}

CB604BL_CXX11_NAMESPACE_END

#endif //CB604BL_CXX11_THINGS_CALLABLE_T_TAGS_HPP
