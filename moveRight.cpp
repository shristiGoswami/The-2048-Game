// Function to perform a right move
void moveRight(int board[][SIZE], int& score) {
    shiftRight(board);
    mergeRight(board, score);
    shiftRight(board);
}
