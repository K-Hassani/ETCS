/* token_fetching.h */

#pragma once

#include "token_space.h"
#include <string>
#include <fstream>

namespace simulatorlib {
class token_fetching {
public:
  token_fetching(token_space &space, std::istream &input_stream);
  void fetch_char();
  void finish();
  bool finished() const;
private:
  token_space &space_;
  std::istream &stream_;
  bool finished_ = false;
};
} // namespace simulatorlib