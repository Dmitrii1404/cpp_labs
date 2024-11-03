#include "trapezoid.h"
#include <math.h>

/*
       B-------C
      /         \
     /           \
    A-------------D
 */

Trapezoid::~Trapezoid() = default;

double Trapezoid::square() const{
     double AB = 0, AD = 0, BC = 0, n = 0, h = 0;
     AB = sqrt(pow(coords[1].first - coords[0].first, 2) + pow(coords[1].second - coords[0].second, 2));
     AD = sqrt(pow(coords[3].first - coords[0].first, 2) + pow(coords[3].second - coords[0].second, 2));
     BC = sqrt(pow(coords[2].first - coords[1].first, 2) + pow(coords[2].second - coords[1].second, 2));
     n = (AD - BC) / 2;
     h = sqrt(pow(AB, 2) - pow(n, 2));
     return round(((AD + BC) / 2 * h) * 1000) / 1000;
}