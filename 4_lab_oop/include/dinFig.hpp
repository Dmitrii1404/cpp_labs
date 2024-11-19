#ifndef DINFIG_HPP
#define DINFIG_HPP

#include <iostream>

template<typename T>
concept FType = requires(T t)
{
  { t->square() } -> std::convertible_to<double>;
};

template<FType T>
class DinFig {
private:
  std::shared_ptr<T[]> data;
  size_t size;
  size_t len;

  void resize(size_t new_size) {
    auto new_data = std::shared_ptr<T[]>(new T[new_size]);
    for (size_t i = 0; i < len; i++) {
      new_data[i] = std::move(data[i]);
    }
    data = std::move(new_data);
    size = new_size;
  }

public:
  DinFig() : data(nullptr), size(0), len(0) {}

  ~DinFig() = default;

  void push_back(const T& num) {
    if (len == size){
      size_t new_size;
      if (!size) {
        new_size = 1;
      } else {
        new_size = size*2;
      }
      resize(new_size);
    }
    data[len++] = num;
  }

  void remove_ind(size_t index) {
    if (index >= len){
      throw std::out_of_range("out of range");
    }
    for (size_t i = index; i < len-1; i++) {
      data[i] = data[i+1];
    }
    len--;
  }

  size_t get_size() const {
    return size;
  }

  T& operator[](size_t i) const {
    if (i >= len) {
      throw std::out_of_range("out of range");
    }
    return data[i];
  }

  void printCoords() {
    for (int i = 0; i < len; i++){
      std::cout << *(data[i]) << std::endl;
    }
  }
  void printCenters() {
    for (int i = 0; i < len; i++){
      std::cout << "(" << data[i]->center().getX() << ", " << data[i]->center().getY() << ")" << std::endl;
    }
  }

  void printSquares() {
    for (int i = 0; i < len; i++){
      std::cout << data[i]->square() << std::endl;
    }
  }

  double getAllSquare() {
    double sq = 0;
    for (int i = 0; i < len; i++){
      sq += data[i]->square();
    }
    return sq;
  }
};

#endif