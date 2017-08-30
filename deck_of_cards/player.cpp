#include "player.hpp"
#include "deck.hpp"

// 2. Player class function implementations
Player::Player(){
    firstName = "";
    lastName = "";
    score = 0;
    cash = 0;
}

Player::Player(string firstName, string lastName, int score, double cash) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->score = score;
    this->cash = cash;
    handCount = 0;
}

void Player::addCard(card aCard){
    hand[handCount] = aCard;
    calculateScore(hand[handCount]);
    handCount++;
}

void Player::resetHand() {
    handCount = 0;
    score = 0;
}

void Player::calculateScore(card lastCard){
    switch (lastCard.face) {
        case 1:
            if (score < 11) {
                score += 11;
            }
            else {
                score += 1;
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            score += lastCard.face;
            break;
        case 10:
        case 11:
        case 12:
        case 13:
            score += 10;
            break;
    }
}

void Player::changeDisplay(int suit, int face, int i) {
    string faceStr;
    string suitSym;
    switch(face) {
        case 1:
            faceStr = "A";
            break;
        case 2:
            faceStr = "2";
            break;
        case 3:
            faceStr = "3";
            break;
        case 4:
            faceStr = "4";
            break;
        case 5:
            faceStr = "5";
            break;
        case 6:
            faceStr = "6";
            break;
        case 7:
            faceStr = "7";
            break;
        case 8:
            faceStr = "8";
            break;
        case 9:
            faceStr = "9";
            break;
        case 10:
            faceStr = "10";
            break;
        case 11:
            faceStr = "J";
            break;
        case 12:
            faceStr = "Q";
            break;
        case 13:
            faceStr = "K";
            break;
    }
    
    switch(suit) {
        case 1:
            suitSym = "\u2660";
            break;
        case 2:
            suitSym = "\u2666";
            break;
        case 3:
            suitSym = "\u2663";
            break;
        case 4:
            suitSym = "\u2665";
            break;
    }
    cout << i + 1 << ". " << faceStr << "-" << suitSym << "   ";
}

void Player::displayInfo(){
    cout << "You are: " << firstName << " " << lastName << endl;
    cout << "You have: $" << cash << endl;
}

double Player::getCash(){
    return cash;
}

string Player::getFirstName(){
    return firstName;
}

string Player::getLastName(){
    return lastName;
}

int Player::getScore(){
    return score;
}

void Player::setScore(double score) {
    this->score = score;
}

void Player::setCash(double cash) {
    this->cash = cash;
}

void Player::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Player::setLastName(string lastName) {
    this->lastName = lastName;
}

void Player::showHand(){
    cout << endl << "Hand: ";
    for (int i = 0; i < handCount; i++) {
        changeDisplay(hand[i].suit, hand[i].face, i);
    }
    cout << endl << "Score: " << getScore() << endl << endl;
}
