//CSCI 135
//Prof Maryash
//Project 3
//Zara Amer
//5/13/23

#include <iostream>
#include <string>
#include <vector>
#include "profemon.hpp"
#include "trainer.hpp"


/*
    @post       :   Initializes the pointer to the currently
                    selected profémon as 'nullptr'
*/  
Trainer::Trainer()
{
  current = nullptr; 
}

/*
    @param      :   a vector of profémons
    @post       :   Adds the profémons from given parameter
                    vector to the team and the profédex. If
                    the team is full, add the profémons to 
                    the profedéx. Maintain the order of the 
                    given 'profemons' vector. Assume that 
                    the parameter vector has atleast one
                    item. Select the profémon at 0 index of
                    the team array to accompany the trainer
*/
Trainer::Trainer(std::vector <Profemon> profemons)
{
  for(int i = 0; i < profemons.size(); i++)
    {
      if(i < 3)
      {
        team[i] = profemons[i];
      }  
      else
      {
        profedex.push_back(profemons[i]);
      }  
    }
  current = &team[0];
}

/*
    @param      :   the name of a profémon
    @return     :   'true' if profémon with given name is in 
                    the team or profedex, otherwise 'false'   
    @post       :   return 'true' if the profémon with the name
                    same as the given parameter is found either
                    in current team, or in the profédex. Return
                    false if the profémon is not found
*/
bool Trainer::contains(std::string name)
{
  for(int i = 0; i < profedex.size(); i++)
  {
    if(profedex[i].getName() == name)
    {
      return true;
    }
  }

  for(int i = 0; i < 3; i++)
    {
      if(team[i].getName() == name)
      {
        return true;
      }
    }
  return false;
}

/*
    @param      :   a profémon that is to be added
    @return     :   boolean indicating successful add operation
    @post       :   Add the given parameter profémon to the team
                    or the profedex. Only add the profemon to
                    profédex if the current team is full. If the 
                    profémon is being added to the team, add it 
                    to the smallest index possible. The profémon 
                    can't be added if another profémon with the
                    same name already exists in the team or 
                    the profédex 
*/
bool Trainer::addProfemon(Profemon profemon)
{
  //check if already in profedex or in team
  for(int i = 0; i < profedex.size(); i++)
    {
      if(profedex[i].getName() == profemon.getName())
      {
        return false;
      }
    }

  for(int i = 0; i < 3; i++)
    {
      if(team[i].getName() == profemon.getName())
      {
        return false;
      }
    }

  //add to team 
  for(int i = 0; i < 3; i++)
  {
    if(team[i].getName() == "Undefined")
    {
      team[i] = profemon;
      return true;
    }
  }
  //if cannot add to team add to profedex 
  profedex.push_back(profemon); 
  return true;
}

/*
    @param      :   the name of the profémon that is to be removed
    @return     :   boolean indicating successful remove operation
    @post       :   remove the profémon with the given name from
                    the current team or the profédex. If the profémon
                    is removed from the profédex, make sure the order
                    of the remaining profémons is maintained. If the 
                    profémon is on the team, it should be swapped 
                    with an empty profémon object. The profémon 
                    cannot be removed if no profémon with the given 
                    name exists in the team or the profédex.

    Hint        :   What is the default value of the profémons in an    
                    empty array of 'Profemon' objects?
*/
bool Trainer::removeProfemon(std::string name)
{
  for(int i = 0; i < profedex.size(); i++)
    {
      if(profedex[i].getName() == name)
      {
        profedex.erase(profedex.begin() + i);
        return true;
      }
    }
  for(int i = 0; i < 3; i++)
    {
      //check if in team
      if(team[i].getName() == name)
      {
        team[i] = Profemon();
        return true;
      }
    }
  return false;
}


/*
    @param      :   integer representing a slot in the team (0,1 or 2)
    @param      :   name of the profémon that is to be added to the team
    @post       :   assuming that a profémon with the given 'name' exists
                    in the profédex and given 'slot' is valid (0,1,2), add
                    the profémon to the team at the given slot. If the slot
                    already contains a profémon, swap the profémon with the
                    profémon that is being added to the team. If the 'slot'
                    doesn't contain a profémon, move the profémon from the
                    profédex to the slot

For example :

    Let's suppose the current team array is: ["Enxhi", "Undefined", "Kimberly"]
    And profédex is: ["Sadab", "Yoomin", "Zilola", "Brandon"]

    If we call 'setTeamMember(1,"Yoomin")', the team and profédex becomes:
    Team: ["Enxhi", "Yoomin", "Kimberly"]
    Profédex: ["Sadab", "Zilola", "Brandon"]
    The profémon is moved to the team's empty slot (Undefined means empty)

    However, if we call 'setTeamMember(0,"Zilola")':
    Team: ["Zilola", "Undefined", "Kimberly"]
    Profédex: ["Sadab", "Yoomin", "Enxhi", "Brandon"]
    The profémon is swapped with the profémon in slot 0
*/
void Trainer::setTeamMember(int slot, std::string name)
{
  bool added = false;
  int position; 
  for(int i = 0; i < profedex.size(); i++)
    {
      if(profedex[i].getName() == name)
      {
        added = true;
        position = i;
        break;
      }
    }
    if(added == false)
    {
      return;
    }
    else if(team[slot].getName() == "Undefined")
    {
      team[slot] = profedex[position];
      profedex.erase(profedex.begin() + position);
    }
    else
    {
      Profemon t = team[slot];
      team[slot] = profedex[position];
      profedex[position] = t;
    }
}

/*
    @param      :   integer representing a slot in the team (0,1 or 2)
    @return     :   'true' if the profémon at given slot is successfully
                    chosen. Otherwise, return 'false'
    @post       :   choose a profemon to accompany the Trainer from the
                    team (refers to the pointer Profemon data member).
                    The profémon cannot be chosen if the given slot
                    doesn't contain a profémon. Assume that the given
                    'slot' is valid(0,1,2)

    Hint        :   What is the name of the objects in an empty
                    profémon array?
*/
bool Trainer::chooseProfemon(int slot)
{
  if(team[slot].getName() != "Undefined")
  {
    current = &team[slot];
    return true;
  }
  return false;
}

/*
    @return     :   profémon that is currently accompanying the trainer
*/
Profemon Trainer::getCurrent()
{
  return *current;
}

/*
    @post       :   prints profémons in the profédex in a specific format

Format :
(Profemon1Name) [(Specialty)] | lvl (Level) | exp (CurrentExp)/(RequiredExp) | hp (MaxHP)
(empty line)
(Profemon2Name) [(Specialty)] | lvl (Level) | exp (CurrentExp)/(RequiredExp) | hp (MaxHP)
(empty line)
. . . PRINT ALL THE PROFEMONS IN THE PROFEDEX . . .
(ProfemonName) [(Specialty)] | lvl (Level) | exp (CurrentExp)/(RequiredExp) | hp (MaxHP)
(empty line)

For example:
Maryash [SOFTWARE] | lvl 2 | exp 30/80 | hp 13500

Saad [HARDWARE] | lvl 3 | exp 20/110 | hp 15000

Raja [ML] | lvl 1 | exp 10/60 | hp 35000


Hint : The format looks familiar from Task A doesn't it?
*/
void Trainer::printProfedex()
{
  for(int i = 0; i < profedex.size(); i++)
    {
      profedex[i].printProfemon(false);
      std::cout << "\n";
    }
}

/*
    @post       :   prints profémons in the team in a specific format.
                    Do not print "Undefined" profémons

Format :
(Profemon1Name) [(Specialty)] | lvl (Level) | exp (CurrentExp)/(RequiredExp) | hp (MaxHP)
    (SkillNameSlot0) [(Uses)] : (description of skill in slot 0)
    (SkillNameSlot1) [(Uses)] : (description of skill in slot 1)
    (SkillNameSlot2) [(Uses)] : (description of skill in slot 2)
(empty line)
(Profemon2Name) [(Specialty)] | lvl (Level) | exp (CurrentExp)/(RequiredExp) | hp (MaxHP)
    (SkillNameSlot0) [(Uses)] : (description of skill in slot 0)
    (SkillNameSlot1) [(Uses)] : (description of skill in slot 1)
    (SkillNameSlot2) [(Uses)] : (description of skill in slot 2)
(empty line)
(Profemon3Name) [(Specialty)] | lvl (Level) | exp (CurrentExp)/(RequiredExp) | hp (MaxHP)
    (SkillNameSlot0) [(Uses)] : (description of skill in slot 0)
    (SkillNameSlot1) [(Uses)] : (description of skill in slot 1)
    (SkillNameSlot2) [(Uses)] : (description of skill in slot 2)
(empty line)
*/
void Trainer::printTeam()
{
  for(int i = 0; i < 3; i++)
    {
      if(team[i].getName() != "Undefined")
      {
        team[i].printProfemon(true);
       std::cout << "\n";
      }
      
    }
}

