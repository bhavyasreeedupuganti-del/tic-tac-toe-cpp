#include <iostream>
#include <limits>
using namespace std;

const int SIZE = 3;

void displayBoard(const char board[SIZE][SIZE]) {
    cout << "\n";
    for (int row = 0; row < SIZE; row++) {
        cout << " ";
        for (int col = 0; col < SIZE; col++) {
            cout << board[row][col];
            if (col < SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (row < SIZE - 1) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(const char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player &&
            board[i][2] == player) return true;

        if (board[0][i] == player && board[1][i] == player &&
            board[2][i] == player) return true;
    }

    if (board[0][0] == player && board[1][1] == player &&
        board[2][2] == player) return true;

    if (board[0][2] == player && board[1][1] == player &&
        board[2][0] == player) return true;

    return false;
}

bool checkDraw(const char board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] != 'X' && board[row][col] != 'O')
                return false;
        }
    }
    return true;
}

void playGame() {
    char board[SIZE][SIZE] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char currentPlayer = 'X';
    int position;
    bool gameOver = false;

    cout << "\n===== TIC TAC TOE =====\n";
    cout << "Player 1: X\nPlayer 2: O\n";
    cout << "Choose a position from 1 to 9.\n";

    while (!gameOver) {
        displayBoard(board);
        cout << "Player " << currentPlayer
             << ", enter your position (1-9): ";

        if (!(cin >> position)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (position < 1 || position > 9) {
            cout << "Please choose a position between 1 and 9.\n";
            continue;
        }

        int row = (position - 1) / SIZE;
        int col = (position - 1) % SIZE;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "That position is already occupied. Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Congratulations! Player " << currentPlayer
                 << " wins!\n";
            gameOver = true;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw! Well played.\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    char replay;

    do {
        playGame();
        cout << "\nWould you like to play again? (Y/N): ";
        cin >> replay;

        if (replay >= 'a' && replay <= 'z')
            replay = replay - ('a' - 'A');

    } while (replay == 'Y');

    cout << "\nThank you for playing Tic Tac Toe!\n";
    return 0;
}
