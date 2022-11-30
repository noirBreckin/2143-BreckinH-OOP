#include <iostream>
#include <vector>
#include <string>
#include "helpers.hpp"

//using standard library
using namespace std;

#pragma once

/**
 * Die
 * 
 * Description: 
 *      This class is used to simulate a real die where you can pick
 *      how many sides you would like the die to have and roll the die 
 *      as much times as you want
 * Public Methods
 *      Die()
 *      Die(int sides)                
 *      int roll(int rolls)
 *      friend ostream& operator<<(ostream &os, const Die& d)
 * Private Methods:   
 *      int sides
*/ 
class Die {
    int sides;
public:
/**
 * Public : Die
 * Description:      
 *     Default constructor that creates a 6 sided die
 */
    Die():sides{6}{}
/**
 * Public : Die
 *
 * Description:
 *Constructor that takes in an int of how many sides the die will have.
 * Params:
 * int sides 

 */
    Die(int sides):sides{sides}{}
/**
 * Public : roll
 *
 * Description: rolls the die a given number of times and sums up the results and return the sum.
 * Params:
 *      int rolls 
 * Returns:
 *      int he result of the rolls 
 */
    int roll(int rolls = 1) {
        int sum = 0;
        while(rolls--){
            sum += (rand() % sides) + 1;
        }
        return sum;
    };
/**
 * Public : operator<<
 *
 * Description:
 *overloaded the ostream operator to allow the dice to be 
 *displayed [sides] by just using the << operators
 * Params:
 *      ostream         &os
 *      Die&            d
 * Returns:
 * ostream& what will be passed to ostream
 */
    friend ostream& operator<<(ostream &os,const Die& d){
        return os <<"["<< d.sides<<"]";
    }
};
/**
 * Dice
 * 
 * Description: 
 *     This class is used to represent a set of dice where the 
 *      user can specify the type of dice beng rolled by entering 
 *      a tokenized string like "1.d.20" which is a die of size
 *      20 rolled once
 * 
 * Public Methods
 *      Dice()
 *      Dice(int n, int s)                
 *      Dice(string d)                   
 *      void init(int n, int s) 
 *      int  roll(int rolls=1) //default parameter so it has to roll once
 *      int MaxRoll()
 *      int avgRoll()
 *      friend ostream& operator <<(ostream &os,const Dice& d) 
 * 
 * Private Methods:   
 *      vector<Die> dice
 *      bool average
 *      bool best
 *      bool constant    
 * 
 * Usage:
 *      
 *    Dice  dice(2,6)                //creates two 6 sided die
 *    Dice  dice("1.d.20")           //creates one 10 sided die
 *    dice.roll(2)              // rolls the dice twice
 *    dice.maxRoll()              //outputs the max possible roll
 *    dice.avgRoll()              // outputs the average roll of the dice
 *    cout << dice                 // displas the sizes of the dice  
 *    
*/ 

class Dice {
private:
    vector< Die > dice;
    bool average;
    bool best;
    bool constant;

public:
 /**
 * Public : Dice
 *
 * Description:
 * Default Constructor to create 1 6 sided die
 */   
    Dice() {
        init(1,6);
    }
 /**
 * Public : Dice
 *
 * Description:
 * Constructor that takes in the number of die and the amount of sides for the die being created
 * 
 * Params:
 *      int     n
 *      int     s
 */ 
    Dice(int n, int s) {
        init(n,s);
    }
 /**
 * Public : Dice
 * Description:
 * Constructor that takes in a tokenized string to create dice
 * Params:
 * string d
 */ 
    Dice(string d){
        vector<string> parts = split(d,".");

        int n = stoi(parts[0]);
        int s = stoi(parts[2]);

        init(n,s);
    }
/**
 * Public : init
 *
 * Description:
 * Initialization class to create the dices
 * Params:
 * int n
 * int s
 */ 
    void init(int n,int s){
        while (n--) {
            dice.push_back(Die(s));
        }
    }
/**
 * Public : roll
 *
 * Description:
 * Roll the dice and return the sum
 * Params:
 * int rolls
 * Returns:
 * int the result of the rolls 
 */ 
    int roll(int rolls = 1) {
        int sum = 0;
        while(rolls--){
            for (int i = 0; i < dice.size(); i++) {
                sum += dice[i].roll();

            }
        }
        return sum;
    }
/**
 * Public : maxRoll
 *
 * Description:
 * Roll the dice and return the maximum dice value
 * Returns:
 *      int max value of all die being rolled 
 */ 
    int maxRoll() {
      int max = 0;
      for (int i = 0; i < 1000; i++) {
        int t = this->roll();
        if (t > max) {
            max = t;
        }
        }
        return max;
    }
/**
 * Public : maxRoll
 *
 * Description:
 * Roll the dice and return the AVG dice value
 * Returns:
 * int: AVG value of all die being rolled
 */ 
    
    int avgRoll() {
        int avg;
        int sum;
        sum = this->roll();
        avg = sum/dice.size();
        return avg;
    }

/**
 * Public : operator<<
 *
 * Description:
 * overloaded the ostream operator to allow the dice to be displayed [sides] by just using the << operators
 * Params:
 * ostream &os
 * Dice& d
 * Returns: ostream&         what will be passed to ostream
 */
    friend ostream& operator<<(ostream &os,const Dice& d){
        for(int i=0;i<d.dice.size();i++){
            os << d.dice[i];
        }
        return os;
    }
};
