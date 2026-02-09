#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()GRR
#include <limits>    // For input validation

using namespace std;

// Function to generate a random number between 1 and 100
int generateRandomNumber() {
    return rand() % 100 + 1;
}

int main() {

    // Seed the random number generator
    srand(time(0));

    char playAgain;

    cout << "==========================================" << endl;
    cout << "      ?? WELCOME TO NUMBER GUESSING GAME    " << endl;
    cout << "==========================================" << endl;

    do {
        int secretNumber = generateRandomNumber();
        int userGuess;
        int attempts = 0;
        bool guessedCorrectly = false;

        cout << "\nI have selected a number between 1 and 100." << endl;
        cout << "Try to guess it!" << endl;

        // Game loop
        while (!guessedCorrectly) {

            cout << "\nEnter your guess: ";
            cin >> userGuess;

            // Input validation
            if (cin.fail() || userGuess < 1 || userGuess > 100) {
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "?? Invalid input! Please enter a number between 1 and 100." << endl;
                continue;
            }

            attempts++;

            // Check the guess
            if (userGuess > secretNumber) {
                cout << "?? Too High! Try a smaller number." << endl;
            }
            else if (userGuess < secretNumber) {
                cout << "?? Too Low! Try a bigger number." << endl;
            }
            else {
                cout << "\n?? Congratulations!" << endl;
                cout << "You guessed the correct number: " << secretNumber << endl;
                cout << "Total attempts taken: " << attempts << endl;
                guessedCorrectly = true;
            }
        }

        // Ask user to play again
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n?? Thank you for playing. Goodbye!" << endl;

    return 0;
}