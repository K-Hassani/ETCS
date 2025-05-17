// /* statement_face.cpp */
// #include <statement_face.h>

// namespace testscenario {
// namespace language {

// statement_face::statement_face(int index_command, int index_subcommand)
//     : command_idx_{index_command}, subcommand_idx_{index_subcommand} {}
// statement_face::statement_face(
//     int index_command, int index_subcommand,
//     std::initializer_list<std::pair<int, std::string>> subcommand_variables)
//     : command_idx_{index_command}, subcommand_idx_{index_subcommand} {
//   for (auto p : subcommand_variables)
//     subcommand_vars_.insert(p);
// }
// statement_face::statement_face(
//     int index_command, int index_subcommand,
//     std::initializer_list<std::pair<int, std::string>> subcommand_variables,
//     std::initializer_list<std::pair<int, std::string>> additional_variables)
//     : command_idx_{index_command}, subcommand_idx_{index_subcommand} {
//   for (auto p : subcommand_variables)
//     subcommand_vars_.insert(p);
//   for (auto p : additional_variables)
//     additional_vars_.insert(p);
// }

// } // namespace language
// } // namespace testscenario