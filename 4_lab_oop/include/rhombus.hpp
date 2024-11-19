#ifndef RHOMBUS_HPP
#define RHOMBUS_HPP

#include "figure.hpp"
#include <math.h>

template<Scal T>
class Rhombus : public Figure<T> {
public:
    using Figure<T>::Figure;
    ~Rhombus() = default;

    double square() const override {
        double AC = 0, BD = 0;
        AC = sqrt(pow((*this->coords[2]).getX() - (*this->coords[0]).getX(), 2) + pow((*this->coords[2]).getY() - (*this->coords[0]).getY(), 2));
        BD = sqrt(pow((*this->coords[3]).getX() - (*this->coords[1]).getX(), 2) + pow((*this->coords[3]).getY() - (*this->coords[1]).getY(), 2));
        return round(AC * BD * 1000) / 1000;
    }
};
#endif
