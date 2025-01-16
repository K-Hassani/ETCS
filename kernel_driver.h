/* kernel_driver.h */

#pragma once

#include <ch1.h>
#include <g1.h>

namespace simulatorlib {
class kernel_driver {
private:
  g1 &outbuf_;
  ch1 &inbuf_;

public:
  kernel_driver(ch1 &input_buffer, g1 &output_buffer)
      : inbuf_{input_buffer}, outbuf_{output_buffer} {};
};

} // namespace simulatorlib
