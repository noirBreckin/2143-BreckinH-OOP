//Breckin Hume
//2143 OOP
//Terry Griffin
//This program utilizes starter code provided by Prof. Griffin
//I thank him for allowing the use of this code and the emojis it lets us use here
//This is...the RPSLS Program
#include <iostream>
//#include "emoji.h"    //https://github.com/99x/emojicpp
#include <functional>  // needed for `bind`
#include <map>
#include <random>
#include <string>
#include <cstdlib>

using namespace std;

#define ROCK u8"\U0000270A"
#define PAPER u8"\U0000270B"
#define SCISSORS u8"\U0001F44C"
#define LIZARD u8"\U0001F918"
#define SPOCK u8"\U0001F596"

#define ROCK2 u8"\U0001F5FB"
#define PAPER2 u8"\U0001F4C3"
#define SCISSORS2 u8"\U0001F52A"
#define LIZARD2 u8"\U0001F438"
#define SPOCK2 u8"\U0001F596"

/**
 * This class is used to test the random number generators by creating an
 * array with the same sides as some die. Then counting the values generated
 * between 1 and die size. There should be an equal number in every slot, which
 * for a 20 sided die is about .05 or 5 percent in each.
 * 
 */
class Tester {
    int* arr;
    int  size;

public:
    Tester() : size{20} {
        arr = new int[size + 1];
        initArr();
    }

    Tester(int size) : size{size} {
        arr = new int[size + 1];
        initArr();
    }

    void initArr() {
        for (int i = 0; i < size + 1; i++) {
            arr[i] = 0;
        }
    }

    // add random value to distribution table
    void load(int i) {
        arr[i]++;
    }

    // generate  the distribution table
    void distro(double res[], double total) {
        for (int i = 0; i < size + 1; i++) {
            res[i] = (double)arr[i] / total;
        }
    }
};

/**
 * RandRoll
 * @description: A class to implement roll playing dice rolls.
 * @methods:
 * private:
 *      int Random(Max) : returns a value between 0 and max.
 *      int Random(Min , Max) : returns a value between min and max
 *      void init(int , int)  : initialize class
 * public:
 *      DieRoll()
 *      DieRoll(int)
 *      DieRoll(int,int)
 *      void setDie(int)    : set sides
 *      int Roll(int,int)   :  NEEDS FIXING!!!!!!
 */
class DieRoll {
    int sides;

    int Random(int max) {
        return 1 + (rand() % max);
    }

    // min = 40 max = 100
    int Random(int min, int max) {
        return 1 + min + (rand() % (max - min));
    }
    void init(int _seed, int _sides) {
        sides = _sides;
        srand(_seed);
    }
public:
    DieRoll() {
        //cout << "default base" << endl;
        init(time(0), 6);
    }
    DieRoll(int _seed) {
        //cout << "overloaded const" << endl;
        init(_seed, 6);
    }
    DieRoll(int _seed, int _sides) {
        //cout << "overloaded const" << endl;
        init(_seed, _sides);
    }

    void setDie(int _sides) {
        sides = _sides;
    }

    // NEEDS FIXING!!!
    int Roll(int sides, int times) {
        int sum = 0;
        while (times--) {
            sum += Random(sides);
        }
        return sum;
    }
};


/**
 * RandRoll
 * @description: A random die roller using a "better" random
 *      number generator. Docs: https://www.cplusplus.com/reference/random/
 * 
 * @methods:
 *     int Roll(int)    : give the "sides" will return an int between 1 and sides inclusive.
 * 
 */
class RandRoll {
    default_random_engine           generator;
    uniform_int_distribution< int > dieMap[21];

public:
    /**
     * Constructor
     * 
     * @description: Create an stl array that has the common dice values
     *              loaded as uniform distribution types.
     * 
     *  Wasteful, as not every array location has a uniform distribution 
     *  associated with it. Could you make it less wasteful?
     */
    RandRoll() {
        dieMap[4] = uniform_int_distribution< int >(1, 4);
        dieMap[6] = uniform_int_distribution< int >(1, 6);
        dieMap[8] = uniform_int_distribution< int >(1, 8);
        dieMap[10] = uniform_int_distribution< int >(1, 10);
        dieMap[12] = uniform_int_distribution< int >(1, 12);
        dieMap[20] = uniform_int_distribution< int >(1, 20);
    }

    /**
     * Generate a random number depending on the "sides" of the dice.
     */
    int Roll(int sides) {
        int diceRoll = dieMap[sides](generator);
        return diceRoll;
    };
};

/**
 * Hands
 * 
 * @description: A static class that only has references to
 *      emojis for printing out Rock Paper Scissors Lizard Spock
 * 
 * @methods:
 *      string RandHand()   : returns a random hand (emoji) 
 *      string Rock()       : returns the emoji for "rock" 
 *      string Paper()      : returns the emoji for "paper" 
 *      string Scissors()   : returns the emoji for "scissors" 
 *      string Lizard()     : returns the emoji for "lizard" 
 *      string Spock()      : returns the emoji for "spock" 
 */
struct Hands {
    const string rock = ROCK2;
    const string paper = PAPER2;
    const string scissors = SCISSORS2;
    const string lizard = LIZARD2;
    const string spock = SPOCK2;

    static map< string, string > Emojis;  // stl map
    //         name  , emoji

    static map< string, string > Names;  // stl map
    //         emoji  , name

    static string RandHand() {
        auto it = Emojis.begin();  // iterator to front of map

        std::advance(it, rand() % Emojis.size());  // advance some random amnt
                                                   //   of steps

        string random_hand = it->second;  // grab emoji from map

        return random_hand;  // return rand emoji
    }

    static string Rock() {
        return Emojis["rock"];
    }
    static string Paper() {
        return Emojis["paper"];
    }
    static string Scissors() {
        return Emojis["scissors"];
    }
    static string Lizard() {
        return Emojis["lizard"];
    }
    static string Spock() {
        return Emojis["spock"];
    }
};

// initialize static data member for
// hands struct (class)
map< string, string > Hands::Emojis = {
    {"rock", ROCK2},
    {"paper", PAPER2},
    {"scissors", SCISSORS2},
    {"lizard", LIZARD2},
    {"spock", SPOCK2}};
// initialize static data member for
// hands struct (class)
map< string, string > Hands::Names = {
    {ROCK2, "rock"},
    {PAPER2, "paper"},
    {SCISSORS2, "scissors"},
    {LIZARD2, "lizard"},
    {SPOCK2, "spock"}};

/**
 * Rock Paper Scissors Lizard Spock
 * 
 * @description: A class to run the rock papers scissors game
 * 
 * Scissors cuts Paper
 * Paper covers Rock
 * Rock crushes Lizard
 * Lizard poisons Spock
 * Spock smashes Scissors
 * Scissors decapitates Lizard
 * Lizard eats Paper
 * Paper disproves Spock
 * Spock vaporizes Rock
 * Rock crushes Scissors
 */
class RPSLS : public DieRoll, public Hands {
public:
    
    RPSLS(): DieRoll(time(0)){
        string h = RandHand();
        cout<<Names[h]<<": " <<h<<endl;
    };
    RPSLS(int seed) : DieRoll(seed) {
        
    }
};

struct Emoji{
  string type;
};
//Class For Spock Rules
class Spock: public Emoji {
  bool operator <(const Emoji other){
     if(other.type == "Scissors"){
      cout<<SPOCK2<< " smashes " << SCISSORS2<< endl;
       return true;}
     else if(other.type == "Rock"){ 
       cout<<SPOCK2<<" vaporizes " <<ROCK2<<endl;  
       return true;
    }
     else
       return false;
    }
};
//Class for Rock Rules
class Rock: public Emoji {
  bool operator <(const Emoji other)
    {
     if(other.type == "Lizard"){
      cout<<ROCK2<< " crushes " << LIZARD2<< endl;
       return true;}
     else if(other.type == "Scissors"){
       cout<<ROCK2<<" crushes " <<SCISSORS2<<endl;
       return true;
    }
      else
       return false;
      }
};
//Class for Lizard Rules
class Lizard: public Emoji {
  bool operator <(const Emoji other){
     if(other.type == "Spock"){
      cout<<LIZARD2<< " poisons " << SPOCK2<< endl;
       return true;}
     else if(other.type == "Paper"){
       cout<<LIZARD2<<" eats " <<PAPER2<<endl;  
       return true;
    }
     else 
       return false;
    }
};
//Class for Paper Rules
class Paper: public Emoji {
  bool operator <(const Emoji other){
     if(other.type == "Spock"){
      cout<<PAPER2<< " disproves " << SPOCK2<< endl;
       return true;
       }
     else if(other.type == "Scissors"){
       cout<<PAPER2<<" covers " <<ROCK2<<endl;  
       return true;
    }
    else
       return false;
    }
};
//Class for Scissors Rules
class Scissors: public Emoji {
  bool operator <(const Emoji other){
     if(other.type == "Lizard"){
      cout<<SCISSORS2<< " decapitates " << LIZARD2<< endl; 
       return true; }
     else if(other.type == "Paper"){
       cout<<SCISSORS2<<" slices " <<PAPER2<<endl;  
       return true;
    }
     else
       return false;
    }
};
//Player Struct for Game Function
struct Player{

    string weapon;
    string weapon2;
    Player(){
        weapon = Hands::RandHand();
        weapon2 = Hands::RandHand();
      }
};



//GAME is the function that will run this game. It will create 2 instances of player and goes through each of the possibilities while also printing to console.
void GAME()
{
  
  Player P1;
  Player P2;

  cout << "Player 1 uses " << P1.weapon << endl;
  cout << "Player 2 uses " << P2.weapon << endl;


   if(P1.weapon == SCISSORS2 && P2.weapon == PAPER2)
    cout<<SCISSORS2<< "slices" << PAPER2<<endl;
  else if(P1.weapon == SCISSORS2 && P2.weapon == LIZARD2)
    cout<<SCISSORS2 "decapitates" LIZARD2<<endl;
  else if(P1.weapon == SCISSORS2 && P2.weapon == SPOCK2)
    cout<<SPOCK2 "smashes" SCISSORS2<<endl;
  else if(P1.weapon == SCISSORS2 && P2.weapon == ROCK2)
    cout<<ROCK2 "smashes" SCISSORS2<<endl;
  else if(P1.weapon == LIZARD2 && P2.weapon == SPOCK2)
    cout<<LIZARD2 "poisons" SPOCK2 <<endl;
  else if(P1.weapon == LIZARD2 && P2.weapon == PAPER2)
    cout<<LIZARD2 "eats" PAPER2 <<endl;
  else if(P1.weapon == LIZARD2 && P2.weapon == SCISSORS2)
    cout<<SCISSORS2 "decapitates" LIZARD2<<endl;
  else if(P1.weapon == LIZARD2 && P2.weapon == ROCK2)
    cout<<ROCK2 "smashes" LIZARD2<<endl;
  else if(P1.weapon == PAPER2 && P2.weapon == LIZARD2)
    cout<<LIZARD2 "eats" PAPER2<<endl;
  else if(P1.weapon == PAPER2 && P2.weapon == SCISSORS2)
    cout<<SCISSORS2 "slices" PAPER2<<endl;
  else if(P1.weapon == PAPER2 && P2.weapon == ROCK2)
    cout<<PAPER2 "covers" ROCK2<<endl;
  else if(P1.weapon == PAPER2 && P2.weapon == SPOCK2)
    cout<<PAPER2 "disproves" SPOCK2<<endl;
  else if(P1.weapon == SPOCK2 && P2.weapon == LIZARD2)
    cout<<LIZARD2 "poisons" SPOCK2<<endl;
  else if(P1.weapon == SPOCK2 && P2.weapon == PAPER2)
    cout<<PAPER2 "disproves" SPOCK2<<endl;
  else if(P1.weapon == SPOCK2 && P2.weapon == ROCK2)
    cout<<SPOCK2 "vaporizes" ROCK2<<endl;
  else if(P1.weapon == SPOCK2 && P2.weapon == SCISSORS2)
    cout<<SPOCK2 "smashes" SCISSORS2<<endl;
  else if(P1.weapon == ROCK2 && P2.weapon == LIZARD2)
    cout<<ROCK2 "crushes" LIZARD2<<endl;
  else if(P1.weapon == ROCK2 && P2.weapon == SCISSORS2)
    cout<<ROCK2 "crushes" SCISSORS2<<endl;
  else if(P1.weapon == ROCK2 && P2.weapon == SPOCK2)
    cout<<SPOCK2 "vaporizes" ROCK2<<endl;
  else if(P1.weapon == ROCK2 && P2.weapon == PAPER2)
    cout<<PAPER2 "covers" ROCK2<<endl;
  else if(P1.weapon == P2.weapon){
    cout<<"It's a tie! Resort to alternative weapons!!"<<endl;
    P1.weapon = P1.weapon2;
    P2.weapon = P2.weapon2;
    cout<<"Player 1 uses " <<P1.weapon2<<endl;
    cout<<"Player 2 uses " <<P2.weapon2<<endl;
    GAME();
  }
}


int main() {
      
    cout << "Rock: " << ROCK2 << endl;
    cout << "Paper: " << PAPER2 << endl;
    cout << "Scissors: " << SCISSORS2 << endl;
    cout << "Lizard: " << LIZARD2 << endl;
    cout << "Spock: " << SPOCK2 << endl;

   GAME();
}
