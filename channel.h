/* channel.h */

#pragma once

#include <string>

namespace simulatorlib {

enum class channel_status { OPEN, READY, USING, PREPARING };

class channel {
protected:
  channel_status status_ = channel_status::OPEN;
  virtual void clear() = 0;
  std::string name_ = "";

public:
  std::string name() const { return name_; }
  virtual channel_status status() { return status_; }
  virtual void begin_reading() {
    if (status_ != channel_status::OPEN)
      throw "channel " + name_ + " can not call begin reading";
    status_ = channel_status::USING;
  }
  virtual void end_reading() {
    clear();
    status_ = channel_status::OPEN;
  }
  virtual void begin_writing() {
    if (status_ != channel_status::OPEN)
      throw "channel " + name_ + " can not call begin writing";;
    status_ = channel_status::PREPARING;
  }
  virtual void end_writing() { status_ = channel_status::READY; }
};

} // namespace simulatorlib