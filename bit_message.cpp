#include "../header/bit_message.h"
#include <cassert>
#include <cstdint>
#include <stdexcept>

namespace simulatorlib {
bit_message::~bit_message() { delete[] arr_; }

bit_message::bit_message(const bit_message &b) {
  bit_size_ = b.bit_size_;
  int byte_size = (bit_size_ + 7) / 8;
  arr_ = new uint8_t[byte_size];
  for (int i = 0; i < byte_size; i++)
    arr_[i] = b.arr_[i];
}

bit_message::bit_message(bit_message &&b) {
  bit_size_ = b.bit_size_;
  arr_ = b.arr_;
  b.arr_ = nullptr;
}

struct bit_rw {
  uint8_t *buf;
  int byte_index;
  uint8_t bit_mask;
  bit_rw(int bit_index_in_message, uint8_t *b)
      : buf{b}, byte_index{bit_index_in_message / 8},
        bit_mask{(uint8_t)(0x80 >> (bit_index_in_message % 8))} {}

  inline void write_zero() {
    buf[byte_index] &= ~bit_mask;
    next();
  }
  inline void write_one() {
    buf[byte_index] |= bit_mask;
    next();
  }
  inline uint8_t read_bit() {
    uint8_t result = buf[byte_index] & bit_mask;
    next();
    return result;
  }
  inline void next() {
    if (bit_mask == 1) {
      bit_mask = 0x80;
      byte_index++;
    } else bit_mask >>= 1;
  }
};

uint64_t bit_message::read_variable(int start, int number_of_bits) const {
  if (start < 0 || number_of_bits < 0 || start + number_of_bits > bit_size_ * 8)
    throw std::out_of_range("read out of range of bit-message");

  uint64_t result = 0;
  bit_rw reader{start, arr_};
  for (int i = 0; i < number_of_bits; i++) {
    result <<= 1;
    if (reader.read_bit() != 0) result++;
  }
  return result;
}

void bit_message::write_variable(int start, int number_of_bits,
                                 uint64_t value) {
  if (start < 0 || number_of_bits < 0 || start + number_of_bits > bit_size_ * 8)
    throw std::out_of_range("write out of range of bit-message");
  assert(number_of_bits > 0);

  bit_rw writer{start, arr_};
  uint64_t value_mask = 1 << (number_of_bits - 1);
  for (int i = 0; i < number_of_bits; i++) {
    if ((value_mask & value) == static_cast<uint64_t>(0)) writer.write_zero();
    else writer.write_one();
    value_mask >>= 1;
  }
}
} // namespace simulatorlib