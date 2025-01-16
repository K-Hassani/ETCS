/* output_writer.h */

#pragma once

#include <ch1.h>

namespace simulatorlib {
class output_writer {
private:
  ch1 &inbuf_;

public:
  output_writer(ch1 &input_buffer) : inbuf_{input_buffer} {};
};
} // namespace simulatorlib
