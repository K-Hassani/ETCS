/* parse_enum.cpp */
#include <parse_enum.h>

namespace testscenario {
namespace language {

template <class E, std::string *all, int len> E tparse(std::string s) {
  static_assert(std::is_enum_v<E> == true);
  for (int i = 0; i < len; i++)
    if (all[i] == s) return static_cast<E>(i);
  throw "inavlid command";
}

} // namespace language
} // namespace testscenario