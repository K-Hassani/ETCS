/* scenario_feeder.h */

#pragma once

#include <ch1.h>

namespace simulatorlib {
class scenario_feeder {
private:
  ch1 &ch0_;
  ch1 &ch1_;

public:
  scenario_feeder(ch1 &ch0, ch1 &ch) : ch0_{ch0}, ch1_{ch} {}
};
} // namespace simulatorlib
