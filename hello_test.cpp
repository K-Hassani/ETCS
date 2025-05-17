/* hello_test.cpp */

#include <gtest/gtest.h>
#include <simulator.h>

using namespace simulatorlib;

namespace simulatorlibtest
{
TEST(HelloTest, HelloTest)
{
    EXPECT_EQ(hello_test(), 110);
}
} // namespace simulatorlibtest
