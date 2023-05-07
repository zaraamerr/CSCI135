//Zara Amer
//CSCI 135
//Prof. Maryash
//Project 3
//5/6/23

#include <iostream>
#include <string>
#include "profemon.hpp"

// @post: Initializes the name of the profémon as "Undefined"

Profemon::Profemon(){
    pname = "Undefined";
}

// @post       :   Initializes the name, max health 
//                 and specialty as the corresponding
//                 parameters. Set the required 
//                 experience equal to 50. 
//                 Initializes the current experience
//                 and level as 0
 

Profemon::Profemon(std::string name, double max_health, Specialty specialty){
    pname = name;
    max_health = max_health;
    pspecialty = specialty;
    req_exp = 50;
    curr_exp = 0;
    plevel = 0;
}


 // @return     :   name of the profémon


std::string Profemon::getName(){
    return pname;
}


// @return     :   specialty of the profémon


Specialty Profemon::getSpecialty(){
    return pspecialty;
}


// @return     :   level of the profémon


int Profemon::getLevel(){
    return plevel;
}

//
//     @return     :   max health of the profémon
//

double Profemon::getMaxHealth(){
    return max_health;
}

int Profemon::getCurrExp()
{
    return curr_exp;
}

int Profemon::getReqExp()
{
    return req_exp;
}


    // @post       :   Sets the name of the profémon
    //                 equal to the parameter


void Profemon::setName(std::string name){
    pname = name;
}

//     @param      :   experience points earned by the profémon 
//     @post       :   Increase the profémon's level based on
//                     the given 'exp'. The profémon will level
//                     up if it reaches the required experience.
//                     Depending on the profémon's specialty,
//                     the required experience goes up by a certain
//                     amount everytime the profémon levels up.
//                     'ML' required experience goes up by 10,
//                     'SOFTWARE' goes up by 15, and 'HARDWARE'
//                     goes up by 20. Make sure to update the
//                     required, current experience and level
//                     private data members accordingly. The given 
//                     'exp' can result in the profémon leveling 
//                     up multiple times
  
//   For example   :   starting at lvl 0, calling 'levelUp(115)'
//                     on different types of profémon would result
//                     in the following:

//                     ML:
//                       - new level: 2
//                       - current exp: 5
//                       - required exp: 70

//                     SOFTWARE:
//                       - new level: 2
//                       - current exp: 0
//                       - required exp: 80

//                     HARDWARE:
//                       - new level: 1
//                       - current exp: 65
//                       - required exp: 70

//                     As stated above, each specialty has 
//                     a different speed of leveling up

void Profemon::levelUp(int exp) {
    int levelIncrease = 0;
    int newReqExp = req_exp;
    
    if (pspecialty == ML) {
        while (exp >= newReqExp) {
            levelIncrease++;
            exp -= newReqExp;
            newReqExp += 10;
        }
    }
    else if (pspecialty == SOFTWARE) {
        while (exp >= newReqExp) {
            levelIncrease++;
            exp -= newReqExp;
            newReqExp += 15;
        }
    }
    else if (pspecialty == HARDWARE) {
        while (exp >= newReqExp) {
            levelIncrease++;
            exp -= newReqExp;
            newReqExp += 20;
        }
    }
    
    plevel += levelIncrease;
    curr_exp = exp;
    req_exp = newReqExp;
}

    // @param      :   the skill slot or index
    // @param      :   the new skill to be learned 
    // @return     :   return 'true' if the skill has been successfully 
    //                 learned. Return 'false' if 'slot' parameters is 
    //                 not within the valid range(0,1,2) or the 
    //                 specialty of the 'skill' does not match 
    //                 the specialty of the profémon 
    // @post       :   if the given slot is valid(0,1,2) and the
    //                 skill specialty matched with the profémon,
    //                 add the 'skill' to the 'slot' index of the
    //                 learned skills array                


bool Profemon::learnSkill(int slot, Skill skill){
    if (slot == 0 || slot == 1 || slot == 2){
        if (skill.getSpecialty() == pspecialty){
            pskills[slot] = skill;
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

//
//     @param      :   bool indicating whether or not the profémon's 
//                     skills should be printed
//     @post       :   Prints the profémon's information in a
//                     specific format. Additionally, lists
//                     the profémon's skills if the given 
//                     'print_skills' parameter is true. Only 
//                     print the skills that are not "Undefined"

// Note: There are four spaces before the each line of skills.
//       The last line prints an endline.
//

void Profemon::printProfemon(bool print_skills){
    std::cout << pname << " [" << pspecialty << "] | lvl " << plevel << " | exp " << curr_exp << "/" << req_exp << " | hp " << max_health << std::endl;
    if (print_skills == true){
        for (int i = 0; i < 3; i++){
            if (pskills[i].getName() != "Undefined"){
                std::cout << "    " << pskills[i].getName() << " [" << pskills[i].getTotalUses() << "] : " << pskills[i].getDescription() << std::endl;
            }
        }
    }
}


