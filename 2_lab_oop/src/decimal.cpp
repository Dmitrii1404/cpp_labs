#include "decimal.h"

Decimal::Decimal() : nums({0}) {}

Decimal::Decimal(const std::string& number){
  for (auto chr = number.rbegin(); chr != number.rend(); ++chr){
    if (*chr < '0' || *chr > '9') {
      throw std::invalid_argument("Input invalid number");
    }
    nums.push_back(*chr - '0');
  }
}

Decimal::Decimal(Decimal const &other) {
  nums = other.nums;
}
Decimal::Decimal(Decimal&& other) noexcept {
  nums = std::move(other.nums);
}
Decimal::~Decimal() = default;



Decimal& Decimal::operator=(const Decimal &other){
  if (this != &other) {
    nums = other.nums;
  }
  return *this;
}

Decimal& Decimal::operator=(Decimal &&other) noexcept {
  if (this != &other) {
    nums = std::move(other.nums);
  }
  return *this;
}

bool Decimal::operator==(Decimal const &other) const {
  return nums == other.nums;
}

bool Decimal::operator!=(Decimal const &other) const {
  return !(*this == other);
}

bool Decimal::operator<( Decimal const &other) const {
  if (nums.size() != other.nums.size()) {
    return nums.size() < other.nums.size();
  }
  for (int i = nums.size(); i-- > 0;){
    if (nums[i] != other.nums[i]) {
      return nums[i] < other.nums[i];
    }
  }
  return false;
}

bool Decimal::operator>(Decimal const &other) const {
  return other < *this;
}

void Decimal::delZeros() {
  while (nums.size() > 1 && nums.back() == 0){
    nums.pop_back();
  }
}

Decimal Decimal::add(Decimal const  &a, Decimal const &b) {
  Decimal solution;
  solution.nums.clear();
  unsigned char ten = 0;
  int mxSize = std::max(a.nums.size(), b.nums.size());

  for (int i = 0; ten || i < mxSize; ++i){
    unsigned char sum = ten;
    if (i < a.nums.size()) { sum += a.nums[i]; }
    if (i < b.nums.size()) { sum += b.nums[i]; }
    ten = (sum > 9);
    solution.nums.push_back(sum % 10);
  }

  return solution;
}

Decimal Decimal::subtract(Decimal const &a, Decimal const &b) {
  if (a < b) {
    throw std::invalid_argument("Second num is greater than the first.");
  }
  Decimal solution;
  solution.nums.clear();
  unsigned char ten = 0;

  for (int i = 0; i < a.nums.size(); ++i){
    unsigned char sub = a.nums[i] - ten;
    if (i < b.nums.size()) { sub -= b.nums[i]; }
    ten = (sub > 9);
    solution.nums.push_back((sub + 10) % 10);
  }

  solution.delZeros();
  return solution;
}

Decimal Decimal::operator+(Decimal const &other) const {
  return add(*this, other);
}

Decimal Decimal::operator-(Decimal const &other) const {
  return subtract(*this, other);
}

std::string Decimal::toString() const {
  std::string str_;
  for (auto chr = nums.rbegin(); chr != nums.rend(); ++chr){
    str_ += (*chr + '0');
  }
  return str_;
}

