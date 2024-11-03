#include "figure.h"


Figure::Figure() {
     coords[0] = {0, 0};
     coords[1] = {0, 0};
     coords[2] = {0, 0};
     coords[3] = {0, 0};
}

Figure::Figure(const std::pair<int, int> &coordA,
            const std::pair<int, int> &coordB,
            const std::pair<int, int> &coordC,
            const std::pair<int, int> &coordD){
    coords[0] = coordA;
    coords[1] = coordB;
    coords[2] = coordC;
    coords[3] = coordD;
}

Figure::Figure(Figure const &other) {
     for (int i = 0; i < 4; ++i) {
          coords[i] = other.coords[i];
     }
}

Figure::Figure(Figure &&other) noexcept{
     for (int i = 0; i < 4; ++i) {
          coords[i] = std::move(other.coords[i]);
     }
}

Figure& Figure::operator=(const Figure &other) {
     if (this != &other) {
          for (int i = 0; i < 4; ++i) {
               coords[i] = other.coords[i];
          }
     }
     return *this;
}

Figure& Figure::operator=(Figure &&other) noexcept{
     if (this != &other) {
          for (int i = 0; i < 4; ++i) {
               coords[i] = std::move(other.coords[i]);
          }
     }
     return *this;
}

bool Figure::operator==(const Figure &other) const {
     for (int i = 0; i < 4; ++i) {
          if (coords[i] != other.coords[i]) return false;
     }
     return true;
}

bool Figure::operator!=(const Figure &other) const {
     return !(*this == other);
}


std::pair<double, double> Figure::center() const {
     double x1 = 0;
     double x2 = 0;
     for (const auto &coord : coords){
          x1 += coord.first;
          x2 += coord.second;
     }
     return {x1/4, x2/4};
}


std::ostream &operator<<(std::ostream &os, const Figure &fig){
     for (const auto& coord : fig.coords){
          os << "(" << coord.first << ";" << coord.second << ")";
     }
     return os;
}

std::istream &operator>>(std::istream &is, Figure &fig) {
     for (auto& coord : fig.coords){
          is >> coord.first >> coord.second;
     }
     return is;
}