#include <iostream>
using namespace std;

// Global game board
char board[3][3];

// Function to initialize the board
void initializeBoard() {
    char value = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = value++;
        }
    }
}

// Function to display the board
void displayBoard() {
    cout << "\nCurrent Game Board:\n\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---|---|---\n";
    }
    cout << endl;
}

// Function to place player's mark
bool placeMark(int choice, char mark) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = mark;
        return true;
    }
    return false;
}

// Function to check win
bool checkWin(char mark) {

    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
        return true;
    }

    return false;
}

// Function to check draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {

    char currentPlayer = 'X';
    int choice;
    char playAgain;

    cout << "=====================================\n";
    cout << "        TIC TAC TOE GAME (C++)        \n";
    cout << "=====================================\n";

    do {
        initializeBoard();
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();

            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> choice;

            if (choice < 1 || choice > 9) {
                cout << "Invalid choice! Please choose between 1 and 9.\n";
                continue;
            }

            if (!placeMark(choice, currentPlayer)) {
                cout << "This position is already taken. Try again.\n";
                continue;
            }

            // Check win
            if (checkWin(currentPlayer)) {
                displayBoard();
                cout << "?? Player " << currentPlayer << " wins the game!\n";
                gameOver = true;
            }
            // Check draw
            else if (checkDraw()) {
                displayBoard();
                cout << "?? The game is a draw!\n";
                gameOver = true;
            }
            else {
                // Switch player
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThank you for playing Tic Tac Toe!\n";
    return 0;
}