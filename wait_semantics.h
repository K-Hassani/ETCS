// /* wait_semantics */
// #pragma once

// #include <command_semantics.h>
// #include <map>
// #include <string>

// namespace testscenario {
// namespace semantics {

// enum class wait_titles { WAIT_FOR_SECONDS };

// class wait_semantics : command_semantics<domains::DRIVER_ACTION> {
// private:
//   //  const wait_titles title_;
//   int value_;

// public:
//   wait_semantics() { this->get_domain(); }
// };

// } // namespace semantics
// } // namespace testscenario