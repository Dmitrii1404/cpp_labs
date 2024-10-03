#include <iostream>
#include "solution.h"

int main(){
  int divider, border;
  std::cout << "Enter the divisor" << std::endl;
  std::cin >> divider;
  std::cout << "Enter the border" << std::endl;
  std::cin >> border;

  int result = findAnswer(divider, border);
  if (result == -1){
    std::cout << "Invalid input data" << std::endl;
  } else {
    std::cout << "Greatest multiple: " << result << std::endl;
  }

  return 0;
}