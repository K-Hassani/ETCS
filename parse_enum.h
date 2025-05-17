/* parse_enum.h */
#pragma once

#include <string>
#include <type_traits>

template <class E, std::string *all, int len> E tparse(std::string s);
