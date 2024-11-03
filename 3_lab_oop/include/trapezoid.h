#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

class Trapezoid : public Figure {
public:
    using Figure::Figure;
    ~Trapezoid();

    double square() const override;
};

#endif