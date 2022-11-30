//Breckin Hume

//Professor Terry Griffin

//Program 5: Bolniverse Fightclub

//Uses starter code provided by Terry Griffin in dice.hpp, fighter.hpp, helpers.hpp, and weapon.hpp

//Purpose: This program assembles two armies of soldiers to battle it out
//The soldiers are diverse as they feature: warriors, wizards, archers, dragonborne, and elves
//Of the two assembled armies, one army is an attacking force, and the other army is the defending force. 
//The main feature is the two armies will battle it out until one army is eliminated.

// neccesary Libraries and files
#include "dice.hpp"
#include "fighter.hpp"
#include "helpers.hpp"
#include "weapon.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <fstream>
//using namespace standard
using namespace std;
// function prototypes
int Percentages(int, int);


   // Public Method:
   // Method Name: Percentages
   // Parameters: int total and int n
   // Purpose: Calculate %s for the sake of convenience
int Percentages(int total, int n) {
  double temp = (double)n / total;
  return temp * 100;
  }
int main(int argc, char** argv) {
  
  string file_name = "temp";


  // all variables used
  //infile for the sake of input file
  ifstream infile;

  //temp file for various uses
  int temp;
  
  if(argc < 2){
    cout<<"Error: need filename param.";
      exit(0);
  }
  file_name = argv[1];

  cout<<file_name<<endl;
  
  // For the sake that each battle is different
  srand(time(0));

  //String filename so it allows the use of any input file. In this case we use recruitlist.dat
  
  
  //An int to keep track of victories claimed by attackers
  int attacker_victory = 0;
  
  //An int to keep track of victories claimed by defenders
  int defender_victory = 0;
  //A pointer that points to the current attacker
  BaseFighter *this_attacker;
  
  //A pointer that points to the current defender
  BaseFighter *this_defender;
  //An int to keep track of the number of attackers
  int AttackingForce;

  //An int to keep track of the number of defenders
  int DefendingForce;

  //An int that keeps track of the number of encounters or 'skirmishes' between the attackers and defenders.
  int skirmish_count = 0;
  
  // Requesting the input file name. In this case we use recruitlist.dat
  // cout << "What is the name of the file used for recruiting the attackers? ";
  // cin >> file_name;

  infile.open(file_name);
  // cout << flush;
  // system("clear");
//After asking for the file name and obtaining it, we clear the console.
  

// creating both armies
  Attackers attack(infile);
  Defender defend(attack.Size());
  DefendingForce = defend.Size();
  AttackingForce = attack.Size();

  
  //The main loop that will keep going until one army is whiped out. This initiates the battle 
  while ((attack.Size() > 0) && (defend.Size() > 0)) {
    int count = 0;
    this_attacker = &attack[0];
    this_defender = &defend[0];
    temp = 0;
    // finding matching defender to fight attacker
    while ((this_defender->getname() != this_attacker->getname()) &&
           (temp < defend.Size())) {
      temp++;
      if (temp < defend.Size()) {
        this_defender = &defend[temp];
      }
    }
    
    if (temp == (defend.Size())) {
      temp = 0;
      this_defender = &defend[temp];
    }
    cout << "Attacking Forces remaining: " << attack.Size() << "               "
         << "Defending Forces remaining: " << defend.Size() << endl;
    cout << "Attacker: " << *this_attacker << " vs "
         << "Defender: " << *this_defender << endl;

// The battle begins here
    while (this_defender->remains() && this_attacker->remains()) {

// Determining who gets initiative or who goes first
      if (this_defender->initiative() >= this_attacker->initiative()) {
        // For if the defender gets the initiative and goes first
        this_attacker->setHP(this_attacker->getHP() -this_defender->attack());
        if (this_attacker->remains() == true) {
          //if that allows for the attacker to counterattack if they survive the defenders attack
          this_defender->setHP(this_defender->getHP() - this_attacker->attack());
        }
      } else {
        //For if the attacker gains initiative and strikes first
        this_defender->setHP(this_defender->getHP() - this_attacker->attack());
        if (this_defender->remains() == true) {
          //For if the defender survives the attack and gets to counterattack
          this_attacker->setHP(this_attacker->getHP() - this_defender->attack());
        }
      }
      // The end of the attack phase. Fighters on both sides will regenerate and a tally will be added to the skirmish count
      defend.regeneration();
      attack.regeneration();
      skirmish_count++;
    }
    // Checks to see if both fighters are still standing
    // For if the attacker lost the skirmish
    if (this_attacker->remains() == false) {
      cout << "ATTACKER DIED.";
      cout << flush;
      usleep(200000);
      system("clear");
      attack.remove();
      defender_victory++;
    }
    if (this_defender->remains() == false) {
      cout << "DEFENDER DIED.";
      cout << flush;
      usleep(200000);
      system("clear");
      defend.pop(temp);
      temp = 0;
      attacker_victory++;
    }
  }
  // displaying victory messages based on which side wins 
  if (defend.Size() == 0) {
    cout << "ATTACKERS WIN!!" << endl;
    cout << endl << endl;
    cout << "============================================================================="<<endl;
    cout << "Scoreboard: " << endl;
    cout << "There were  " << skirmish_count << " skirmishes." << endl;
    cout << "Attacking Victories: " << attacker_victory << " "
         << Percentages(skirmish_count, attacker_victory) << "%" << endl;
    cout << "Defending Victories: " << defender_victory << " "
         << Percentages(skirmish_count, defender_victory) << "%" << endl;
  }
  if (attack.Size() == 0) {
    cout << "DEFENDERS WIN!!" << endl;
    
    cout << "There were  " << skirmish_count << " skirmishes." << endl;
    cout << "Attacking Victories: " << attacker_victory << " "
         << Percentages(skirmish_count, attacker_victory) << "%" << endl;
    cout << "Defending Victories: " << defender_victory << " "
         << Percentages(skirmish_count, defender_victory) << "%" << endl;
  }
  infile.close();
}

