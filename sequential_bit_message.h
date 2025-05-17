#pragma once
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace simulatorlib {
class sequential_bit_message {
private:
  std::size_t p_;
  std::size_t size_;
  uint8_t *buf_;

public:
  sequential_bit_message(std::size_t size);
  sequential_bit_message(std::vector<uint8_t> v);
  ~sequential_bit_message();
  sequential_bit_message(const sequential_bit_message &m);
  sequential_bit_message(sequential_bit_message &&m);
  // sequential_bit_message &operator=(const sequential_bit_message &m);
  // sequential_bit_message &operator=(sequential_bit_message &&m);

  uint64_t read(std::size_t n_bits);
  void seek(std::size_t p) {
    assert(p < size_);
    p_ = p;
  }
};

} // namespace simulatorlib
