//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_TEMPLATE_TOOLS_ALWAYS_FALSE_HPP
#define CB604BL_CXX11_THINGS_TEMPLATE_TOOLS_ALWAYS_FALSE_HPP

#include "configs/namespace_macro.h"

CB604BL_CXX11_NAMESPACE_START

template<typename... Ts>
struct always_false
{
	static constexpr bool value = false;
};

CB604BL_CXX11_NAMESPACE_END

#endif //CB604BL_CXX11_THINGS_TEMPLATE_TOOLS_ALWAYS_FALSE_HPP
