#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "weapon.hpp"
#include "helpers.hpp"
#include <algorithm>
#include <cstdlib>
#include <fstream>

//using namespace std
using namespace std;

#pragma once
/**
 * Public : fRand
 *
 * Description:
 *        
 *    allows to get a random double number with a given range of 
 *    double  
 * 
 * Params:
 *      double        fMin
 *      double        fMax
 *
 * Returns:
 *     double         :random double generated
 */ 
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
/**
 * BaseFighter
 * 
 * Description: 
 *     This class is the base fighter for every class of fighter to be 
 *     derived from. Containing the attributes and methods that are used 
 *      by all of the classes and allowing for methods to be overridden 
 *      by these classes
 * 
 * Public Methods
 *                        BaseFighter()
 *     virtual double     attack()
 *     virtual int        getHP()
 *     virtual  void      setHP(int h)
 *     virtual  void      setHP(double h)
 *      virtual double    getregen()
 *     virtual string     getname()
 *     virtual bool       remains()
 *      virtual int       initiative()
 *     virtual MaxHp      getMaxHP()
 *     friend double      fRand(double,double)
 *      virtual string    Print()
 *     friend ostream&    operator<<(ostream& os, BaseFighter& f)
 *                             
 * 
 * Private Methods:   
 *        string          name
 *        Weapon          *weapon
 *        int             HP
 *        double          regen
 *        int             speed
 *        int             MaxHP 
*/ 
class BaseFighter {
protected:

    string name;
    Weapon *weapon;
    int HP;
    double regen;
    int speed;
    int MaxHP;
public:
/**
 * Public : BaseFighter
 *
 * Description:
 *        
 *    Default constructor to create a base fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */ 
    BaseFighter() {
        name = "None";
        weapon = new Weapon;
    }
/**
 * Public : attack
 *
 * Description:
 *        
 *    uses the fighter's weapon and returns the damage dealt
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     the damage dealt
 */ 
    virtual double attack(){
        return weapon->use();
    }
/**
 * Public : getHP
 *
 * Description:
 *        
 *    Returns the current HP of the fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     The current HP of the fighter
 */ 
virtual int getHP(){
  return HP;
}
/**
 * Public : setHP
 *
 * Description:
 *        
 *    sets the current HP of the fighter
 * 
 * Params:
 *      int h: the new HP of the fighter
 *
 * Returns:
 *    N/A
 */ 
virtual void setHP(int h){
  HP = h;
}
/**
 * Public : setHP
 *
 * Description:
 *        
 *    sets the current HP of the fighter
 * 
 * Params:
 *      double h: the new HP of the fighter
 */ 
virtual void setHP(double h){
  HP = h;
}
/**
 * Public : getregen
 *
 * Description:
 *        
 *    Returns the Regeneration Rate of the fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     double:The current Regeneration Rate of the fighter
 */
virtual double getregen(){
  return regen;
}
/**
 * Public : getname
 * Returns:
 *     string      :The name of the fighter
 */
virtual string getname(){
  return name;
}
/**
 * Public : remains
 *
 * Description:
 *        
 *    Checks if the fighter's curren HP is 0 if it is 
 *    or less then return false of else return true
 */
virtual bool remains(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}
/**
 * Public : getspeed
 * Returns:
 *     string      :The speed of the fighter
 */
virtual int initiative(){
  return speed;
}
/**
 * Public : getMaxHP
 * Returns:
 *     string      :The max possible hp of the fighter
 */
virtual int getMaxHP(){
  return MaxHP;
}
//defined outside of class 
friend double fRand(double, double);
/**
 * Public : Print
 *
 * Description:
 *        
 *    Methods creates a string with all the relevant information of the 
 *    fighter in a specified format [name,weapon name,weapon damage,]
 * Returns:
 *     string      :The resulting string
 */
    virtual string Print(){
      string temp = "";
      temp += "["; 
      temp += name;
      temp+= " , ";
      temp+= "[";
      temp+= weapon->getName();
      temp+=" , ";
      temp+= weapon->getDamage();
      temp+= "]";
      temp+= "]";
      return temp;
    }
/**
 * Public : operator<<
 *
 * Description:
 *        
 *    overloaded ostream operator to display the string created from 
 *    the Print method

 * Returns:
 *      ostream& :what is passed to ostream
 */
 friend ostream& operator<<(ostream& os, BaseFighter& f) {
        return os << f.Print();
    }


};
/**
 * Warrior: Public BaseFighter
 * 
 * Description: 
 *     This is a Warrior fighter class that is derived from the Base Fighter class and uses methods from Base Fighter
 * 
 * Public Methods
 *                        Warrior()
 *     double             attack()
 *     int                getHP()
 *     void               setHP(int h)
 *     void               setHP(double h)
 *     double             getregen()
 *     string             getname()
 *     bool               isAlive()
 *     int                getspeed()
 *     MaxHp              getMaxHP()
 *     friend double      fRand(double,double)
 *                            
 * 
 * Private Methods:   
 *        int             HP
 *        double          regen
 * 
 *   
 *    
*/ 
class Warrior : public BaseFighter{
private: 
  int HP;
  double regen;
public:
/**
 * Public : Warrior
 *
 * Description:
 *        
 *    Default constructor to create a Warrior fighter 
 */
  Warrior(){
    
    name = "Warrior";
    HP = (rand()%8+5);
    MaxHP = HP;
    regen = fRand(0.15,0.75);
    speed = rand()%10+3;
    int WD = (rand()%2+4);
    if(WD==1){
      weapon = new Weapon("Sword","1.d.4");
      }
    else{
      weapon = new Weapon("Sword","1.d.6");
    }  
  }
  // All overriden from the BaseFighter Class
double attack(){
  return weapon->use();
}
int getHP(){
  return HP;
}
void setHP(int h){
  HP = h;
}
void setHP(double h){
  HP = h;
}
double getregen(){
  return regen;
}
string getname(){
  return name;
}
bool remains(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}
int initiative(){
  return speed;
}
int getMaxHP(){
  return MaxHP;
}
friend double fRand(double, double);
};
/**
 * Wizard: Public BaseFighter
 * 
 * Description: 
 *     This is a Wizard fighter class that is derived from the Base Fighter class and uses methods from Base Fighter
 * 
 * Public Methods
 *                        Wizard()
 *     double             attack()
 *     int                getHP()
 *     void               setHP(int h)
 *     void               setHP(double h)
 *     double             getregen()
 *     string             getname()
 *     bool               isAlive()
 *     int                getspeed()
 *     MaxHp              getMaxHP()
 *     friend double      fRand(double,double)
 *                            
 * 
 * Private Methods:   
 *        int             HP
 *        double          regen
 * 
 *   
 *    
*/ 
class Wizard : public BaseFighter{
private: 
  int HP;
  double regen;
public:
/**
 * Public : Wizard
 *
 * Description:
 *        
 *    Default constructor to create a Wizard fighter 
 */
  Wizard(){
    name = "Wizard";
    HP = (rand()%8+3);
    MaxHP = HP;
    regen = fRand(0.15,0.75);
    speed = rand()%10+2;
    int WD = (rand()%4+2);
    if(WD==1){
      weapon = new Weapon("Firaga","1.d.20");
      }
    else if (WD==2){
      weapon = new Weapon("Thundaga","2.d.10");
    }  
    else if (WD == 3){
      weapon = new Weapon("Blizzaga","d.6");
    }
    else{
      weapon = new Weapon("Meteor","5.d.4");
    }
  }
// all overriden methods from the BaseFighter Class
double attack(){
  return weapon->use();
}
int getHP(){
  return HP;
}
void setHP(int h){
  HP = h;
}
void setHP(double h){
  HP = h;
}
double getregen(){
  return regen;
}
bool remains(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}
int initiative(){
  return speed;
}
int getMaxHP(){
  return MaxHP;
}
friend double fRand(double, double);
};
/**
 * Archer: Public BaseFighter
 * 
 * Description: 
 *     This is a Archer fighter class that is derived from the Base Fighter class and uses methods from Base Fighter
 * 
 * Public Methods
 *                        Archer()
 *     double             attack()
 *     int                getHP()
 *     void               setHP(int h)
 *     void               setHP(double h)
 *     double             getregen()
 *     string             getname()
 *     bool               isAlive()
 *     int                getspeed()
 *     MaxHp              getMaxHP()
 *     friend double      fRand(double,double)
 *                            
 * 
 * Private Methods:   
 *        int             HP
 *        double          regen
 *    
*/ 
class Archer : public BaseFighter{
private: 
  int HP;
  double regen;
public:
/**
 * Public : Wizard
 *
 * Description:
 *        
 *    Default constructor to create a Archer fighter 
 */
  Archer(){
    srand(time(0));
    name = "Archer";
    HP = (rand()%8+3);
    MaxHP = HP;
    regen = fRand(0.15,0.75);
    speed = rand()%10+1;
    int WD = (rand()%3+1);
    
    if(WD==1){
      weapon = new Weapon("Iron Arrow","1.d.8");
      }
    else if (WD==2){
      weapon = new Weapon("Steel Arrow","2.d.4");
    }  
    else{
      weapon = new Weapon("Magic Arrow","1.d.10");
    }
  }
// overridden methods of the Base Fighter
double attack(){
  return weapon->use();
}
int getHP(){
  return HP;
}
void setHP(int h){
  HP = h;
}
void setHP(double h){
  HP = h;
}
double getregen(){
  return regen;
}
bool remains(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}
int initiative(){
  return speed;
}
int getMaxHP(){
  return MaxHP;
}
friend double fRand(double, double);
};
/**
 * Elf: Public BaseFighter
 * 
 * Description: 
 *     This is a Elf fighter class that is derived from the Base Fighter class
 *     and overrides all the methods of BaseFighter but adds another weapon 
 * 
 * Public Methods
 *                        Elf()
 *     double             attack()
 *     int                getHP()
 *     void               setHP(int h)
 *     void               setHP(double h)
 *     double             getregen()
 *     string             getname()
 *     bool               isAlive()
 *     int                getspeed()
 *     MaxHp              getMaxHP()
 *     friend double      fRand(double,double)
 *     string             Print()                        
 * 
 * Private Methods:   
 *        int             HP
 *        double          regen 
 *        Weapon          *weapon2
 * 
 *    
*/ 
class Elf : public BaseFighter{
private: 
  int HP;
  double regen;
  Weapon *weapon2;
public:
  Elf(){
/**
 * Public : Elf
 *
 * Description:
 *        
 *    Default constructor to create an Elf fighter 
 */
    name = "Elf";
    HP = (rand()%8+3);
    MaxHP = HP;
    regen = regen = fRand(0.15,0.75);
    speed = rand()%10+1;
    int WD = (rand()%4+1);
    if(WD==1){
      weapon = new Weapon("Magic Dagger","1.d.20");
      }
    else if (WD==2){
      weapon = new Weapon("Magic Sword","2.d.10");
    }  
    else if (WD == 3){
      weapon = new Weapon("Meteoric Rainfall","3.d.6");
    }
    else{
      weapon = new Weapon("Death Ray","5.d.4");
    }
    int WD2 = (rand()%2+1);
    if(WD2==1){
      weapon2 = new Weapon("Shortsword","1.d.4");
      }
    else{
      weapon2 = new Weapon("Broadsword","1.d.6");
    } 

  }
/**
 * Public : attack
 *
 * Description:
 *        
 *    uses the fighter's weapon and returns the damage dealt. Since
 *    Elf has two weapons it combines the damage of both weapons
 * Returns:
 *     double :the damage dealt
 */ 
double attack(){
  return (weapon->use()+weapon2->use());
}
//overridden methods from BaseFighter clsss
int getHP(){
  return HP;
}
void setHP(double h){
  HP = h;
}
void setHP(int h){
  HP = h;
}
double getregen(){
  return regen;
}
bool remains(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}
int initiative
(){
  return speed;
}
int getMaxHP(){
  return MaxHP;
}
friend double fRand(double, double);
/**
 * Public : Print
 *
 * Description:
 *        
 *    Methods creates a string with all the relevant information of the 
 *    fighter in a specified format [name,[weapon 1 name,weapon1 damage],[weapon 2 name,
 *    weapon 2 damage]]
 * Returns:
 *     string      :The resulting string
 */
 string Print(){
      string temp = "";
      temp += "["; 
      temp += name;
      temp+= " , ";
      temp+= "[";
      temp+= weapon->getName();
      temp+=" , ";
      temp+= weapon->getDamage();
      temp+= "]";
      temp+= "[";
      temp+= weapon2->getName();
      temp+=" , ";
      temp+= weapon2->getDamage();
      temp+= "]";
      temp+= "]";
      return temp;
    }
};
/**
 * Dragonborn: Public BaseFighter
 * 
 * Description: 
 *     This is a Dragonborn fighter class that is derived from the Base Fighter class
 *     and overrides all the methods of BaseFighter but adds another weapon 
 * 
 * Public Methods
 *                        Dragonborn()
 *     double             attack()
 *     int                getHP()
 *     void               setHP(int h)
 *     void               setHP(double h)
 *     double             getregen()
 *     string             getname()
 *     bool               isAlive()
 *     int                getspeed()
 *     MaxHp              getMaxHP()
 *     friend double      fRand(double,double)
 *     string             Print()                        
 * 
 * Private Methods:   
 *        int             HP
 *        double          regen 
 *        Weapon          *weapon2  
*/
class Dragonborn: public BaseFighter{
private: 
  int HP;
  double regen;
  Weapon *weapon2;
public:
/**
 * Public : Dragonborn
 *
 * Description:
 *        
 *    Default constructor to create an Dragonborn fighter 
 */
  Dragonborn(){
    name = "DragonBorn";
    HP = (rand()%8+3);
    MaxHP = HP;
    regen = fRand(0.15,0.75);
    speed = rand()%10+1;
    int WD = (rand()%4+1);
    if(WD==1){
      weapon = new Weapon("Magic Punch","1.d.20");
      }
    else if (WD==2){
      weapon = new Weapon("Magic Slash","2.d.10");
    }  
    else if (WD == 3){
      weapon = new Weapon("Magic Stab","3.d.6");
    }
    else{
      weapon = new Weapon("Magic Yell","5.d.4");
    }
    int WD2 = (rand()%2+1);
    if(WD2==1){
      weapon2 = new Weapon("Fira","1.d.6");
      }
    else{
      weapon2 = new Weapon("Firaga","1.d.8");
    } 

  }
//overridden method from BaseFighter
bool remains(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}
/**
 * Public : attack
 *
 * Description:
 *    uses the fighter's weapon and returns the damage dealt. Since
 *    Dragonborn has two weapons it combines the damage of both weapons

 * Returns:
 *     double :the damage dealt
 */ 
double attack(){
  return (weapon->use()+weapon2->use());
}
int getHP(){
  return HP;
}
void setHP(int h){
  HP = h;
}
void setHP(double h){
  HP = h;
}
double getregen(){
  return regen;
}
int initiative(){
  return speed;
}
int getMaxHP(){
  return MaxHP;
}
friend double fRand(double, double);
/**
 * Public : Print
 *
 * Description:
 *        
 *    Methods creates a string with all the relevant information of the 
 *    fighter in a specified format [name,[weapon 1 name,weapon1 damage],[weapon 2 name,
 *    weapon 2 damage]]
 * Returns:
 *     string      :The resulting string
 */
string Print(){
      string temp = "";
      temp += "["; 
      temp += name;
      temp+= " , ";
      temp+= "[";
      temp+= weapon->getName();
      temp+=" , ";
      temp+= weapon->getDamage();
      temp+= "]";
      temp+= "[";
      temp+= weapon2->getName();
      temp+=" , ";
      temp+= weapon2->getDamage();
      temp+= "]";
      temp+= "]";
      return temp;
    }
};
/**
 * Attackers
 * 
 * Description: 
 *     This is a class uses a vector containing a group of BaseFighter Pointers then 
 *     points these pointers to a fighter class (dynamic polymorphispm) and fills the 
 *     vector with these pointers to create a group of attackers 
 * 
 * Public Methods
 *                        Attackers()                      
 *                        Attackers(int s)
 *                        Attackers(ifstream& in)
 *    BaseFighter&        operator[](int index)
 *    int                 Size()
 *    void                remove()
 *    void                regen()
 * 
 * Private Methods:   
 *    vector<BaseFighter *>     attackers
 *    int                       WarriorC
 *    int                       WizardC
 *    int                       ArcherC
 *    int                       ElfC
 *    int                       DBC
 *    int                       size  
*/
class Attackers{
private:
vector<BaseFighter *> attackers;
int WarriorC;
int WizardC;
int ArcherC;
int ElfC;
int DBC;
int size;
protected:
public:
/**
 * Public : Attackers
 *
 * Description:
 *        
 *    Default constructor of the attacker class that fills the vector 
 *    with 1000 elements and varies the types of fighter based on a ratio
 *    then randomizes the group
 */
Attackers(){
  srand(time(0));
  WarriorC = 1000*0.35;
  ArcherC = 1000*0.35;
  WizardC = 1000*0.20;
  ElfC = 1000*0.05;
  DBC = 1000*0.05;
  for(int i = 0; i < WarriorC; i++){
    attackers.push_back(new Warrior);
  }
  for(int i = 0; i < ArcherC; i++){
    attackers.push_back(new Archer);
  }
  for(int i = 0; i < WizardC; i++){
    attackers.push_back(new Wizard);
  }
  for(int i = 0; i < ElfC; i++){
    attackers.push_back(new Elf);
  }
  for(int i = 0; i < DBC; i++){
    attackers.push_back(new Dragonborn);
  }
  size = attackers.size();
  random_shuffle(attackers.begin(),attackers.end());
}
/**
 * Public : Attackers
 *
 * Description:
 *        
 *    Default constructor of the attacker class that fills the vector 
 *    with a given number of elements and varies the types of fighter based on a ratio
 *    then randomizes the group
 */
Attackers(int s){
  srand(time(0));
  WarriorC = s*0.35;
  ArcherC = s*0.35;
  WizardC = s*0.20;
  ElfC = s *0.05;
  DBC = s *0.05;
  for(int i = 0; i < WarriorC; i++){
    attackers.push_back(new Warrior);
  }
  for(int i = 0; i < ArcherC; i++){
    attackers.push_back(new Archer);
  }
  for(int i = 0; i < WizardC; i++){
    attackers.push_back(new Wizard);
  }
  for(int i = 0; i < ElfC; i++){
    attackers.push_back(new Elf);
  }
  for(int i = 0; i < DBC; i++){
    attackers.push_back(new Dragonborn);
  }
  size = attackers.size();
  random_shuffle(attackers.begin(),attackers.end());
}
/**
 * Public : Attackers
 *
 * Description:
 *        
 *    Default constructor of the attacker class that fills the vector 
 *    with data from an input file and varies the types of fighter based on a ratio
 *    then randomizes the group
 */
Attackers(ifstream& in){
  in.clear();
  
  string fighter;
  
  cout<<fighter<<endl;
  
  while (getline(in, fighter)){
    if(fighter == "Warrior"){
      WarriorC++;
    }
    else if(fighter == "Archer"){
      ArcherC++;
    }
    else if(fighter == "Wizard"){
      WizardC++;
    }
    else if(fighter == "Elf"){
      ElfC++;
    }
    else{
      DBC++;
    }
    in>>fighter;
  }
  
  cout<<"here";
  for(int i = 0; i < WarriorC; i++){
    attackers.push_back(new Warrior);
  }
  for(int i = 0; i < ArcherC; i++){
    attackers.push_back(new Archer);
  }
  for(int i = 0; i < WizardC; i++){
    attackers.push_back(new Wizard);
  }
  for(int i = 0; i < ElfC; i++){
    attackers.push_back(new Elf);
  }
  for(int i = 0; i < DBC; i++){
    attackers.push_back(new Dragonborn);
  }
  size = attackers.size();
  random_shuffle(attackers.begin(),attackers.end());
  
}
/**
 * Public : operator[]
 *
 * Description:    
 *   Overloading the [] operators to access the elements
 *   using the class name similarly to an array
 * 
 * Params:
 *      int index
 *
 * Returns:
 *     Basefighter& the address of the fighter in storage
 */
 BaseFighter& operator[](int index){
   
   if(index > attackers.size()){
     cout << "invalid index";
     return *attackers[0];
     
   }
   else{
    
     return *attackers[index];
   }
 }
 /**
 * Public : Size
 *
 * Description:
 *        
 *   returns the size of the attacker group
 * Returns:
 *     int      the size of the group of attackers
 */
int Size(){
  return attackers.size();
}
/**
 * Public : remove
 *
 * Description:
 *        
 *   removes the first element from the vector
 */
void remove(){
  if(attackers.size()==1){
    attackers.pop_back();
  }
  else{
    attackers.erase(attackers.begin());
  } 
}
/**
 * Public : regen
 *
 * Description:
 *        
 *   gives HP back to the attacker at the front of the group based on its
 *   regeneration rate
 */
void regeneration(){
  if(attackers.front()->getHP()<attackers.front()->getMaxHP()){
    attackers.front()->setHP((int)(attackers.front()->getHP()+(attackers.front()->getHP()*attackers.front()->getregen())));
    if(attackers.front()->getHP()>attackers.front()->getMaxHP()){
      attackers.front()->setHP(attackers.front()->getMaxHP());
    }
  }
}
};
/**
 * Attackers
 * 
 * Description: 
 *     This is a class uses a vector containing a group of BaseFighter Pointers then 
 *     points these pointers to a fighter class (dynamic polymorphispm) and fills the 
 *     vector with these pointers to create a group of defenders and this group of 
 *    defenders are based on the size of the group of attackers 100 attackers to 1 
 *    defenders
 * 
 * Public Methods
 *    Defender()                      
 *    Defender(int x)
 *    BaseFighter& operator[](int index)
 *    int   Size()
 *    void  remove(int x)
 *    void  regen()
 * 
 * Private Methods:   
 *    vector<BaseFighter *> attackers
 *    int size
*/
class Defender{
private: 
vector <BaseFighter *> defender;
int size;
protected:
public:
/**
 * Public : Defender
 *
 * Description:
 *        
 *    Default constructor of the defender class that fills the vector 
 *    with 1000/10 elements and varies the types of fighter are random
 */
Defender(){
  size = 1000/100;
  int select;
  for(int i = 0; i < size; i++){
    select = rand()%5+1;
    if(select == 1){
      defender.push_back(new Warrior);
    }
    else if(select == 2){
      defender.push_back(new Wizard);
    }
    else if(select == 3){
      defender.push_back(new Archer);
    }
    else if(select == 4){
      defender.push_back(new Elf);
    }
    else{
      defender.push_back(new Dragonborn);
    }
  }
  size = defender.size();
  random_shuffle(defender.begin(), defender.end());
}
/**
 * Public : Defender
 *
 * Description:
 *    Default constructor of the defender class that fills the vector 
 *    with n/10 elements and varies the types of fighter are random
 */
Defender(int n){
  size = n/100;
  int select;
  for(int i = 0; i < size; i++){
    select = rand()%5+1;
    if(select == 1){
      defender.push_back(new Warrior);
    }
    else if(select == 2){
      defender.push_back(new Wizard);
    }
    else if(select == 3){
      defender.push_back(new Archer);
    }
    else if(select == 4){
      defender.push_back(new Elf);
    }
    else{
      defender.push_back(new Dragonborn);
    }
  }
  size = defender.size(); 
  random_shuffle(defender.begin(), defender.end());
}
/**
 * Public : operator[]
 *
 * Description:
 *        
 *   Overloading the [] operators to access the elements
 *   using the class name similarly to an array
 * 
 * Params:
 *      int index
 *
 * Returns:
 *     Basefighter& the address of the fighter in storage
 */
BaseFighter& operator[](int index){
   
   if(index > defender.size()){
     cout << "invalid index";
     return *defender[0];
     
   }
   else{
    
     return *defender[index];
   }
 }
  /**
 * Public : Size
 *
 * Description:
 * returns the size of the defender group
 * Returns:
 * int the size of the group of attackers
 */
int Size(){
  return defender.size();
}
/**
 * Public : pop
 *
 * Description:    
 *   removes an element from the group of defender based on the number 
 *   passed in 
 */
void pop(int i){
  if(defender.size()==1){
    defender.pop_back();
  }
  else{
    if(i <= 0){
      defender.erase(defender.begin());
    }
    else{
      defender.erase(defender.begin()+i);
    }
    
  } 
}
/**
 * Public : regeneration
 *
 * Description:     
 *   gives HP back to the all the members of the defender group based on all of 
 *   thier own personal regeneration rates 
 */
void regeneration(){
  for(int i = 0; i < defender.size(); i++){
    if(defender[i]->getHP()<defender[i]->getMaxHP()){
   defender[i]->setHP((int)(defender[i]->getHP()+(defender[i]-> getHP()*defender[i]->getregen())));
    if(defender[i]->getHP()>defender[i]->getMaxHP()){
      defender[i]->setHP(defender[i]->getMaxHP());
    }
  }
  }
}
};
