#ifndef DECIMAL_H
#define DECIMAL_H

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

class Decimal {
  private:
    std::vector<unsigned char> nums;
    void delZeros();
    static Decimal add(Decimal const &a, Decimal const &b);
    static Decimal subtract(Decimal const &a, Decimal const &b);

  public:
    Decimal();
    Decimal(const std::string& number);
    Decimal(Decimal const &other);
    Decimal(Decimal&& other) noexcept;
    ~Decimal();

    Decimal& operator=(Decimal const &other);
    Decimal& operator=(Decimal&& other) noexcept;
    Decimal operator+(Decimal const &other) const;
    Decimal operator-(Decimal const &other) const;

    bool operator==(Decimal const &other) const;
    bool operator!=(Decimal const &other) const;
    bool operator<(Decimal const &other) const;
    bool operator>(Decimal const &other) const;

    std::string toString() const;
};

#endif