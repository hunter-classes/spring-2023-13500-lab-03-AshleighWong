//Spring 2023 - Lab 03 - main.cpp
//Last name: Wong
//First name: Ashleigh
//GitHub username: AshleighWong

#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"


int main() 
{
  //Task A tests
  std::cout << get_east_storage("01/14/2018") << " billion gallons" << "\n";
  std::cout << get_east_storage("05/26/2018") << " billion gallons" << "\n";
  std::cout << get_east_storage("08/25/2018") << " billion gallons" << "\n";
  std::cout << get_east_storage("12/02/2018") << " billion gallons" << "\n";
  std::cout << "\n\n";
  
  //Task B Test
  std::cout << "Minimum storage in East Basin: " << get_min_east() << "\n";
  std::cout << "Maximum storage in East Basin: " << get_max_east() << "\n";
  std::cout << "\n\n";

  //Task C Test
  std::cout << compare_basins("01/08/2018") << " basin was higher" << "\n";
  std::cout << compare_basins("06/18/2018") << " basin was higher" << "\n";
  std::cout << compare_basins("04/05/2018") << " basin was higher" << "\n";
  std::cout << compare_basins("01/24/2018") << " basin was higher" << "\n";
  std::cout << "\n\n";
  
  //Task D Test
  reverse_order("05/26/2018","06/18/2018");
  std::cout<<"\n";
  reverse_order("01/01/2018","01/01/2018");
  std::cout<<"\n";

  return 0;
}
