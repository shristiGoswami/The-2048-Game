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
