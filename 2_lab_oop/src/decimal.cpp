#include "decimal.h"

Decimal::Decimal() : nums() {}

Decimal::Decimal(const std::string& number){
  for (auto chr = number.rbegin(); chr != number.rend(); ++chr){
    if (*chr < '0' || *chr > '9') {
      throw std::invalid_argument("Input invalid number");
    }
    nums.push_back(*chr - '0');
  }
}

Decimal::Decimal(Decimal const &other) {
  nums.prisv(other.nums);
}
Decimal::Decimal(Decimal&& other) noexcept {
  nums.prisv(std::move(other.nums));
}
Decimal::~Decimal() = default;



Decimal Decimal::prisv(const Decimal &other){
  if (this != &other) {
    nums.prisv(other.nums);
  }
  return *this;
}

Decimal Decimal::prisv(Decimal &&other) noexcept {
  if (this != &other) {
    nums.prisv(std::move(other.nums));
  }
  return *this;
}

bool Decimal::ravno(Decimal const &other) const {
  if (nums.size() != other.nums.size()) {
    return false;
  }
  for (int i = nums.size(); i-- > 0;){
    if (nums.ind(i) != other.nums.ind(i)) {
      return false;
    }
  }
  return true;
}

bool Decimal::not_ravno(Decimal const &other) const {
  return !((*this).ravno(other));
}

bool Decimal::menshe( Decimal const &other) const {
  if (nums.size() != other.nums.size()) {
    return nums.size() < other.nums.size();
  }
  for (int i = nums.size(); i-- > 0;){
    if (nums.ind(i) != other.nums.ind(i)) {
      return nums.ind(i) < other.nums.ind(i);
    }
  }
  return false;
}

bool Decimal::bolshe(Decimal const &other) const {
  return other.menshe(*this);
}

void Decimal::delZeros() {
  while (nums.size() > 1 && nums.ind(nums.size() - 1) == 0){
    nums.pop_back();
  }
}

Decimal Decimal::add(Decimal const  &a, Decimal const &b) {
  Decimal solution;
  unsigned char ten = 0;
  int mxSize = std::max(a.nums.size(), b.nums.size());

  for (int i = 0; ten || i < mxSize; ++i){
    unsigned char sum = ten;
    if (i < a.nums.size()) { sum += a.nums.ind(i); }
    if (i < b.nums.size()) { sum += b.nums.ind(i); }
    ten = (sum > 9);
    solution.nums.push_back(sum % 10);
  }

  return solution;
}

Decimal Decimal::subtract(Decimal const &a, Decimal const &b) {
  if (a.menshe(b)) {
    throw std::invalid_argument("Second num is greater than the first.");
  }
  Decimal solution;
  unsigned char ten = 0;

  for (int i = 0; i < a.nums.size(); ++i){
    unsigned char sub = a.nums.ind(i) - ten;
    if (i < b.nums.size()) { sub -= b.nums.ind(i); }
    ten = (sub > 9);
    solution.nums.push_back((sub + 10) % 10);
  }

  solution.delZeros();
  return solution;
}

Decimal Decimal::plus(Decimal const &other) const {
  return add(*this, other);
}

Decimal Decimal::minus(Decimal const &other) const {
  return subtract(*this, other);
}

std::string Decimal::toString() const {
  std::string str_;
  for (int i = nums.size(); i-- > 0;){
    str_ += (nums.ind(i) + '0');
  }
  return str_;
}

