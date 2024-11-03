#ifndef DINNUMS_H
#define DINNUMS_H

//template <typename T>
class DinNums{
  private:
    struct Node {
      unsigned char data;
      Node* next;
      Node(const unsigned char &data) : data(data), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size_n;

    void copy(const DinNums &other) {
      Node* this_ = other.head;
      while (this_ != nullptr) {
        push_back(this_->data);
        this_ = this_->next;
      }
    }

  public:
    DinNums();
    ~DinNums();
    void clear();
    DinNums(const DinNums &other);

    DinNums prisv(const DinNums &other);

    void push_back(const unsigned char &num);
    void pop_back();
    int size() const;
    unsigned char ind(int i) const;
};

#endif