//Zara Amer
//CSCI 135
//Prof. Maryash
//Project 3
//5/6/23

#include <iostream>
#include <string>
#include "skill.hpp"


    // @post       :   Initializes the name and 
    //                 description of the skill as 
    //                 "Undefined". Initializes the 
    //                 total uses of the skill and
    //                 the skill specialty as -1 
 

Skill::Skill(){
    skill_name = "Undefined";
    skill_description = "Undefined";
    total_uses = -1;
    skill_specialty = -1;
}


    // @post       :   Parameterized constructor that
    //                 sets the corresponding data members
    //                 equal to the respective parameters

Skill::Skill(std::string name, std::string description, int specialty, int uses){
    skill_name = name;
    skill_description = description;
    skill_specialty = specialty;
    total_uses = uses;
}


    // @return     :   The name of the skill


std::string Skill::getName(){
    return skill_name;
}


    // @return     :   The description of the skill


std::string Skill::getDescription(){
    return skill_description;
}


    // @return     :   The total number of uses of the skill


int Skill::getTotalUses(){
    return total_uses;
}


    // @return     :   The specialty of the skill


int Skill::getSpecialty(){
    return skill_specialty;
}


    // @post       :   Sets the name of the skill equal to the parameter
    // @param name :   The name of the skill

void Skill::setName(std::string name){
    skill_name = name;
}


    // @post           :   Sets the description of the skill equal to the parameter
    // @param name     :   The description of the skill


void Skill::setDescription(std::string description){
    skill_description = description;
}


    // @post       :   Sets the total number of uses of the skill equal to the parameter
    // @param uses :   The total number of uses of the skill


void Skill::setTotalUses(int uses){
    total_uses = uses;
}


    // @return     :   Return 'true' if the given parameter 
    //                 is either 0, 1 or 2. Otherwise,
    //                 return 'false'
    // @post       :   set the specialty of the skill
    //                 equal to the given parameter only
    //                 if the given parameter is valid (0,1,2)
    //                 Return 'true' if the specialty
    //                 is successfully updated 


bool Skill::setSpecialty(int specialty){
    if(specialty == 0 || specialty == 1 || specialty == 2){
        skill_specialty = specialty;
        return true;
    }
    else{
        return false;
    }
}
