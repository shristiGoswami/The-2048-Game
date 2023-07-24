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
