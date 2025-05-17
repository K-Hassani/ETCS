/* channel_token.h */
#pragma once

#include <channel.h>

namespace simulatorlib {

constexpr int CHANNEL_TOKEN_SIZE = 100;

class channel_token : channel<char[CHANNEL_TOKEN_SIZE]> {
private:
protected:
  void clear() override { buf_[0] = '\0'; }

public:
  channel_token(std::string name) : channel{name} {}
};
} // namespace simulatorlib
