// Function to perform a down move
void moveDown(int board[][SIZE], int& score) {
    shiftDown(board);
    mergeDown(board, score);
    shiftDown(board);
}
