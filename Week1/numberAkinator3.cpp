#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Global variables
int theNumber;    // The number to guess
int inBetween1;   // Lower bound of guess range
int inBetween2;   // Upper bound of guess range
int score = 10;

// Function declarations
void initGuess();
void guess();
void failGuess();
void check(char response);
void checkScore();  // Declare score check function

// Initialize the guessing prompt
void initGuess() {
    // Generate initial random range
    inBetween1 = rand() % 99;          // 0 to 98
    inBetween2 = inBetween1 + rand() % (101 - inBetween1);  // ensure inBetween2 >= inBetween1 and <= 100

    cout << "Is the number between " << inBetween1 << " and " << inBetween2 << "? (Y/N): " << endl;

    char response;
    cin >> response;
    check(response);
}

// The guessing prompt
void guess() {
    // Generate new random range
    inBetween1 = rand() % 99;
    inBetween2 = inBetween1 + rand() % (101 - inBetween1);

    cout << "Is the number between " << inBetween1 << " and " << inBetween2 << "? (Y/N): " << endl;

    char response;
    cin >> response;
    check(response);
}

// Called when user fails to guess correctly
void failGuess() {
    cout << "Too low. Try again." << endl;
    score = score - 1;
    cout << "Score: " << score << endl;
    checkScore();  // Check score after decrement
    guess();
}

//score check
void checkScore() {
    if (score < 0) {
        cout << "\nYour score dropped below 0. Game over!" << endl;
        exit(0);
    }
}

//guessing logic
void check(char response) {
    // Normalize input to uppercase
    response = toupper(response);

    bool numberInRange = (theNumber >= inBetween1 && theNumber <= inBetween2);

    if (response == 'Y') {
        if (numberInRange) {
            cout << "Great! The number is indeed between " << inBetween1 << " and " << inBetween2 << "." << endl;
            cout << "You guessed correctly!" << endl;
            score = score + 10;
            cout << "Score: " << score << endl;
            checkScore();  // Check score after increment

            // ALLOW USER TO KEEP GUESSING THE EXACT NUMBER
            int preciseGuess;
            do {
                cout << "Now, guess the exact number: " << endl;
                cin >> preciseGuess;

                if (preciseGuess == theNumber) {
                    cout << "Congratulations! You guessed the exact number!" << endl;
                    cout << "Score: " << score << endl;
                    exit(0);  // End the program on correct guess
                } else if (preciseGuess < theNumber) {
                    cout << "Too low. Try again." << endl;
                    score = score - 1;
                    cout << "Score: " << score << endl;
                    checkScore();
                } else {
                    cout << "Too high. Try again." << endl;
                    score = score - 1;
                    cout << "Score: " << score << endl;
                    checkScore();
                }
            } while (true);

        } else {
            cout << "Oops! The number is NOT between " << inBetween1 << " and " << inBetween2 << "." << endl;
            failGuess();
        }
    } else if (response == 'N') {
        if (!numberInRange) {
            cout << "Good! The number is NOT between " << inBetween1 << " and " << inBetween2 << "." << endl;
            score = score + 1;
            cout << "Score: " << score << endl;
            checkScore();
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

//main
int main() {
    srand(time(0));  // Seed random number generator

    theNumber = rand() % 101;  // Random number between 0 and 100

    cout << "Number guessing game - CPP Practice Week 1" << endl;
    cout << "Try to guess the range that contains the number between 0 and 100." << endl;

    initGuess();

    return 0;
}
