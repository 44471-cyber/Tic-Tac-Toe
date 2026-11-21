#include <stdio.h>

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char playerX = 'X', playerO = 'O';
    char currentPlayer = ' ', winner = ' ';

    int r = -1, c = -1;

    // input validation
    while (1) {
        printf("Choose a symbol: ");
        scanf("%c", &currentPlayer);

        if (currentPlayer == 'X' || currentPlayer == 'x') {
            currentPlayer = playerX;
            break;
        } else if (currentPlayer == 'O' || currentPlayer == 'o' || currentPlayer == '0') {
            currentPlayer = playerO;
            break;
        } else {
            printf("Invalid input, try again.\n\n");
            while (getchar() != '\n');
        }
    }

    for (int i = 0; i < 9; i++) {
        // Draws the board
        printf("\n   |   |   \n");
        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
        printf("___|___|___\n");
        printf("   |   |   \n");
        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
        printf("___|___|___\n");
        printf("   |   |   \n");
        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
        printf("   |   |   \n");

        if (winner != ' ') {
            break;
        }

        printf("\nCurrent player is %c\n", currentPlayer);

        while (1) {
            printf("Enter the row and column from 0 - 2: ");

            if (!scanf("%d %d", &r, &c) || r < 0 || r > 2 || c < 0 || c > 2) {
                printf("Invalid input, try again.\n\n");
                while (getchar() != '\n');
            } else if (board[r][c] != ' ') {
                printf("The tile you have chosen is full, try again.\n\n");
                while (getchar() != '\n');
            } else {
                break;
            }
        }

        board[r][c] = currentPlayer;
        currentPlayer = currentPlayer == playerX ? playerO : playerX;

        r = -1;
        c = -1;

        while (getchar() != '\n');

        // checks horizontal victory
        for (int r = 0; r < 3; r++) {
            if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2]) {
                winner = board[r][0];
                break;
            }
        }

        // checks vertical victory
        for (int c = 0; c < 3; c++) {
            if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
                winner = board[0][c];
                break;
            }
        }

        // checks diagonal victory
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
        } else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = board[0][2];
        }
    }

    // reveals the winner, otherwise it's a tie
    if (winner != ' ') {
        printf("\nPlayer %c is the winner!", winner);
    } else {
        printf("\nTie!");
    }

    return 0;
}
