#ifndef player_hpp
#define player_hpp

//1. library inclusions
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "deck.hpp"
using namespace std;

//2. constants
const int cardsPerDeck = 52;
const int facesPerDeck = 13;
const int suitsPerDeck = 4;
const int maxHand = 22;

//5. Player class functions
class Player{
public:
    // constructors
    Player();
    Player(string, string, int, double);
    
    // mutators
    void resetHand();
    void setScore(double);
    void setCash(double);
    void setFirstName(string);
    void setLastName(string);
    void addCard(card);
    void calculateScore(card);
    void changeDisplay(int, int, int);
    
    // accessors
    string getFirstName();
    string getLastName();
    void displayInfo();
    void showHand();
    double getCash();
    int getScore();
    
private:
    string firstName;
    string lastName;
    int cash;
    int score;
    card hand[maxHand];
    int handCount;
};

#endif /*player_hpp*/
