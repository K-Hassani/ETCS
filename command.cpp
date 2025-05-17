/* command.cpp */

#include "command.h"

namespace testscenario {
namespace language {
std::string command::all[] = {"DRIVER_ACTION", "WAIT", "EXPECT"};

// commands command::parse(std::string s) {
//   throw "not implemented";
//   // for (int i = 0; i < n_commands; i++) {
//   //   if (all[i] == s) return static_cast<commands>(i);
//   //   throw "parse of " + s + " as a command failed";
//   // }
// }
} // namespace language
} // namespace testscenario