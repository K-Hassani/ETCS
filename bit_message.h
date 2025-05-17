#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

namespace simulatorlib {

class bit_message {
private:
  int bit_size_;
  uint8_t *arr_;

public:
  bit_message(int size_in_bits) /* assert(size_in_bits > 0) */
      : bit_size_{size_in_bits} {
    int byte_size = (bit_size_ + 7) / 8;
    arr_ = new uint8_t[byte_size];
    for (int i = 0; i < byte_size; i++)
      arr_[i] = 0;
  }
  bit_message(std::vector<uint8_t> &values)
      : bit_size_{static_cast<int>(values.size()) * 8},
        arr_{new uint8_t[values.size()]} {
    for (std::size_t i = 0; i < values.size(); i++) {
      arr_[i] = values[i];
    }
  }
  ~bit_message();
  bit_message(const bit_message &b);
  bit_message(bit_message &&b);
  // bit_message &operator=(const bit_message &b);
  // bit_message &operator=(bit_message &&b);

  uint8_t operator[](int index) const { return arr_[index]; }

  uint64_t read_variable(int start, int number_of_bits) const;
  void write_variable(int start, int number_of_bits, uint64_t value);
};
} // namespace simulatorlib