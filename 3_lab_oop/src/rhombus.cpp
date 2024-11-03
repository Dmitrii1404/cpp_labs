#include "rhombus.h"
#include <math.h>

/*
       B
     /   \
    /     \
   A       C
    \     /
     \   /
       D
 */

Rhombus::~Rhombus() = default;

double Rhombus::square() const{
     double AC = 0, BD = 0;
     AC = sqrt(pow(coords[2].first - coords[0].first, 2) + pow(coords[2].second - coords[0].second, 2));
     BD = sqrt(pow(coords[3].first - coords[1].first, 2) + pow(coords[3].second - coords[1].second, 2));
     return round(AC * BD * 1000) / 1000;
}