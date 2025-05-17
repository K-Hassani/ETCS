// /* expect_semantics.h */
// #pragma once

// #include <command_semantics.h>
// #include <map>
// #include <string>

// namespace testscenario {
// namespace semantics {

// enum class expect_titles {
//   JRU_001_GENERAL,
//   JRU_038_CAB_STATUS,
//   DMI_SYMBOL_IS_DISPLAYED,
//   DMI_DRIVER_ID_ENTRY_REQUEST,
// };

// enum class expect_ranges {
//   IMMEDIATE_CYCLE,
//   FOR_CYCLES
// };

// template <>
// class command_semantics<domains::EXPECT> {
// private:
//   const expect_titles title_;
//   std::map<std::string, std::string> name_value_;
//   std::map<std::string, expect_ranges> range_;

// public:
//   command_semantics(const expect_titles title) : title_{title} {}

//   command_semantics(
//       const expect_titles title,
//       std::initializer_list<std::pair<const std::string, std::string>> vars)
//       : title_{title}, name_value_{vars}, range_{} {}

//   command_semantics(
//       const expect_titles title,
//       std::initializer_list<std::pair<const std::string, std::string>> vars,
//       std::initializer_list<std::pair<const std::string, std::string>> ranges)
//       : title_{title}, name_value_{vars}, range_{ranges} {}

//   void add_variable(std::string name, std::string value) {
//     assert(name_value_.find(name) == name_value_.end());

//     name_value_.insert(std::pair<std::string, std::string>{name, value});
//   }

//   void add_range(std::string name, std::string value) {
//     assert(name_value_.find(name) == name_value_.end());

//     range_.insert(std::pair<std::string, std::string>{name, value});
//   }
// };

// using driver_action_semantics = command_semantics<domains::DRIVER_ACTION>;

// } // namespace semantics
// } // namespace testscenario