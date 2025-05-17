
#include <bit_message.h>
#include <gtest/gtest.h>

using namespace simulatorlib;
using namespace std;

namespace  {

bit_message bit_message_0x43() {
  vector<uint8_t> values{0x43};
  bit_message result{values};
  return result;
}

bit_message bit_message_0x80() {
  vector<uint8_t> values{0x80};
  bit_message result{values};
  return result;
}

bit_message bit_message_0x01() {
  vector<uint8_t> values{0x01};
  bit_message result{values};
  return result;
}

// bit_message bit_message_0x80_0x01() {
//   vector<uint8_t> values{0x80, 0x01};
//   bit_message result{values};
//   return result;
// }

bit_message bit_message_0x12_0x63() {
  vector<uint8_t> values{0x12, 0x63};
  bit_message result{values};
  return result;
}

bit_message bit_message_0x12_0x63_0xcc() {
  vector<uint8_t> values{0x12, 0x63, 0xcc};
  bit_message result{values};
  return result;
}

TEST(bit_message_read_test, read_first_byte) {
  bit_message m = bit_message_0x43();
  EXPECT_EQ(m.read_variable(0, 8), 0x43);
}

TEST(bit_message_read_test, read_first_bit) {
  bit_message m = bit_message_0x80();
  EXPECT_EQ(m.read_variable(0, 1), 1);
}

TEST(bit_message_read_test, read_last_bit) {
  bit_message m = bit_message_0x01();
  EXPECT_EQ(m.read_variable(7, 1), 1);
}

TEST(bit_message_read_test, read_middle_bit) {
  bit_message m = bit_message_0x43();
  EXPECT_EQ(m.read_variable(0, 1), 0);
  EXPECT_EQ(m.read_variable(1, 1), 1);
  EXPECT_EQ(m.read_variable(2, 1), 0);
}

TEST(bit_message_read_test, read_between_two_consecutive_bytes) {
  bit_message m = bit_message_0x12_0x63();
  EXPECT_EQ(m.read_variable(6, 5), 19);
}

TEST(bit_message_read_test, read_from_three_bytes) {
  bit_message m = bit_message_0x12_0x63_0xcc();
  EXPECT_EQ(m.read_variable(5, 13), 2447);
  EXPECT_EQ(m.read_variable(20, 2), 3);
}

TEST(bit_message_read_test, read_complete_three_bytes) {
  bit_message m = bit_message_0x12_0x63_0xcc();
  EXPECT_EQ(m.read_variable(0, 24), 1205196);
}

TEST(bit_message_read_test, read_multiple_variables) {
  bit_message m = bit_message_0x12_0x63_0xcc();
  EXPECT_EQ(m.read_variable(0, 5), 2);
  EXPECT_EQ(m.read_variable(5, 2), 1);
  EXPECT_EQ(m.read_variable(7, 3), 1);
  EXPECT_EQ(m.read_variable(10, 4), 8);
  EXPECT_EQ(m.read_variable(14, 4), 15);
  EXPECT_EQ(m.read_variable(18, 6), 12);
}

} // namespace simulatorlibtest
