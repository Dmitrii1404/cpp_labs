#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include "figure.hpp"
#include <math.h>

template<Scal T>
class Trapezoid : public Figure<T> {
public:
    using Figure<T>::Figure;
    ~Trapezoid() = default;

    double square() const override {
        double AB = 0, AD = 0, BC = 0, n = 0, h = 0;
        AB = sqrt(pow((*this->coords[1]).getX() - (*this->coords[0]).getX(), 2) + pow((*this->coords[1]).getY() - (*this->coords[0]).getY(), 2));
        AD = sqrt(pow((*this->coords[3]).getX() - (*this->coords[0]).getX(), 2) + pow((*this->coords[3]).getY() - (*this->coords[0]).getY(), 2));
        BC = sqrt(pow((*this->coords[2]).getX() - (*this->coords[1]).getX(), 2) + pow((*this->coords[2]).getY() - (*this->coords[1]).getY(), 2));
        n = (AD - BC) / 2;
        h = sqrt(pow(AB, 2) - pow(n, 2));
        return round(((AD + BC) / 2 * h) * 1000) / 1000;
    }
};

#endif
