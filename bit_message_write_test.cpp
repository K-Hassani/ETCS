#include <bit_message.h>
#include <gtest/gtest.h>

using namespace simulatorlib;
using namespace std;

TEST(bit_message_write, write_one_first_bit) {
  bit_message m{1};
  m.write_variable(0, 1, 1);
  EXPECT_EQ(m[0], 128);
}

TEST(bit_message_write, write_one_bit_in_middle) {
  bit_message m{6};
  m.write_variable(3, 1, 1);
  EXPECT_EQ(m[0] >> 2, 4);
  EXPECT_EQ(m.read_variable(3, 1), 1);
}

TEST(bit_message_write, write_few_bits_in_middle) {
  bit_message m{6};
  m.write_variable(2, 3, 5);
  EXPECT_EQ(m[0] >> 2, 10);
  EXPECT_EQ(m.read_variable(2, 3), 5);
}

TEST(bit_message_write, write_multiple_variables) {
  bit_message m{10};
  m.write_variable(0, 3, 5);
  m.write_variable(3, 6, 50);
  m.write_variable(9, 1, 1);

  EXPECT_EQ(m[0], 185);
  EXPECT_EQ(m[1], 64);
  EXPECT_EQ(m.read_variable(0, 3), 5);
  EXPECT_EQ(m.read_variable(3, 6), 50);
  EXPECT_EQ(m.read_variable(9, 1), 1);
}