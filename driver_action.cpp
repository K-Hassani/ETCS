/* driver_action.cpp */
#include <driver_action.h>
#include <parse_enum.h>

namespace testscenario {
namespace language {

driver_actions subcommand<commands::DRIVER_ACTION>::parse(std::string s) {
  return tparse<driver_actions, all, n_driver_actions>(s);
}

std::string driver_action::all[]{"POWER_UP_ONBOARD_UNIT", "OPEN_DESK",
                                       "ENTER_DRIVER_ID"};

} // namespace language
} // namespace testscenario