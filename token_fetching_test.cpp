/* token_fetching_test.cpp */

#include <exception>
#include <gtest/gtest.h>
#include <sstream>
#include <token_fetching.h>

using namespace simulatorlib;
using namespace std;

namespace simulatorlibtest {

bool check_content_of_space(token_space &s, string str) {
  if (str.length() != s.length()) return false;
  for (int i = 0; i < s.length(); i++) {
    if (str[i] != s[i]) return false;
  }
  return true;
}

TEST(token_fetching, thorough_test) {
  token_space space;
  istringstream stream{"token"};
  token_fetching f{space, stream};
  ASSERT_TRUE(check_content_of_space(space, ""));
  f.fetch_char();
  ASSERT_TRUE(check_content_of_space(space, "t"));
  ASSERT_FALSE(f.finished());
  f.fetch_char();
  ASSERT_TRUE(check_content_of_space(space, "to"));
  ASSERT_FALSE(f.finished());
  f.fetch_char();
  ASSERT_TRUE(check_content_of_space(space, "tok"));
  ASSERT_FALSE(f.finished());
  f.fetch_char();
  ASSERT_TRUE(check_content_of_space(space, "toke"));
  ASSERT_FALSE(f.finished());
  f.fetch_char();
  ASSERT_TRUE(check_content_of_space(space, "token"));
  ASSERT_FALSE(f.finished());
  f.fetch_char();
  ASSERT_TRUE(check_content_of_space(space, "token"));
  ASSERT_TRUE(f.finished());
  f.fetch_char();
  ASSERT_TRUE(check_content_of_space(space, "token"));
  ASSERT_TRUE(f.finished());
}

TEST(token_fetching, finish_before_end_of_stream) {
  token_space space;
  istringstream stream{"token"};
  token_fetching f{space, stream};
  ASSERT_TRUE(check_content_of_space(space, ""));
  f.fetch_char();
  ASSERT_TRUE(check_content_of_space(space, "t"));
  ASSERT_FALSE(f.finished());
  f.finish();
  ASSERT_TRUE(check_content_of_space(space, "t"));
  ASSERT_TRUE(f.finished());
  f.fetch_char();
  ASSERT_TRUE(check_content_of_space(space, "t"));
  ASSERT_TRUE(f.finished());
}

TEST(token_fetching, finish_before_start) {
  token_space space;
  istringstream stream{"token"};
  token_fetching f{space, stream};
  ASSERT_TRUE(check_content_of_space(space, ""));
  f.finish();
  ASSERT_TRUE(check_content_of_space(space, ""));
  ASSERT_TRUE(f.finished());
  f.fetch_char();
  ASSERT_TRUE(check_content_of_space(space, ""));
  ASSERT_TRUE(f.finished());
}
} // namespace simulatorlibtest