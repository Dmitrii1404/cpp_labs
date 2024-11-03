#include "rectangle.h"
#include <math.h>

/*
 B---------C
 |         |
 A---------D
 */

Rectangle::~Rectangle() = default;

double Rectangle::square() const{
     double AB = 0, AD = 0;
     AB = sqrt(pow(coords[1].first - coords[0].first, 2) + pow(coords[1].second - coords[0].second, 2));
     AD = sqrt(pow(coords[3].first - coords[0].first, 2) + pow(coords[3].second - coords[0].second, 2));
     return round(AB * AD * 1000)/1000;
}