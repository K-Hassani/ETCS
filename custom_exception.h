/* custom_exception.h */

#pragma once

#include <string>

namespace simulatorlib {
class custom_exception {
private:
  std::string message_;

public:
  custom_exception(std::string msg) : message_{msg} {}
  const std::string &message() const { return message_; }
};
} // namespace simulatorlib