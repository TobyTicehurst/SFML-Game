#pragma once
#include <memory>

// std::unique_ptr<T> == ptr<T>
template<class T>
using ptr = std::unique_ptr<T>;