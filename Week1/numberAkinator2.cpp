#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Global variables
int theNumber;    // The number to guess
int inBetween1;   // Lower bound of guess range
int inBetween2;   // Upper bound of guess range

// Function declarations
void initGuess();
void guess();
void failGuess();
void check(char response);

// Initialize the guessing prompt
void initGuess() {
    // Generate initial random range
    inBetween1 = rand() % 99;          // 0 to 98
    inBetween2 = inBetween1 + rand() % (101 - inBetween1);  // ensure inBetween2 >= inBetween1 and <= 100

    cout << "Is the number between " << inBetween1 << " and " << inBetween2 << "? (Y/N): ";

    char response;
    cin >> response;
    check(response);
}

// The guessing prompt
void guess() {
    // Generate new random range
    inBetween1 = rand() % 99;
    inBetween2 = inBetween1 + rand() % (101 - inBetween1);

    cout << "Is the number between " << inBetween1 << " and " << inBetween2 << "? (Y/N): ";

    char response;
    cin >> response;
    check(response);
}

// Called when user fails to guess correctly
void failGuess() {
    cout << "The number is not between " << inBetween1 << " and " << inBetween2 << endl;
    guess();
}

// The guessing logic
void check(char response) {
    // Normalize input to uppercase
    response = toupper(response);

    bool numberInRange = (theNumber >= inBetween1 && theNumber <= inBetween2);

    if (response == 'Y') {
        if (numberInRange) {
            cout << "Great! The number is indeed between " << inBetween1 << " and " << inBetween2 << "." << endl;
            cout << "You guessed correctly!" << endl;
            //ALLOW USER TO GUESS WHICH NUMBER IT PRECISELY IS
        } else {
            cout << "Oops! The number is NOT between " << inBetween1 << " and " << inBetween2 << "." << endl;
            failGuess();
        }
    } else if (response == 'N') {
        if (!numberInRange) {
            cout << "Good! The number is NOT between " << inBetween1 << " and " << inBetween2 << "." << endl;
            guess();
        } else {
            cout << "Oops! The number IS between " << inBetween1 << " and " << inBetween2 << "." << endl;
            failGuess();
        }
    } else {
        cout << "Invalid input. Please enter Y or N." << endl;
        // Repeat the same prompt
        guess();
    }
}

int main() {
    srand(time(0));  // Seed random number generator

    theNumber = rand() % 101;  // Random number between 0 and 100

    cout << "Number guessing game - CPP Practice Week 1" << endl;
    cout << "Try to guess the range that contains the number between 0 and 100." << endl;

    initGuess();

    return 0;
}
