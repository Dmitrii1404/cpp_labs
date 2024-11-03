#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

class Rhombus : public Figure {
public:
    using Figure::Figure;
    ~Rhombus();

    double square() const override;
};
#endif