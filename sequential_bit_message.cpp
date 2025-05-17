#include "../header/sequential_bit_message.h"
#include <cstddef>

using sbm = simulatorlib::sequential_bit_message;
using namespace std;

namespace simulatorlib {

sbm::sequential_bit_message(std::size_t size)
: p_{0}, size_{size}, buf_{new uint8_t[size]} {
for (std::size_t i = 0; i < size; i++)
buf_[i] = 0;
}

sbm::sequential_bit_message(std::vector<uint8_t> v)
: p_{0}, size_{v.size() * 8}, buf_{new uint8_t[size_]} {
for (std::size_t i = 0; i < size_; i++)
buf_[i] = v[i];
}

sbm::~sequential_bit_message() { delete[] buf_; }

sbm::sequential_bit_message(const sequential_bit_message &m)
    : p_{m.p_}, size_{m.size_}, buf_{new uint8_t[m.size_]} {
  for (size_t i = 0; i < size_; i++)
    buf_[i] = m.buf_[i];
}

sbm::sequential_bit_message(sequential_bit_message &&m)
    : p_{m.p_}, size_{m.size_} {
  buf_ = m.buf_;
  m.buf_ = nullptr;
}

// sequential_bit_message &sbm::operator=(const sequential_bit_message &m) {
//   if (&m != this) {
//     p_ = m.p_;
//     size_ = m.size_;
//     delete[] buf_;
//     buf_ = new uint8_t[size_];
//     for (size_t i = 0; i < size_; i++)
//       buf_[i] = m.buf_[i];
//   }
//   return *this;
// }

// sequential_bit_message &sbm::operator=(sequential_bit_message &&m) {
//   if (&m != this) {
//     p_ = m.p_;
//     size_ = m.size_;
//     delete[] buf_;
//     buf_ = m.buf_;
//     m.buf_ = nullptr;
//   }
//   return *this;
// }

uint64_t sbm::read(size_t n) {
  assert(n >= 0);
  assert(n <=64);
  assert(p_ + n <= size_);

  uint64_t r = 0;
  int index_s = p_ / 8;
  int offset_s = p_ - index_s * 8;
  int index_e = (p_ + n - 1) / 8;
  int offset_e = (p_ + n - 1) - index_e * 8;
  r = (uint64_t)(buf_[index_s] & (0xFF >> offset_s));
  if (index_e == index_s)
    r >>= (7 - offset_e);
  else {
    for (int i = index_s + 1; i < index_e; i++) {
      r <<= 8;
      r |= (uint64_t)buf_[i];
    }
    r <<= (offset_e + 1);
    r |= (uint64_t)(buf_[index_e] >> (7 - offset_e));
  }
  p_ += n;
  return r;
}

} // namespace simulatorlib