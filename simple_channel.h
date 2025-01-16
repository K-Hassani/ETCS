/* simple_channel.h */

#pragma once

#include <channel.h>

namespace simulatorlib {
template <class T> class simple_channel : channel {
protected:
  T value_;
  void clear() override { value_ = T{}; }

public:
  void set(T value) { value_ = value; }
  T get() { return value_; }
};
} // namespace simulatorlib
