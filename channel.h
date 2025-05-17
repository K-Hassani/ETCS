/* channel.h */

#pragma once

#include <string>

namespace simulatorlib {

enum class channel_status { EMPTY, DATA_READY, USING, PREPARING };

template <class BUFTYPE> /* TODO: restrict BUFTYPE to types which has default
                            constructor */
class channel {
private:
  std::string bad_begin_reading() {
    return "channel " + name_ + " can not call begin reading";
  }
  std::string bad_begin_writing() {
    return "channel " + name_ + " can not call begin writing";
  }
  std::string bad_end_reading() {
    return "channel " + name_ + " can not call end reading";
  }
  std::string bad_end_writing() {
    return "channel " + name_ + " can not call end writing";
  }

protected:
  channel_status status_ = channel_status::EMPTY;
  virtual void clear() = 0;
  std::string name_;
  BUFTYPE buf_;

public:
  channel(std::string name) : name_{name}, buf_{} {}
  ~channel() {
    if (status_ != channel_status::EMPTY) clear();
  }

  std::string name() const { return name_; }

  channel_status status() const { return status_; }

  void begin_reading() {
    if (status_ != channel_status::EMPTY) throw bad_begin_reading();
    status_ = channel_status::USING;
  }

  void end_reading() {
    if (status_ != channel_status::USING) throw bad_end_reading();
    clear();
    status_ = channel_status::EMPTY;
  }

  void begin_writing() {
    if (status_ != channel_status::EMPTY) throw bad_begin_writing();
    status_ = channel_status::PREPARING;
  }

  void end_writing() {
    if (status_ != channel_status::PREPARING) throw bad_end_writing();
    status_ = channel_status::DATA_READY;
  }
};

} // namespace simulatorlib