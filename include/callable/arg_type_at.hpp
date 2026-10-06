//Copyright (c) 2026 CB604BL
#ifndef CB604BL_CXX11_THINGS_CALLABLE_ARG_TYPE_AT_HPP
#define CB604BL_CXX11_THINGS_CALLABLE_ARG_TYPE_AT_HPP

#include "callable/traits.hpp"
#include "configs/namespace_macro.h"
#include <cstddef>

CB604BL_CXX11_NAMESPACE_START

template<typename Callable, std::size_t index>
using arg_type_at = typename callable_traits<Callable>::template arg_type_at<index>;

CB604BL_CXX11_NAMESPACE_END

#endif //CB604BL_CXX11_THINGS_CALLABLE_ARG_TYPE_AT_HPP
