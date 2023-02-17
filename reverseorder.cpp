//Spring 2023 - Lab 03 - reverseorder.cpp
//Last name: Wong
//First name: Ashleigh
//GitHub username: AshleighWong

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reverseorder.h"
#include "reservoir.h"
#include <string>

//add the program functions
void reverse_order(std::string date1, std::string date2)
{
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) 
  {
    std::cerr << "File cannot be opened for reading." << "\n";
    exit(1); // exit if failed to open the file
  }
  
  std::string junk;// new string variable
  std::getline(fin, junk); // read one line from the file
  
  std::string inputDate;
  double eastSt, eastEl, westSt, westEl;


  int max_data = 365, position = 0; //the index of the arrays will start at 0
  //defining the arrays 
  std::string dates[max_data];
  double basinEl[max_data];
  bool write_in_array = false; //initializing as false bc will only write if condition is true
 

  
  // this loop reads the file line-by-line, extracting 5 values on each iteration
  while (fin >> inputDate >> eastSt >> eastEl >> westSt >> westEl) 
  { 
    fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignoring the remaining columns 
    if (inputDate == date1)
    {
      write_in_array = true;
    }
    if (write_in_array)
    {
      //writes the data to the arrays
      dates[position] = inputDate;
      basinEl[position] = westEl;
      //increments
      position++;
    }
    if (inputDate == date2)
    {
      write_in_array = false;
    }
  }
  //loop will print the elements in the array in reverse order until element [0]. 
  // i = position - 1 because # of elements and the index of elements is different 
  for(int i = position-1; i >= 0; i--) 
    {
      std::cout << dates[i] << ": " << basinEl[i] << " ft" << "\n";
    }
  fin.close();
}
