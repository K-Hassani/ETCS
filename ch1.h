/* ch1.h */

#pragma once

#include <simple_channel.h>
#include <string>

namespace simulatorlib {
class ch1 : simple_channel<std::string> {
public:
  ch1(){};
};
} // namespace simulatorlib