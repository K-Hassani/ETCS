/* driver_action__semanticss.h */
#pragma once

#include <command.h>
#include <string>

namespace testscenario {
namespace language {

template <> class subcommand<commands::DRIVER_ACTION> {
public:
  enum class e { POWER_UP_ONBOARD_UNIT, OPEN_DESK, ENTER_DRIVER_ID };
  e parse(std::string s);
  static const int n_driver_actions = 3;

private:
  static std::string all[];
};

using driver_action =
    testscenario::language::subcommand<commands::DRIVER_ACTION>;

using driver_actions =
    testscenario::language::subcommand<commands::DRIVER_ACTION>::e;

} // namespace language
} // namespace testscenario