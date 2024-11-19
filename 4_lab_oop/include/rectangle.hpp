#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "figure.hpp"
#include <math.h>

template<Scal T>
class Rectangle : public Figure<T> {
    public:
        using Figure<T>::Figure;
        ~Rectangle() = default;

        double square() const override {
     		double AB = 0, AD = 0;

     		AB = sqrt(pow((*this->coords[1]).getX() - (*this->coords[0]).getX(), 2) + pow((*this->coords[1]).getY() - (*this->coords[0]).getY(), 2));
     		AD = sqrt(pow((*this->coords[3]).getX() - (*this->coords[0]).getX(), 2) + pow((*this->coords[3]).getY() - (*this->coords[0]).getY(), 2));
     		return round(AB * AD * 1000)/1000;
		}
};
#endif
