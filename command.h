/* semantics.h */
#pragma once

#include <string>

namespace testscenario {
namespace language {

class command {
public:
  static std::string all[];
  enum class e { DRIVER_ACTION, WAIT, EXPECT };
  e parse(std::string s);

private:
  static constexpr int n_commands = 3;
};

using commands = testscenario::language::command::e;

template <commands c> class subcommand;

// enum class value_types { STRING, ENUM, INTEGER };

} // namespace language
} // namespace testscenario