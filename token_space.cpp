/* token_space.cpp */

#include "../header/token_space.h"

#include "../header/custom_exception.h"
#include <cassert>

using ts = simulatorlib::token_space;
using namespace std;

namespace simulatorlib {

const char &ts::operator[](const int index) const {
  assert(index < length());
  return buf_[index];
}

inline const char &ts::first() const {
  assert(last_ > buf_.begin());
  return buf_[0];
}

inline const char &ts::last() const {
  assert(last_ > buf_.begin());
  return *last_;
}

int ts::length() const { return last_ - buf_.begin(); }

void ts::push(char ch) {
  if (length() >= ts::MAX_LENGTH)
    throw custom_exception{"token_space overflow!"};
  *last_ = ch;
  last_++;
}

void ts::clear() { last_ = buf_.begin(); }

std::array<char, ts::MAX_LENGTH>::iterator ts::begin() { return buf_.begin(); }

std::array<char, ts::MAX_LENGTH>::iterator ts::end() { return last_; }

} // namespace simulatorlib
