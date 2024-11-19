#ifndef POINT_HPP
#define POINT_HPP

#include <type_traits>

template<typename T>
concept Scal = std::is_arithmetic_v<T>;

template<Scal T>
class Point {
  private:
    T x;
    T y;

  public:
    Point() : x(0), y(0) {}
    Point(T xVal, T yVal) : x(xVal), y(yVal) {}

    T getX() const { return x; }
    T getY() const { return y; }

    void setXY(T xVal, T yVal) { x = xVal; y = yVal; }

    bool operator==(const Point &other) const {
          if (x != other.x || y != other.y) return false;
        return true;
    }
};

#endif