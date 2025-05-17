/* channel_parsed.h */
#pragma once

#include <channel.h>
#include <string>
#include <vector>

namespace simulatorlib {
struct statement_parsed {
private:
  std::string *command_;
  std::string *subcommand_;
  std::vector<std::string *> var_names_;
  std::vector<std::string> var_values_;
  std::vector<std::string *> additional_names_;
  std::vector<std::string> additional_values_;

public:
  statement_parsed(std::string *command, std::string *subcommand)
      : command_{command}, subcommand_{subcommand} {}

  void clear() {
    command_ = nullptr;
    subcommand_ = nullptr;
    var_names_.clear();
    var_values_.clear();
    additional_names_.clear();
    additional_values_.clear();
  }
};

class channel_parsed : channel<statement_parsed> {
private:
  /* data */
protected:
  void clear() override { buf_.clear(); }

public:
  channel_parsed(std::string name) : channel{name} {};
};

} // namespace simulatorlib
