void printBoard(int board[][SIZE]) {
    cout << "+---------------------+" << endl;
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
        cout << "+---------------------+" << endl;
    }
}
