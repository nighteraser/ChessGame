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
int a, b, c, d;      // a: first y ; b: first x ; c: end y ; d: end x


void draw_board() {
    int i, j;
    printf("\\ 0 1 2 3 4 5 6 7\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", i);
        for (j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool check_blackchess() {
    int i = 0;
    for (; i < 6; i++)
        if (board[a][b] == blackchess[i]) return true;
    return false;
}
bool check_whitechess() {
    int i = 0;
    for (; i < 6; i++)
        if (board[a][b] == whitechess[i]) return true;
    return false;
}
bool check_endpoint() {
    char chess = board[a][b];
    int vx = d - b;
    int vy = c - a;
    if (chess == 'P') {
        if (vx == 0 && vy == -1) return true;
    }
    return false;
}

void move() {
    board[c][d] = board[a][b];
    board[a][b] = ' ';
}

int main() {
    
    draw_board();
    printf("Please choose the chess position: \n");  // "White" go first. choosing the white chess
    while (1) {
        scanf_s("%d %d", &a, &b, 1);
        if (a >= 0 && a < 8 && b >= 0 && b < 8 && check_whitechess()) break;
        printf("Please enter the correct chess position\n");
    }
    printf("Please choose the end position: \n");
    while (1) {
        scanf_s("%d %d", &c, &d, 2);
        if (c >= 0 && c < 8 && d >= 0 && d < 8 && check_endpoint()) break;
        printf("Please enter the correct end position\n");
    }                                       
    move();                  
    draw_board();
    

    return 0;
}
