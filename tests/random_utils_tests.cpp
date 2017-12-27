#include <iostream>
#include "random_utils.h"

int main()
{
  ts::randomize();
  std::cout << ts::random() << std::endl;
  std::cout << ts::pick(10, 1000) << std::endl;
  std::cout << ts::pick(10, 1000) << std::endl;
  return 0;
}
