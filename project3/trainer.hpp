//CSCI 135
//Prof Maryash
//Project 3
//Zara Amer
//5/13/23

#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "profemon.hpp"
#include "skill.hpp"

// Since the Department classes will inherit from the Trainer, the Trainer class should have the following protected data members:

// - A vector of profémons which represents a profedéx
// - A profémon array of size 3 which represents the trainer's current team
// - A pointer to a profémon which is currently selected from the team

// The Trainer class must have the following in it’s public access modifier:
/* 
Trainer();
Trainer(std::vector <Profemon> profemons);
bool contains (std::string name);
bool addProfemon(Profemon profemon);
bool removeProfemon(std::string name);
void setTeamMember(int slot, std::string name);\
bool chooseProfemon (int slot);
Profemon getCurrent();
void printProfedex();
void printTeam();
*/

class Trainer {
protected:
    std::vector <Profemon> profedex;
    Profemon team[3];
    Profemon *current;
public:
    Trainer();
    Trainer(std::vector <Profemon> profemons);
    bool contains (std::string name);
    bool addProfemon(Profemon profemon);
    bool removeProfemon(std::string name);
    void setTeamMember(int slot, std::string name);
    bool chooseProfemon (int slot);
    Profemon getCurrent();
    void printProfedex();
    void printTeam();
};

