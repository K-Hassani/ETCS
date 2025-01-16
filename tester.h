/* tester.h */

#pragma once

#include <assessor.h>
#include <ch1.h>
#include <g1.h>
#include <kernel_driver.h>
#include <output_writer.h>
#include <scenario_feeder.h>
#include <simulator.h>

namespace simulatorlib {
class tester {
private:
  scenario_feeder *sf_;
  assessor *assess_;
  kernel_driver *kd_;
  output_writer *ow_;
  simulator &sim_;

  ch1 *ch0_{new ch1{}};
  ch1 *ch1_{new ch1{}};
  ch1 *ch2_{new ch1{}};
  ch1 *ch3_{new ch1{}};
  ch1 *ch4_{new ch1{}};
  g1 *g1_{new g1{}};
  scenario_feeder *sf_{new scenario_feeder{*ch0_, *ch1_}};
  assessor *a_{new assessor{*g1_, *ch2_, *ch3_, *ch4_}};
  kernel_driver *kd_{new kernel_driver{*ch2_, *g1_}};
  output_writer *ow_{new output_writer{*ch3_}};
  simulator *sim_{new simulator{*ch1_, *ch2_}};

public:
};

} // namespace simulatorlib
