//CSCI 135
//Prof Maryash
//Project 3
//Zara Amer
//5/13/23

#include "department.hpp"
#include "skill.hpp"
#include "profemon.hpp"
#include "trainer.hpp"

#include <iostream>
#include <string>
#include <vector>

//constructor for the ML department class
//@param: vector of profemons

MLDepartment::MLDepartment(std::vector<Profemon> profemons)
{
  for(int i = 0; i < profemons.size(); i++) //go thru each of the profemons in the vector
    {
      if(profemons[i].getSpecialty() == ML) //check if their specialty is ML
      {
        Trainer::addProfemon(profemons[i]); //add profemon to profedex
      }
      
    }
}

//add profemon bool that checks if specialty is ML. if true, add to profedex. otherwise, false.
bool MLDepartment::addProfemon(Profemon profemon)
{
  if(profemon.getSpecialty() == ML)
  {
    profedex.push_back(profemon);
    return true;
  }
  return false;
}

//constructor for the Software department class
//@param: vector of profemons

SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons)
{
  for(int i = 0; i < profemons.size(); i++) //go thru each of the profemons in the vector
    {
      if(profemons[i].getSpecialty() == SOFTWARE) //check if their specialty is SOFTWARE
      {
        Trainer::addProfemon(profemons[i]); //add profemon to profedex
      } 
    }
}

//add profemon bool that checks if specialty is SOFTWARE. if true, add to profedex. otherwise, false.
bool SoftwareDepartment::addProfemon(Profemon profemon)
{
  if(profemon.getSpecialty() == SOFTWARE)
  {
    profedex.push_back(profemon);
    return true;
  }
  return false;
}

//constructor for the Hardware department class
//@param: vector of profemons

HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons)
{
  for(int i = 0; i < profemons.size(); i++) //go thru each of the profemons in the vector
    {
      if(profemons[i].getSpecialty() == HARDWARE) //check if their specialty is HARDWARE
      {
        Trainer::addProfemon(profemons[i]); //add profemon to profedex
      }
      
    }
}

//add profemon bool that checks if specialty is HARDWARE. if true, add to profedex. otherwise, false.
bool HardwareDepartment::addProfemon(Profemon profemon)
{
  if(profemon.getSpecialty() == HARDWARE)
  {
    profedex.push_back(profemon);
    return true;
  }
  return false;
}
