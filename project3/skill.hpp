//Zara Amer
//CSCI135
//Prof. Maryash
//Project 3
//5/6/23

#pragma once
#include <iostream>
#include <string>


// The Skill class must have the following information stored in their private member variables:

// - The name of the skill
// - The description of the skill
// - The total number of times the skill can be used 
// - An integer that represents the specialty of the skill (0, 1 or 2)

// The Skill class must have the following in it’s public access modifier:

// Skill();
// Skill(string name, string description, int specialty, int uses);
// string getName();
// string getDescription();
// int getTotalUses();
// int getSpecialty();
// void setName(string name);
// void setDescription(string description);
// void setTotalUses(int uses);
// void setSpecialty(int specialty);

class Skill {
private:
    std::string skill_name;
    std::string skill_description;
    int total_uses;
    int skill_specialty;
public:
    Skill();
    Skill(std::string name, std::string description, int specialty, int uses);
    std::string getName();
    std::string getDescription();
    int getTotalUses();
    int getSpecialty();
    void setName(std::string name);
    void setDescription(std::string description);
    void setTotalUses(int uses);
    bool setSpecialty(int specialty);
};