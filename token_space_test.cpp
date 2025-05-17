/* token_space_test.cpp */

#include <custom_exception.h>
#include <gtest/gtest.h>
#include <token_space.h>

using namespace simulatorlib;

namespace simulatorlibtest {

int number_of_iteration(token_space &s) {
  int rv = 0;
  for (auto i = s.begin(); i != s.end(); i++) {
    rv++;
  }
  return rv;
}

TEST(token_space, thorough_test) {
  token_space s;
  int max_length = token_space::MAX_LENGTH;
  ASSERT_EQ(s.length(), 0);
  s.push('0');
  ASSERT_EQ(s[0], '0');
  ASSERT_EQ(s.length(), 1);
  ASSERT_EQ(number_of_iteration(s), 1);
  for (char ch = '1'; ch <= '9'; ch++) {
    s.push(ch);
  }
  for (char ch = '1'; ch <= '9'; ch++) {
    int index = ch - '1' + 1;
    ASSERT_EQ(s[index], ch);
  }
  ASSERT_EQ(s.length(), 10);
  ASSERT_EQ(number_of_iteration(s), 10);
  for (int i = s.length(); i < max_length; i++) {
    s.push('a');
  }
  ASSERT_EQ(s[max_length - 1], 'a');
  ASSERT_EQ(s.length(), max_length);
  ASSERT_EQ(number_of_iteration(s), max_length);
  s.clear();
  ASSERT_EQ(s.length(), 0);
  ASSERT_EQ(number_of_iteration(s), 0);
}

TEST(token_space, overflow_test) {
  token_space s;
  int max_length = token_space::MAX_LENGTH;
  for (int i = 0; i < max_length; i++)
    s.push('a');
  ASSERT_THROW(s.push('a'), custom_exception);
}

} // namespace simulatorlibtest