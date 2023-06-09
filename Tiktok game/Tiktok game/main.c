#include <stdio.h>

char board[3][3];

void initializeBoard() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    int i,j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

int checkWin() {
    int i;
    for (i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

void playGame() {
    int row, col, player = 1, moves = 0;
    char mark;
    initializeBoard();
    
    do {
        displayBoard();
        
        // Determine the current player's mark ('X' or 'O')
        mark = (player == 1) ? 'X' : 'O';
        
        // Get the player's move
        printf("Player %d, enter your move (row[1-3] column[1-3]): ", player);
        scanf("%d %d", &row, &col);
        
        // Check if the move is valid and update the board
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = mark;
            moves++;
            if (checkWin()) {
                displayBoard();
                printf("Player %d wins!\n", player);
                return;
            }
            if (moves == 9) {
                displayBoard();
                printf("It's a draw!\n");
                return;
            }
            player = (player == 1) ? 2 : 1;
        } else {
            printf("Invalid move! Try again.\n");
        }
    } while (1);
}

int main() {
    printf("Welcome to the TikTok Game!\n");
    printf("Player 1: X | Player 2: O\n");
    printf("----------------------------\n");
    
    playGame();
    
    return 0;
}

