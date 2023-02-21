#include <stdio.h>

char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};
char blackchess[6] = { 'r', 'n', 'b', 'q', 'k', 'p' };
char whitechess[6] = { 'R', 'N', 'B', 'Q', 'K', 'P' };


void draw_board() {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void move(int a, int b, int c, int d) {
    char tmp;
    tmp = board[a][b];
    board[a][b] = board[c][d];
    board[c][d] = tmp;
}

int main() {
    int a, b, c, d;

    draw_board();
    printf("Please choose the chess position: \n");
    while (1) {
        scanf_s("%d %d", &a, &b, 1);
        if (a >= 0 && a < 8 && b >= 0 && b < 8) break;
        printf("Please enter the correct chess position\n");
    }
    printf("Please choose the end position: \n");
    while (1) {
        scanf_s("%d %d", &c, &d, 1);
        if (c >= 0 && c < 8 && d >= 0 && d < 8) break;
        printf("Please enter the correct end position\n");
    }
    move(a, b, c, d);
    draw_board();
    

    return 0;
}
