#include "deck.hpp"

// Deck class constructor; sets up LL
Deck::Deck(int numDecks){
    this->numDecks = numDecks;
    for(int deckNum = 1; deckNum <= numDecks; deckNum++) {
        for(int suit = 1; suit <= suitsPerDeck; suit++) {
            for(int face = 1; face <= facesPerDeck; face++) {
                push(face, suit);
            }
        }
    }
}

card* Deck::assignCard(int face, int suit) {
    card *top = new card; // create a card
    top->face = face;   // assign face value to top card
    top->suit = suit;   // assign suit value to top card
    top->used = false;
    return top;         // returns a pointer to the new card
}

void Deck::push(int face, int suit) {
    if (top == nullptr) { // if no cards have been added to the top of the deck
        top = assignCard(face, suit);
        top->next = NULL;   // this is the last card in the deck (end of list)
    }
    else {
        card *temp = top;   // save previous top card as temp
        top = assignCard(face, suit);
        top->next = temp;   // new top card points to previous top card (temp)
    }
    size++;
}

card* Deck::pop(){
    card *temp;
    if (top == NULL) {
        return NULL;
    }
    else {
        temp = top;   // save current top card as temp
        top = top->next;    // assign new top card
    }
    size--;
    return temp;    // return original top card
}

// draw card from the top of the deck and PRINT its face and suit in a string
string Deck::drawCard(){
    return formatCard(pop());
}

void Deck::display(){
    cout << endl << "Total number of cards: " << size << endl << endl;
    card *position = top;
    int i = 1;
    while(position != NULL) {
        cout << i << "." << " " << formatCard(position) << endl;
        position = position->next;
        i++;
    }
}

// finds and returns card at desired position in the linked list
card* Deck::cardAt(int index){
    card *position = top;
    int i = 1;
    while(i != index) {
        position = position->next;
        i++;
    }
    return position;
}

void Deck::shuffle(){
    Deck temp(numDecks);
    card *position = top;
    while(position != NULL) {
        bool assigned;
        do {
            assigned = false;
            int randIndex = (rand() % size) + 1;
            if (temp.cardAt(randIndex)->used == false) {
                position->face = temp.cardAt(randIndex)->face;
                position->suit = temp.cardAt(randIndex)->suit;
                assigned = true;
                temp.cardAt(randIndex)-> used = true;
            }
        }while(assigned == false);
        position = position->next;
    }
    return;
}

// deconstructor that deletes every node in the LL and sets top pointer to null

Deck::~Deck(){
    card *position = top;
    while(position != nullptr) {
        card *temp = position->next;
        delete position;
        position = temp;
    }
}

string Deck::formatCard(card *aCard) {
    string faceStr;
    string suitSym;
    switch(aCard->face) {
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
    
    switch(aCard->suit) {
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
    string cardString = faceStr + "-" + suitSym;
    return cardString;
}
