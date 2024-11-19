#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include "point.hpp"

template<Scal T>
class Figure{
protected:
    std::unique_ptr<Point<T>> coords[4];

public:
    Figure() = default;

    Figure(const std::initializer_list<Point<T>> &c) {
        auto it = c.begin();
        for (int i = 0; i < 4; i++) {
            coords[i] = std::make_unique<Point<T>>(*it);
            ++it;
        }
    }

    virtual ~Figure() = default;

    Figure(Figure const &other) {
        for (int i = 0; i < 4; ++i) {
            coords[i] = std::make_unique<Point<T>>(*other.coords[i]);
        }
    }

    Figure(Figure &&other) noexcept {
        for (int i = 0; i < 4; ++i) {
            coords[i] = std::move(other.coords[i]);
        }
    }

    Figure& operator=(const Figure &other) {
        if (this != &other) {
            for (int i = 0; i < 4; ++i) {
                coords[i] = std::make_unique<Point<T>>(*other.coords[i]);
            }
        }
        return *this;
    }

    Figure& operator=(Figure &&other) noexcept {
        if (this != &other) {
            for (int i = 0; i < 4; ++i) {
                coords[i] = std::move(other.coords[i]);
            }
        }
        return *this;
    }

    bool operator==(const Figure &other) const {
        for (int i = 0; i < 4; ++i) {
            if (*coords[i] != *other.coords[i]) return false;
        }
        return true;
    }

    bool operator!=(const Figure &other) const {
        return !(*this == other);
    }

    friend std::ostream &operator<<(std::ostream &os, const Figure<T> &fig) {
        for (const auto& coord : fig.coords){
            os << "(" << (*coord).getX() << ";" << (*coord).getY() << ")";
        }
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Figure<T> &fig) {
        T x, y;
        for (int i = 0; i < 4; i++) {
            is >> x >> y;
            fig.coords[i] = std::make_unique<Point<T>>(x, y);
        }
        return is;
    }

    Point<T> center() const {
        double x1 = 0;
        double x2 = 0;
        for (const auto &coord : coords){
            x1 += (*coord).getX();
            x2 += (*coord).getY();
        }
        return {x1/4, x2/4};
    }

    virtual double square() const = 0;
};
#endif