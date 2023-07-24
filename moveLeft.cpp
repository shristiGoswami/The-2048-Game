// Function to perform a left move
void moveLeft(int board[][SIZE], int& score) {
    shiftLeft(board);
    mergeLeft(board, score);
    shiftLeft(board);
}
