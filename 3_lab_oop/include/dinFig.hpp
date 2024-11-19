#include "dinFig.h"


template <typename T>
DinFig<T>::DinFig() : data(nullptr), size(0), len(0) {};

template <typename T>
DinFig<T>::DinFig(const DinFig &other) : data(nullptr), size(0), len(0){
  std::copy(other);
}

template <typename T>
DinFig<T>::~DinFig(){
  delete data;
}

template <typename T>
void DinFig<T>::resize(size_t new_size) {
  T* new_data = new T[new_size];
  for (size_t i = 0; i < len; i++) {
    new_data[i] = data[i];
  }
  delete data;
  data = new_data;
  size = new_size;
}


template <typename T>
DinFig<T> DinFig<T>::operator=(const DinFig &other){
  if (this != &other){
    delete this;
    std::copy(other);
  }
  return *this;
}

template <typename T>
void DinFig<T>::push_back(const T& num) {
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

template <typename T>
void DinFig<T>::remove_ind(size_t index){
  if (index >= len){
    throw std::out_of_range("out of range");
  }
  for (size_t i = index; i < len-1; i++) {
    data[i] = data[i+1];
  }
  len--;
}

template <typename T>
size_t DinFig<T>::get_size() const{
  return size;
}

template <typename T>
T& DinFig<T>::operator[](size_t index) const{
  if (index >= len) {
    throw std::out_of_range("out of range");
  }
  return data[index];
}

template <typename T>
void DinFig<T>::printCoords(){
  for (int i = 0; i < len; i++){
    std::cout << *(data[i]) << std::endl;
  }
}

template <typename T>
void DinFig<T>::printCenters(){
  for (int i = 0; i < len; i++){
    std::cout << "(" << data[i]->center().first << ", " << data[i]->center().second << ")" << std::endl;
  }
}

template <typename T>
void DinFig<T>::printSquares(){
  for (int i = 0; i < len; i++){
    std::cout << data[i]->square() << std::endl;
  }
}

template <typename T>
double DinFig<T>::getAllSquare(){
  double sq = 0;
  for (int i = 0; i < len; i++){
    sq += data[i]->square();
  }
  return sq;
}