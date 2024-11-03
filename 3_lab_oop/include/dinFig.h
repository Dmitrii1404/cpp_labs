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
    //void pop_back();
    void remove_ind(size_t index);
    size_t get_size() const;
    T& operator[](size_t i) const;
    void printCoords();
    void printCenters();
    void printSquares();
    double getAllSquare();


    //void clear();
};


// class DinFig{
//   private:
//     struct Node {
//       Figure* data;
//       Node* next;
//       Node(Figure* data) : data(data), next(nullptr) {}
//     };
//     Node* head;
//     Node* tail;
//     int size_n;
//
//     void copy(const DinFig &other) {
//       Node* this_ = other.head;
//       while (this_ != nullptr) {
//         push_back(this_->data);
//         this_ = this_->next;
//       }
//     }
//
//   public:
//     DinFig();
//     DinFig(const DinFig &other);
//
//     DinFig operator=(const DinFig &other);
//
//     void push_back(Figure* num);
//     void pop_back();
//     void remove_ind(int index);
//     int size() const;
//     Figure* ind(int i) const;
//
//     ~DinFig();
//     void clear();
// };
#include "dinFig.hpp"
#endif

