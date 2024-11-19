#ifndef DINFIG_H
#define DINFIG_H



template <typename T>
class DinFig {
private:
    T* data;
    size_t size;
    size_t len;

    void resize(size_t new_size);

public:
    DinFig();
    DinFig(const DinFig &other);
    ~DinFig();

    DinFig operator=(const DinFig &other);
    void push_back(const T& num);
    void remove_ind(size_t index);
    size_t get_size() const;
    T& operator[](size_t i) const;
    void printCoords();
    void printCenters();
    void printSquares();
    double getAllSquare();
};



#include "dinFig.hpp"
#endif

