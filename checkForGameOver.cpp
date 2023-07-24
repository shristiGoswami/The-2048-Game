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
