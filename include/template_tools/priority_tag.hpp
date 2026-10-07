//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_TEMPLATE_TOOLS_PRIORITY_TAG_HPP
#define CB604BL_CXX11_THINGS_TEMPLATE_TOOLS_PRIORITY_TAG_HPP

#include "configs/namespace_macro.h"
#include <cstddef>

CB604BL_CXX11_NAMESPACE_START;

template<std::size_t priority>
struct priority_tag : priority_tag<priority - 1> {};

template<>
struct priority_tag<0> {};

CB604BL_CXX11_NAMESPACE_END;

#endif //CB604BL_CXX11_THINGS_TEMPLATE_TOOLS_PRIORITY_TAG_HPP
