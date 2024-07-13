#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

// Function to state how much money the player has
// Parameter money: reference the money variable (wallet)
void checkWallet(int money) {
    cout << "You now have " << money << " dollars. \n"; 
}

// Function which prints the value of the card.
void printCard(int card) {
    switch (card) {
        case 11:
            cout << "Jack \n";
            break;
        case 12:
            cout << "Queen \n";
            break;
        case 13:
            cout << "King \n";
            break;
        case 14:
            cout << "Ace \n";
            break;
        default:
            cout << card << " \n";
    }
}

// Function which generates a number between
// and including 2 to 14
int randomCard() {
    int lb = 2, ub = 14;
    return rand() % (ub - lb + 1) + lb;
}

// Obtain the player's bet.
int getBet() {
    int betvalue = 0;
    cout << " \n" << "What is your bet? \n";
    cin >> betvalue;
    return betvalue;
}

int main() {
    // True as long as the game is running
    bool running = true;

    // Intro text
    cout << "ACEY DUCEY CARD GAME \n" 
    << "ORIGINALLY WRITTEN BY BILL PALMBY IN BASIC IN 1978 \n" 
    << "TRANSLATED INTO C++ BY MEGAT MOHAMAD MIKHAIL \n" 
    << "IN A DAZE ACROSS 3 DAYS DURING SUMMER BREAK IN 2024 \n"
    << "\n \n \n";

    // Explanation of game's rules
    cout << "Acey ducey is played in the following manner: \n" 
    << "The dealer (computer) deals two cards face up. \n" 
    << "You have an option to bet or not bet depending \n"
    << "on whether or not you feel the third card will have \n" 
    << "a value between the first two. \n \n" 
    << "If you do not want to bet, input an \"O\" \n \n";

    // Initialise variables
    int bet = 0; // Betting amount
    int wallet = 100; // Initial money
    int card1 = 0; // Value of first card
    int card2 = 0; // Value of second card
    int card3 = 0; // Value of third card

    // Initial statement of player's finances
    checkWallet(wallet);

    // Game repeats as long as running is true
    while(running) {

        // Use current time as seed for random number generator
        srand(time(0));

        // Deal the first two cards.
        cout << " \n" << "Here are your next two cards: \n";
        card1 = randomCard(); 
        card2 = randomCard(); 
        printCard(card1);
        printCard(card2);

        // Obtain the player's bet.
        bet = getBet();

        if (bet == 0) {
            cout << "Chicken!!! \n"; 
        } 

        // Handle case where player attempts to bet more than the money that they have
        if (bet > wallet) {
            do {
                cout << "Sorry, my friend, but you bet too much! \n"
                << "You have only " << wallet << " dollars to bet. \n";
                bet = getBet();
            } 
            while (bet > wallet);
        } 

        // Deal the third card.
        cout << " \n" << "Here is your final card: \n";
        card3 = randomCard();
        printCard(card3);
        cout << " \n";

        // Check if the player has won or lost.
        if ((card3 > card1 && card3 < card2 || card3 > card2 && card3 < card1) && bet != 0) {
            cout << "You win!!! Congratulations :) \n";
            wallet += bet;
        } else if (bet != 0) {
            cout << "Sorry, you lose :( \n";
            wallet -= bet;
        }

        checkWallet(wallet);

        // Ending sequence
        if (wallet > 0) {
            cout << "Would you like to try again? (y/n): \n";
            char answer;
            cin >> answer;
            cin.ignore(256, '\n');
            running = (answer == 'y');
        } else {
            cout << "Sorry pal! You're out of cash. \n";
            running = false;
        }
    }

    cout << "Okay, hope you had fun! \n";
    return 0;
}
