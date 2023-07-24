#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 4;

// Function to print the game board
void printBoard(int board[][SIZE]) {
    cout << "+---------------------------+" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "| ";
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                cout << "    ";
            } else {
                cout << setw(4) << board[i][j];
            }
            cout << " | ";
        }
        cout << endl;
        cout << "+---------------------------+" << endl;
    }
}


// Function to initialize the game board with zeros
void initializeBoard(int board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to generate a random number (2 or 4)
int generateRandomNumber() {
    srand(time(0));
    int randomNumber = rand() % 2;
    if (randomNumber == 0) {
        return 2;
    } else {
        return 4;
    }
}

// Function to insert a new number (2 or 4) at a random empty position on the board
void insertNewNumber(int board[][SIZE]) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                count++;
            }
        }
    }

    if (count == 0) {
        return;
    }

    int randomPosition = rand() % count + 1;
    int position = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                position++;
                if (position == randomPosition) {
                    board[i][j] = generateRandomNumber();
                    return;
                }
            }
        }
    }
}

// Function to check if the game is over (no more moves possible)
bool isGameOver(int board[][SIZE]) {
    // Check for any empty cell
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }

    // Check for adjacent cells with the same value
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((j + 1 < SIZE) && (board[i][j] == board[i][j + 1])) {
                return false;
            }
            if ((i + 1 < SIZE) && (board[i][j] == board[i + 1][j])) {
                return false;
            }
        }
    }

    return true;
}

// Function to shift the tiles left
void shiftLeft(int board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] == 0) {
                for (int k = j + 1; k < SIZE; k++) {
                    if (board[i][k] != 0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
}

// Function to merge the tiles left
void mergeLeft(int board[][SIZE], int& score) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] == board[i][j + 1]) {
                board[i][j] += board[i][j + 1];
                score += board[i][j];
                board[i][j + 1] = 0;
            }
        }
    }
}

// Function to perform a left move
void moveLeft(int board[][SIZE], int& score) {
    shiftLeft(board);
    mergeLeft(board, score);
    shiftLeft(board);
}

// Function to shift the tiles right
void shiftRight(int board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE - 1; j > 0; j--) {
            if (board[i][j] == 0) {
                for (int k = j - 1; k >= 0; k--) {
                    if (board[i][k] != 0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
}

// Function to merge the tiles right
void mergeRight(int board[][SIZE], int& score) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE - 1; j > 0; j--) {
            if (board[i][j] == board[i][j - 1]) {
                board[i][j] += board[i][j - 1];
                score += board[i][j];
                board[i][j - 1] = 0;
            }
        }
    }
}

// Function to perform a right move
void moveRight(int board[][SIZE], int& score) {
    shiftRight(board);
    mergeRight(board, score);
    shiftRight(board);
}

// Function to shift the tiles up
void shiftUp(int board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[j][i] == 0) {
                for (int k = j + 1; k < SIZE; k++) {
                    if (board[k][i] != 0) {
                        board[j][i] = board[k][i];
                        board[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }
}

// Function to merge the tiles up
void mergeUp(int board[][SIZE], int& score) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[j][i] == board[j + 1][i]) {
                board[j][i] += board[j + 1][i];
                score += board[j][i];
                board[j + 1][i] = 0;
            }
        }
    }
}

// Function to perform an up move
void moveUp(int board[][SIZE], int& score) {
    shiftUp(board);
    mergeUp(board, score);
    shiftUp(board);
}

// Function to shift the tiles down
void shiftDown(int board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE - 1; j > 0; j--) {
            if (board[j][i] == 0) {
                for (int k = j - 1; k >= 0; k--) {
                    if (board[k][i] != 0) {
                        board[j][i] = board[k][i];
                        board[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }
}

// Function to merge the tiles down
void mergeDown(int board[][SIZE], int& score) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE - 1; j > 0; j--) {
            if (board[j][i] == board[j - 1][i]) {
                board[j][i] += board[j - 1][i];
                score += board[j][i];
                board[j - 1][i] = 0;
            }
        }
    }
}

// Function to perform a down move
void moveDown(int board[][SIZE], int& score) {
    shiftDown(board);
    mergeDown(board, score);
    shiftDown(board);
}

int main() {
    int board[SIZE][SIZE];
    int score = 0;
    char move;

    initializeBoard(board);
    insertNewNumber(board);
    insertNewNumber(board);

    cout << "Welcome to 2048!" << endl;
    cout << "Use the following keys to make a move: " << endl;
    cout << "W or w: Up" << endl;
    cout << "A or a: Left" << endl;
    cout << "S or s: Down" << endl;
    cout << "D or d: Right" << endl;
    cout << "Q or q: Quit" << endl;

    printBoard(board);

    while (true) {
        cout << "Score: " << score << endl;
        cout << "Enter your move: ";
        cin >> move;

        switch (move) {
            case 'W':
            case 'w':
                moveUp(board, score);
                break;
            case 'A':
            case 'a':
                moveLeft(board, score);
                break;
            case 'S':
            case 's':
                moveDown(board, score);
                break;
            case 'D':
            case 'd':
                moveRight(board, score);
                break;
            case 'Q':
            case 'q':
                cout << "Game over! Your final score is: " << score << endl;
                return 0;
            default:
                cout << "Invalid move! Please try again." << endl;
                continue;
        }

        if (isGameOver(board)) {
            cout << "Game over! Your final score is: " << score << endl;
            return 0;
        }

        insertNewNumber(board);
        printBoard(board);
    }

    return 0;
}
