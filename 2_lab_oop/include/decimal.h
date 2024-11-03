#ifndef DECIMAL_H
#define DECIMAL_H

#include "dinNums.h"
#include <string>
#include <stdexcept>
#include <iostream>

class Decimal {
  private:
    DinNums nums;
    void delZeros();
    static Decimal add(Decimal const &a, Decimal const &b);
    static Decimal subtract(Decimal const &a, Decimal const &b);

  public:
    Decimal();
    Decimal(const std::string& number);
    Decimal(Decimal const &other);
    Decimal(Decimal&& other) noexcept;
    ~Decimal();

    Decimal prisv(Decimal const &other);
    Decimal prisv(Decimal&& other) noexcept;
    Decimal plus(Decimal const &other) const;
    Decimal minus(Decimal const &other) const;

    bool ravno(Decimal const &other) const;
    bool not_ravno(Decimal const &other) const;
    bool menshe(Decimal const &other) const;
    bool bolshe(Decimal const &other) const;

    std::string toString() const;
};

#endif