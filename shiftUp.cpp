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
