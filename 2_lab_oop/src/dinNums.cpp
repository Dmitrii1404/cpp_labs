#include "dinNums.h"
#include <stdexcept>

DinNums::DinNums() : head(nullptr), tail(nullptr), size_n(0){}

DinNums::~DinNums(){
  clear();

}

void DinNums::clear(){
    Node* this_ = head;
    while(this_ != nullptr){
      Node* next = this_->next;
      delete this_;
      this_ = next;
    }
    head = tail = nullptr;
    size_n = 0;
}

DinNums::DinNums(const DinNums &other) : head(nullptr), tail(nullptr), size_n(0){
  copy(other);
}

DinNums DinNums::prisv(const DinNums &other){
  if (this != &other){
    clear();
    copy(other);
  }
  return *this;
}

void DinNums::push_back(const unsigned char &num){
  Node* new_node = new Node(num);
  if (tail == nullptr){
    head = tail = new_node;
  } else {
    tail->next = new_node;
    tail = new_node;
  }
  size_n++;
}

void DinNums::pop_back(){
  if (size_n == 0) throw std::out_of_range("error, size = 0");
  if (size_n == 1) {
    delete head;
    head = tail = nullptr;
  } else {
    Node* this_ = head;
    while(this_->next != tail){
      this_ = this_->next;
    }
    delete tail;
    tail = this_;
    tail->next = nullptr;
  }
  size_n--;
}

int DinNums::size() const{
  return size_n;
}

unsigned char DinNums::ind(int index) const{
  if (index >= size_n){
    throw std::out_of_range("out of range");
  }
  Node* this_ = head;
  for (int i = 0; i < index; i++){
    this_ = this_->next;
  }
  return this_->data;
};



