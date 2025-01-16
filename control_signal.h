/* control_signal.h */

#pragma once

namespace simulatorlib {

enum control_signal_types {
  BUFFER_IS_READY,
  BUFFER_CLEARED,
  NEXT_CYCLE,
  NEXT_SCENARIO
};

class control_signal {
private:
  control_signal_types type_;
  void *sender_;

public:
  control_signal(void *sender, control_signal_types type)
      : sender_{sender}, type_{type} {}
};
} // namespace simulatorlib
