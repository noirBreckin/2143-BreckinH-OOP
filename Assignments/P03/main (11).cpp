#include <iostream>
#include <string>
#include "blackjack.hpp"
#include <vector>
#include <time.h>

//stdio.h, sys/ioctl.h, unistd.h 

using namespace std;


void GAME()
{
     //These are variables that will be used throughout the lifetime of the function
      char choice1; //Choice for hitting again or standing
      int betM = 500;//The amount the player can bet
      int wager;//The amount the player bets
      CardContainer Dealer;CardContainer Player;//Card containers for the Player and the Dealer
      

      //Interaction with the player and the set up of a wager
      cout<<"Alright lets deal the cards"<<endl;
      cout<<"How much will you wager?(Limit is $500)"<<endl;
      cin>>wager;
      betM -= wager;
      cout<<"With that bet in place you have " << betM << " remaining"<< endl<<endl;

      //Getting the hand ready for the player and the starting card ready for the dealer
      Card *Dealer1 = new Card(rand()%52);
      Card *Player1 = new Card(rand()%52);
      Card *Player2 = new Card(rand()%52);


      //The Starting Cards Get Dealt to the player and the dealer has their first card ready
      Dealer.Add(Dealer1);
      Player.Add(Player1);
      Player.Add(Player2);
  
      //Having ints in place to let the player know the amount the dealer has and the player has
      int dtotal = Dealer1->getRank();
      int ptotal = Player1->getRank() + Player2->getRank();

      //Interaction with the player to let them know the current cards and scores
      cout<<"Dealer:"<<endl;
      cout<<Dealer<<endl;
      cout<<"The amount the dealer has is " << dtotal << endl << endl;
      cout<<"Player:"<<endl;
      cout<<Player<<endl;
      cout<<"The amount the player has is " << ptotal << endl << endl;


      //Do while loop that lets the player hit as many times as they want or it allows them to 
      //stand with what they have
      do
      {
        cout<<"Would you like another card?(Type Y for yes or N for no)" << endl;
        cin>>choice1;
        if(choice1 == 'Y') 
        {
          Card *Player3 = new Card(rand()%52);
          Player.Add(Player3);
          ptotal += Player3->getRank();
          cout<<endl<<endl<<"Here is your hand with the new card added"<<endl<<endl<<Player;
          cout<<"Your new amount is " << ptotal << endl << endl;
        }

        
        
      }
      while(choice1 == 'Y');
        //Conditionals set up after the player finishes drawing or standing
        //The conditionals are here incase the player busts or hits exactly 31 and gets a blackjack
        if(ptotal > 31){
        cout<<"You have busted, the house wins";
        return;
        }
        else if(ptotal == 31){
          cout<<"YOOOO YOU WIN CONGRATS"<<endl;
          betM += (wager * 2);
         cout<<"You now have " << betM << " you lucky gambler! Nice!";
        return;
        }
        

      //This is where the dealer reveals the second card that they have
      //It also updates the terminal with the new card and score that the dealer has
        Card *Dealer2 = new Card(rand()%52);
        Dealer.Add(Dealer2);
        dtotal += Dealer2->getRank();
        cout<<endl<<endl<<"Here is the dealers updated hand"<<endl<<endl<<Dealer;
        cout<<"The dealers new score is " << dtotal << endl<<endl;


      //This do while will have the dealer draw until they have at least 25 to keep the sense of competition
      do
      {
        cout<<"The dealer chooses to draw another card"<<endl;
        Card *Dealer3 = new Card(rand()%52);
        Dealer.Add(Dealer3);
        dtotal += Dealer3->getRank();
        cout<<endl<<endl<<"Here is the dealers updated hand"<<endl<<endl<<Dealer;
        cout<<"The dealers new score is " << dtotal << endl<<endl;
      }
      while(dtotal <= 27);
  
      //Conditionals based off of the dealers new cards and score
      if(dtotal > 31){
         cout<<"The house has busted, you win!"<< endl;
         betM += (wager * 2);
         cout<<"You now have " << betM << " you lucky gambler! Nice!";
        return;
      }
      else if(dtotal == 31){
        cout<<"The house has won and achieved a score of 31, better luck next time";
        return;
      }
        
      int pdiff = 31 - ptotal;
      int ddiff = 31 - ptotal;

      if(pdiff > ddiff){
        cout<<"The house was closer to 31, the house wins"<<endl;
         return;
      }
      else
      {
        cout<<"You were closer to 31, you win, well played!"<< endl;
        betM += (wager * 2);
        cout<<"You now have " << betM << " you lucky gambler! Nice!";
        return;
      }
     
}




int main() {
//Setting random time(part of the starter code) 
    srand(time(0));

//Interacting with the player before the game starts and introducing the new rules
    cout<<"Hello new gambler, welcome to the blackjack program"<<endl;
    cout<<"This version of blackjack is quite different than most versions, I will now explain the changes"<<endl;
    cout<<"Jacks = 11, Queens = 12, Kings = 13, and Aces = 1."<<endl;
    cout<<"In this program, you will play against a dealer and try to get your card total to 31 or closer to 31 than the dealer"<< endl;
    cout<<"Both you and the dealer will start with two cards, after receiving your two cards you may test your luck and ask for another card or you may stand with what you have"<<endl;
    cout<<"You will also have $500 that you may bet as you wish"<<endl;
    cout<<"Let the games begin, and may the cards be ever in your favor"<<endl<<endl;

    cout<<"======================================="<<endl;
  //Calls the game function to play the game
    GAME();




      
















  
}