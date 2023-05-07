//Zara Amer
//CSCI 135
//Prof. Maryash
//Project 3
//5/6/23

#pragma once
#include <iostream>
#include <string>
#include "skill.hpp"

/*The header file of the Profemon class must have an enumeration type called “Specialty” with three possible values:
ML, SOFTWARE, and HARDWARE in this exact order. The enum should be defined outside the class. */

enum Specialty {
    ML, 
    SOFTWARE, 
    HARDWARE
};

// The Profemon class must have the following information stored in their private member variables:

// - The name of the profémon
// - The level of the profémon
// - The required experience to level up
// - The current experience
// - The maximum health level
// - The specialty of the profémon
// - A 'Skill' array of size 3 containing skills learned by the profémon

// The Profemon class must have the following in it’s public access modifier: 

// Profemon();
// Profemon(string name, double max_health, Specialty specialty);
// string getName();
// int getSpecialty();
// int getLevel();
// double getMaxHealth();
// void setName(string name);
// void levelUp(int exp);
// bool learnSkill(int slot, Skill skill);
// void printProfemon(bool print_skills);

class Profemon {
private:
    std::string pname;
    int plevel;
    int req_exp;
    int curr_exp;
    int maxhealth;
    Specialty pspecialty;
    Skill pskills[3];
public:
    Profemon();
    Profemon(std::string name, double max_health, Specialty specialty);
    std::string getName();
    Specialty getSpecialty();
    int getLevel();
    double getMaxHealth();
    int getCurrExp();
    int getReqExp();
    void setName(std::string name);
    void levelUp(int exp);
    bool learnSkill(int slot, Skill skill);
    void printProfemon(bool print_skills);
};