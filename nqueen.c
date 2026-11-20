
#include <stdio.h>

#define MAX 10

int board[MAX][MAX];
int n;

int isSafe(int row, int col) {
    int i, j;

    // Check same column
    for (i = 0; i < row; i++) {
        if (board[i][col])
            return 0;
    }

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0;
    }

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++) {
        if (board[i][j])
            return 0;
    }

    return 1;
}

int solveNQueen(int row) {

    if (row == n)
        return 1;

    int col;

    for (col = 0; col < n; col++) {

        if (isSafe(row, col)) {

            board[row][col] = 1;

            if (solveNQueen(row + 1))
                return 1;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int i, j;

    printf("Enter number of queens (1-10): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of queens.\n");
        return 1;
    }

    if (solveNQueen(0)) {

        printf("\nSolution:\n");

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

    } else {
        printf("No solution exists.\n");
    }

    printf("\nName: Shourya Singh\n");

    return 0;
}
