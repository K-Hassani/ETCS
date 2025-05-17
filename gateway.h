/* gateway.h */

#pragma once

#include <channel.h>

namespace simulatorlib {

template <class TIN, class TOUT> class gateway : channel {
protected:
  TOUT tout_ = TOUT{};
  virtual TOUT transform(TIN tin) = 0;

public:
  virtual void set_buffer(TIN &value) {
    if (status_ != channel_status::PREPARING)
      throw throw "channel " + name_ + " can not set buffer";
    tout_ = transform(value);
  }

  virtual TOUT get_buffer_value() { return tout_; }
};
} // namespace simulatorlib
