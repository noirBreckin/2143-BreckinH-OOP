#include <iostream>
#include <string>
#include <vector>
#include "dice.hpp"
#include "helpers.hpp"

using namespace std;

#pragma once
/**
 * Weapon
 * 
 * Description: 
 *      This is the class that handles weapon management. This includes weapon names, dice, and damage.
 * Public Methods
 *      Weapon()
 *      Weapon(vector<string> choices)                
 *      Weapon(string n, string d)
 *      double use()
 *      string getName()
 *      string getDamage()
 *      friend ostream&       operator<<(ostream& os, const Weapon& w)
 * Private Methods:   
 *      string name
 *      string damage
 *      Dice*  die
*/ 




class Weapon {
    string name;    
    string damage;  
    Dice*  die;

public:
/**
 * Public : Weapon
 *
 * Description:
 *        
 *     Construct a Weapon
 *     Uses the dice constructor from dice.hpp
 */
    Weapon() {
        name = "Fists&Feet";
        damage = "1.d.4";
        die = new Dice(damage);
    }

/**
 * Public : operator<<
 * Description:
 *     overloaded the ostream operator to allow it to display the
 *     [name and damage] of the weapon using the << operators 
 * Params:
 *      ostream &os
 *      Weapon& w
 * Returns:
 *      ostream& what will be passed to ostream
 */
    friend ostream& operator<<(ostream& os, const Weapon& w) {
        return os << "[" << w.name << " , " << w.damage << "]";
    }
/**
 * Public : Weapon
 *
 * Description:
 *        
 *     Overloaded Constructor for a new Base Weapon object
 *     Also invokes the Dice class constructor with the "die" type
 * 
 * Params:
 *      vector<string> and choices

 */
    Weapon(vector< string > choices) {
        name = "Fists&Feet";
        damage = randomChoice(choices);
        die = new Dice(damage);
    }


/**
 * Public : Weapon
 * Description:
 *     Overloaded Constructor for Base Weapon object
 *     Uses the dice constructor from dice.hpp
 * Params:
 *      string x
 *      string y
 */
    Weapon(string x, string y){
      name = x;
      damage = y;
      die = new Dice(damage);
    }
/**
 * Public : use
 * Returns: The results of the dice roll for damage
 */
    double use() {
        return die->roll();
    }
/**
 * Public : getName
 * Returns: The weapon name
 */
    string getName(){
      return name;
    }
/**
 * Public : getDamage
 * Description: 
This method returns the dice of damage
 * Returns: The damage die used
 */
    string getDamage(){
      return damage;
    }

};
