#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure {
    public:
        using Figure::Figure;
        ~Rectangle();

        double square() const override;
};
#endif