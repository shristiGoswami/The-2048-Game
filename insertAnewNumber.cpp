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
