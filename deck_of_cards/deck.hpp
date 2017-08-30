#ifndef deck_hpp
#define deck_hpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct card {
    int face;
    int suit;
    bool used;
    card *next;
};

class Deck {
public:
    Deck(int numDecks);
    ~Deck();
    string drawCard();
    void shuffle();
    void display();
    card *pop();
    
private:
    const int cardsPerDeck = 52;
    const int facesPerDeck = 13;
    const int suitsPerDeck = 4;
    
    int numDecks;
    string formatCard(card* aCard);
    card* assignCard(int face, int suit);
    card *top = nullptr;
    int size = 0;	// initialize size of deck
    void push(int face, int suit);	// add to top
    card* cardAt(int index);
};

#endif /* deck_hpp */
