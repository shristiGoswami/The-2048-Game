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
