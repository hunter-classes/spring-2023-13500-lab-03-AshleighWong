//Spring 2023 - Lab 03 - reservoir.cpp
//Last name: Wong
//First name: Ashleigh
//GitHub username: AshleighWong

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"
#include <string>

//TASK A
double get_east_storage(std::string date)
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
  // this loop reads the file line-by-line, extracting 5 values on each iteration
  while (fin >> inputDate >> eastSt >> eastEl >> westSt >> westEl) 
  { 
    fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignoring the remaining columns 
    if (inputDate == date)
    {
      std::cout << "\n";
      std::cout << date << ": ";
      return eastSt;
    }
  }
  fin.close();
  return 0;
}






//TASK B
double get_min_east()
{
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) 
  {
    std::cerr << "File cannot be opened for reading." << "\n";
    exit(1); 
  }
  
  std::string junk;
  std::getline(fin, junk); 

  std::string inputDate;
  double eastSt;
  double min = INT_MAX; //initializing min to the biggest value possible
  while (fin >> inputDate >> eastSt) 
  { 
    fin.ignore(INT_MAX, '\n');
    if (eastSt < min)
    {
      min = eastSt;
    }
  }
  fin.close();
  return min;
}



double get_max_east()
{
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) 
  {
    std::cerr << "File cannot be opened for reading." << "\n";
    exit(1);
  }
  
  std::string junk;
  std::getline(fin, junk); 

  std::string inputDate;
  double eastSt;
  double max = INT_MIN; //initializing max to the smallest value possible
  while (fin >> inputDate >> eastSt )
  { 
    fin.ignore(INT_MAX, '\n');
    if (eastSt > max)
    {
      max = eastSt;;
    }
  }
  fin.close();
  return max;
}




//TASK C
std::string compare_basins(std::string date)
{
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) 
  {
    std::cerr << "File cannot be opened for reading." << "\n";
    exit(1);
  }
  
  std::string junk;
  std::getline(fin, junk); 

  std::string inputDate;
  double eastSt, eastEl, westSt, westEl;
  while (fin >> inputDate >> eastSt >> eastEl >> westSt >> westEl) 
  { 
    fin.ignore(INT_MAX, '\n');
    if (inputDate == date)
    {
      if (eastEl < westEl)
      {
        std::cout << "\n";
        std::cout << date << ": ";
        return "West";
      }
      else if (eastEl > westEl)
      {
        std::cout << "\n";
        std::cout << date << ": ";
        return "East";
      }
      else
      {
        std::cout << "\n";
        std::cout << date << ": ";
        return "Equal";
      }
    }
  }
  fin.close();
  return 0;
}
