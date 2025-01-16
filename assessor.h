/* assessor.h */

#pragma once

#include <ch1.h>
#include <g1.h>

namespace simulatorlib {
class assessor {
private:
  g1 &g1_;
  ch1 &ch2_;
  ch1 &ch3_;
  ch1 &ch4_;

public:
  assessor(g1 &g, ch1 &ch2, ch1 &ch3, ch1 &ch4)
      : g1_{g}, ch2_{ch2}, ch3_{ch3}, ch4_{ch4} {};
};
} // namespace simulatorlib
