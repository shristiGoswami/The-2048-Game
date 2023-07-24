// Function to generate a random number (2 or 4)
int generateRandomNumber() {
    srand(time(0));
    int randomNumber = rand() % 2;
    if (randomNumber == 0) {
        return 2;
    } else {
        return 4;
    }
}
