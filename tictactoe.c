#include <stdio.h>

char board[3][3];
char currentPlayer;

void initBoard() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard() 
{
    printf("\n    1   2   3  \n"); 
    printf("  -------------\n");
    printf("1| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("  -------------\n");
    printf("2| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("  -------------\n");
    printf("3| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
    printf("  -------------\n\n");    
}

int checkWin() {
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return 1;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return 1;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return 1;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return 1;
    return 0;
}

int isDraw() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int main() 
{
    while(1)
    {
        int row, col;
        currentPlayer = 'X';
        initBoard();

        while (1) 
        {   

            printf("\n========== TIC TAC TOE ==========\n");
            
            printBoard();
            printf("Player %c, enter move (row col: 1-3 1-3): ", currentPlayer);
            if (scanf("%d %d", &row, &col) != 2) 
            {
                printf("Invalid input. Please enter two numbers.\n");
                while (getchar() != '\n'); 
                continue;
            }

            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') 
            {
                printf("Invalid move! Try again.\n");
                while(getchar() != '\n');
                continue;
            }

            board[row - 1][col - 1] = currentPlayer;

            if (checkWin()) 
            {
                printBoard();
                printf("Player %c wins!\n", currentPlayer);
                break;
            }

            if (isDraw()) 
            {
                printBoard();
                printf("It's a draw!\n");
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        char choice;
        while(getchar() != '\n');
        printf("Enter C/c to play again and Q/q to quit the game: ");
        if(scanf("%c", &choice) == 1)
        {
            if(choice == 'Q' || choice == 'q')
            {
                printf("Selected Q/q Exiting the game.\n");
                printf("Thank you for playing. Goodbye.\n");
                return 0;
            } else if(choice == 'C' || choice == 'c')
            {
                printf("\nRestarting game.\n");
                continue;
            }
        }
    }
}
