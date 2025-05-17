#include <gtest/gtest.h>
#include <sequential_bit_message.h>

using namespace simulatorlib;
using namespace std;

namespace simulatorlibtest {
sequential_bit_message B1() {
  vector<uint8_t> v{0xaa};
  sequential_bit_message r{v};
  return r;
}

sequential_bit_message B2() {
  vector<uint8_t> v{0x55, 0xaa};
  sequential_bit_message r{v};
  return r;
}

sequential_bit_message B3() {
  vector<uint8_t> v{0x45, 0x67, 0x89};
  sequential_bit_message r{v};
  return r;
}

sequential_bit_message B8() {
  vector<uint8_t> v{0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0};
  sequential_bit_message r{v};
  return r;
}

sequential_bit_message B9() {
  vector<uint8_t> v{0,0x80, 0, 0, 0, 0, 0, 0, 0x80};
  sequential_bit_message r{v};
  return r;
}

TEST(sequential_bit_message, read_2_to_6) {
  sequential_bit_message b1 = B1();
  b1.seek(2);

  uint64_t r = b1.read(5);
  ASSERT_EQ(r, 0x15);
}

TEST(sequential_bit_message, read_4_to10) {
  sequential_bit_message b = B2();
  b.seek(4);

  uint64_t r = b.read(7);
  ASSERT_EQ(r, 0x2d);
}

TEST(sequential_bit_message, read_6_to_19) {
  sequential_bit_message b = B3();
  b.seek(6);

  uint64_t r = b.read(14);
  ASSERT_EQ(r, 0x1678);
}

TEST(sequential_bit_message, read_0_to_5) {
  sequential_bit_message b = B1();

  uint64_t r = b.read(6);
  ASSERT_EQ(r, 0x2a);
}

TEST(sequential_bit_message, read_0_to_11) {
  sequential_bit_message b = B2();

  uint64_t r = b.read(12);
  ASSERT_EQ(r, 0x055a);
}

TEST(sequential_bit_message, read_7_to_12) {
  sequential_bit_message b = B2();
  b.seek(7);

  uint64_t r = b.read(6);
  ASSERT_EQ(r, 0x35);
}

TEST(sequential_bit_message, read_2_to_8) {
  sequential_bit_message b = B2();
  b.seek(2);

  uint64_t r = b.read(7);
  ASSERT_EQ(r, 0x2b);
}

TEST(sequential_bit_message, read_5_to_15) {
  sequential_bit_message b = B2();
  b.seek(5);

  uint64_t r = b.read(11);
  ASSERT_EQ(r, 0x5aa);
}

TEST(sequential_bit_message, read_7_to_8) {
  sequential_bit_message b = B2();
  b.seek(7);

  uint64_t r = b.read(2);
  ASSERT_EQ(r, 0x03);
}

TEST(sequential_bit_message, read_0_to_7) {
  sequential_bit_message b = B1();

  uint64_t r = b.read(8);
  ASSERT_EQ(r, 0xaa);
}

TEST(sequential_bit_message, read_0_to_23) {
  sequential_bit_message b = B3();

  uint64_t r = b.read(24);
  ASSERT_EQ(r, 0x456789);
}

TEST(sequential_bit_message, read_0_to_63) {
  sequential_bit_message b = B8();

  uint64_t r = b.read(64);
  ASSERT_EQ(r, 0x123456789abcdef0);
}

TEST(sequential_bit_message, read_8_to_71) {
  sequential_bit_message b = B9();
  b.seek(8);
  uint64_t r = b.read(64);
  ASSERT_EQ(r, 0x8000000000000080);
}
} // namespace simulatorlibtest