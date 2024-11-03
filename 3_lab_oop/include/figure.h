#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>


class Figure {
      protected:
            std::pair<int, int>coords[4] = {};

      public:
            Figure();
            Figure(const std::pair<int, int> &coordA,
                  const std::pair<int, int> &coordB,
                  const std::pair<int, int> &coordC,
                  const std::pair<int, int> &coordD);
            Figure(Figure const &other);
            Figure(Figure &&other) noexcept;
            virtual ~Figure() = default;

            Figure& operator=(const Figure &other);
            Figure& operator=(Figure &&other) noexcept;
            bool operator==(const Figure &other) const;
            bool operator!=(const Figure &other) const;

            friend std::ostream &operator<<(std::ostream &os, const Figure &fig);
            friend std::istream &operator>>(std::istream &is, Figure &fig);

            std::pair<double, double> center() const;
            virtual double square() const = 0;
};

#endif