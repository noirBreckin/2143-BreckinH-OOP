#include <iostream>
#include "emoji.h"    //https://github.com/99x/emojicpp
#include <functional>  
#include <map>
#include <random>
#include <string>

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

struct Emoji{
  string type;
};

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
struct Player{

    string weapon;
   
    // Player(){
    //     weapon = Hands::RandHand();
    //   }
};

void GAME() {
  
   
}

int main() {
  

  
    cout << "Rock: " << ROCK2 << endl;
    cout << "Paper: " << PAPER2 << endl;
    cout << "Scissors: " << SCISSORS2 << endl;
    cout << "Lizard: " << LIZARD2 << endl;
    cout << "Spock: " << SPOCK2 << endl;

    Spock();
    Rock();
    Scissors();
    Lizard();
    Paper();

  Player P1;
  Player P2;

  P1.weapon = Hands::RandHand();
  P2.weapon = Hands::RandHand();
  
  cout <<  P1.weapon << endl;
  cout << P2.weapon << endl;
  
}
