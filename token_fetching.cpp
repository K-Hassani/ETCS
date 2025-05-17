/* token_fetching.cpp */

#include "../header/token_fetching.h"
#include <fstream>

using tf = simulatorlib::token_fetching;
using namespace std;

namespace simulatorlib {
tf::token_fetching(token_space &space, std::istream &input_stream)
    : space_{space}, stream_{input_stream} {}

void tf::fetch_char() {
  if (!finished_) {
    char ch;
    if (stream_ >> ch) space_.push(ch);
    else finished_ = true;
  }
}

void tf::finish() { finished_ = true; }

bool tf::finished() const { return finished_; }
} // namespace simulatorlib