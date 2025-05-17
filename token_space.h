/* token_space.h */

#pragma once

#include <array>
#include <cassert>

namespace simulatorlib {

class token_space {
public:
  static const int MAX_LENGTH = 50;
  const char &operator[](const int index) const;
  const char &first() const;
  const char &last() const;
  int length() const;
  void push(char ch);
  void clear();
  std::array<char, MAX_LENGTH>::iterator begin();
  std::array<char, MAX_LENGTH>::iterator end();

private:
  std::array<char, MAX_LENGTH> buf_;
  std::array<char, MAX_LENGTH>::iterator last_ = buf_.begin();
};

} // namespace simulatorlib