/****************************************************************************
 * Project number: Final Project
 *
 * Programmer: Jasmine Norman
 *
 * Due Date: 4/17/17
 *
 * EGRE 246 Spring 2017
 *
 * Pledge: I have neither given nor received unauthorized aid on the program.
 *
 * Description:
 *
 * Input:
 *
 * Output:
 *
 ***************************************************************************/

#include <iostream>
#include <fstream>
#include "deck.hpp"
#include "player.hpp"


using namespace std;

double bet;
double minBet = 10;
int randSeed;
int numDecks = 1;
string tempFH;
string firstName = "";
string lastName = "";
string filename = "";
ofstream output;
ifstream input;
enum type_state {MAIN, SETTINGS, GAME, SAVE, LOAD, QUIT} state;
enum type_state mainMenu();
enum type_state settings();
enum type_state game();
enum type_state save();
enum type_state load();
bool goodinput(int choice, int min, int max);
Player player("Player", "Player", 0, 100);
Player dealer("Dealer", "", 0, 100);
void gameHeader() {
    cout << "Money on the table: $" << bet*2 << endl;
    cout << endl;
    cout << "-- PLAYER --" << endl;
    player.showHand();
    cout << "-- DEALER --" << endl;
    dealer.showHand();
}

void Splash(){
    cout << endl;
    cout << "٩⩾⏠⩽۶      Black Jack      ٩⩾⏠⩽۶"<< endl;
    cout << "٩⩾⏠⩽۶      Black Jack      ٩⩾⏠⩽۶" << endl;
    cout << "٩⩾⏠⩽۶      Black Jack      ٩⩾⏠⩽۶" << endl;
    cout << "٩⩾⏠⩽۶      Black Jack      ٩⩾⏠⩽۶" << endl;
    cout << "٩⩾⏠⩽۶      Black Jack      ٩⩾⏠⩽۶"<< endl;
    cout << endl;
}

void dealerWins() {
    dealer.setCash(dealer.getCash() + bet*2);
}
void playerWins() {
    player.setCash(player.getCash() + bet*2);
}

int main(){
    state = MAIN;
    
    while (true) {
        switch(state) {
            case (MAIN): {
                state = mainMenu();
                break;
            }
            case (SETTINGS): {
                state = settings();
                break;
            }
            case (GAME): {
                state = game();
                break;
            }
            case (SAVE): {
                state = save();
                break;
            }
            case (LOAD): {
                state = load();
                break;
            }
            case (QUIT): {
                exit(0);
            }
        }
    }
}

enum type_state mainMenu(){
    while (true) {
        int choice;
        Splash();
        cout << endl << "Main Menu" << endl << "1. Play Game" << endl << "2. Settings" << endl << "3. Load Game" << endl << "4. Exit" << endl << "Choice? ";
        
        fflush(stdin);
        cin >> choice;
        cout << endl;
        if (goodinput(choice, 1, 4)) {
            switch (choice) {
                case (1): {
                    return GAME;
                    break;
                }
                case (2): {
                    return SETTINGS;
                    break;
                }
                case (3): {
                    return LOAD;
                    break;
                }
                case (4): {
                    return QUIT;
                    break;
                }
                default: {
                    break;
                }
            }
        }
        }
        }
        
        enum type_state settings(){
            while (true) {
                int choice;
                Splash();
                cout << endl << "Settings Menu" << endl << endl << "Player Settings" << endl << "1. First Name: " << player.getFirstName() << endl << "2. Last Name: " << player.getLastName() << endl << "3. Starting Money: $" << player.getCash() << endl << endl;
                cout << "Game Settings" << endl << "4. Minimum bet: $" << minBet << endl << "5. Number of decks: " << numDecks << endl << "6. Random number: " << randSeed << endl << "7. Main Menu" << endl << "Choice? ";
                fflush(stdin);
                cin >> choice;
                if (goodinput(choice, 1, 7)) {
                    switch (choice) {
                        case (1): {
                            cout << "Enter first name: ";
                            cin >> firstName;
                            player.setFirstName(firstName);
                            cout << endl;
                            break;
                        }
                        case (2): {
                            cout << "Enter last name: ";
                            cin >> lastName;
                            player.setLastName(lastName);
                            cout << endl;
                            break;
                        }
                        case (3): {
                            cout << "Enter starting cash amount: $";
                            double cash;
                            cin >> cash;
                            player.setCash(cash);
                            dealer.setCash(cash);
                            break;
                        }
                        case (4): {
                            cout << "Set minimum bet to: $";
                            cin >> minBet;
                            break;
                        }
                        case (5): {
                            cout << "Set number of decks to: ";
                            cin >> numDecks;
                            break;
                        }
                        case (6): {
                            cout << "Number for random number generator: ";
                            cin >> randSeed;
                            break;
                        }
                        case (7): {
                            return MAIN;
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                }
            }
        }
        
        enum type_state game(){
            Deck deck(numDecks);
            deck.shuffle();
            player.addCard(*deck.pop());
            dealer.addCard(*deck.pop());
            gameHeader();
            string winner = "";
            while (true) {
                int Choice;
                Splash();
                player.displayInfo();
                cout <<  endl << "1. Place minimum bet" << endl << "2. Place custom bet" << endl << "3. Hit" << endl << "4. Hold" << endl << "5. Go to Options Menu" << endl << "Choice? ";
                
                fflush(stdin);
                cin >> Choice;
                if (goodinput(Choice, 1, 5)) {
                    switch (Choice) {
                        case (1): {
                            bet = minBet;
                            cout << "You bet: $" << bet << endl << endl;
                            player.setCash(player.getCash() - bet);
                            dealer.setCash(dealer.getCash() - bet);
                            break;
                        }
                        case (2): {
                            cout << endl << "Bet: $";
                            cin >> bet;
                            cout << endl;
                            player.setCash(player.getCash() - bet);
                            dealer.setCash(dealer.getCash() - bet);
                            cout << endl;
                            gameHeader();
                            break;
                        }
                        case (3): {
                            player.addCard(*deck.pop());
                            gameHeader();
                            if (player.getScore() < 21) {
                                break;
                            }
                        }
                        case (4): {
                            while (dealer.getScore() < 18 && player.getScore() <= 21) {
                                dealer.addCard(*deck.pop());
                            };
                            if (dealer.getScore() <= 21 && player.getScore() <= 21) {
                                if (dealer.getScore() == player.getScore()){
                                    cout << "Tie-breaker" << endl;
                                    do {
                                        player.resetHand();
                                        dealer.resetHand();
                                        player.addCard(*deck.pop());
                                        dealer.addCard(*deck.pop());
                                    } while (player.getScore() == dealer.getScore());
                                }
                                
                                if (dealer.getScore() > player.getScore() ) {
                                    winner = dealer.getFirstName();
                                    dealerWins();
                                }
                                else if (player.getScore() > dealer.getScore() ) {
                                    winner = player.getFirstName() + " " + player.getLastName();
                                    playerWins();
                                }
                            }
                            else if (dealer.getScore() <= 21 && player.getScore() > 21) {
                                winner = dealer.getFirstName();
                                dealerWins();
                            }
                            else if (player.getScore() <= 21 && dealer.getScore() > 21 ){
                                winner = player.getFirstName() + " " + player.getLastName();
                                playerWins();
                            }
                            gameHeader();
                            cout << "Winner: " << winner << endl;
                        }
                        case (5): {
                            while (true) {
                                Splash();
                                player.displayInfo();
                                int choice;
                                cout << endl << "Options Menu" << endl << "1. Play Again" << endl << "2. Save" << endl << "3. Main Menu" << endl << "Choice? ";
                                fflush(stdin);
                                cin >> choice;
                                if (goodinput(choice, 1, 3)) {
                                    switch (choice) {
                                        case (1): {
                                            player.resetHand();
                                            dealer.resetHand();
                                            return GAME;
                                            break;
                                        }
                                        case (2): {
                                            return SAVE;
                                            break;
                                        }
                                        case (3): {
                                            return MAIN;
                                            break;
                                        }
                                        default: {
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        default: {
                            break;
                        }
                    }
                }
                
            }
            
        }
        
        enum type_state save(){
            while (true) {
                Splash();
                int choice;
                cout << endl << "Save Game Menu" << endl << "1. File Name: " << filename << endl << "2. Save" << endl << "3. Game Menu" << endl << "Choice? ";
                fflush(stdin);
                cin >> choice;
                if (goodinput(choice, 1, 3)) {
                    switch (choice) {
                        case (1): {
                            cout << "Enter file name: ";
                            cin >> tempFH;
                            filename = tempFH + ".jak";
                            cout << endl;
                            break;
                        }
                        case (2): {
                            if (filename.length() == 0 || firstName.length() == 0 || lastName.length() == 0) {
                                cout << "Error: file name, first name and last name required" << endl;
                            }
                            else {
                                output.open(filename);
                                output << firstName << endl << lastName;
                                output.close();
                            }
                            break;
                        }
                        case (3): {
                            player.resetHand();
                            dealer.resetHand();
                            return GAME;
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                }
            }
        }
        
        enum type_state load(){
            while (true) {
                Splash();
                int choice;
                cout << endl << "Load Game Menu" << endl << "1. File Name: " << filename << endl << "2. Load" << endl << "3. Main Menu" << endl << "Choice? ";
                fflush(stdin);
                cin >> choice;
                if (goodinput(choice, 1, 3)) {
                    switch (choice) {
                        case (1): {
                            cout << "Enter file name to load: ";
                            cin >> filename;
                            cout << endl;
                            break;
                        }
                        case (2): {
                            if (filename.length() == 0) {
                                cout << "Error: file name required" << endl;
                            }
                            else {
                                input.open(filename);
                                input >> firstName;
                                input >> lastName;
                                input.close();
                            }
                            break;
                        }
                        case (3): {
                            return MAIN;
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                }
            }
        }
        
        bool goodinput(int choice, int min, int max) {
            if(!cin.good() || (choice < min || choice > max)) {
                cout << "Error: Invalid Choice" << endl;
                cin.clear();
                return false;
            }
            return true;
        }
    
