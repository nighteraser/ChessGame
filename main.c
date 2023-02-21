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
bool check_blackchess(int a, int b) {
    int i = 0;
    for (; i < 6; i++)
        if (board[a][b] == blackchess[i]) return true;
    return false;
}
bool check_whitechess(int a, int b) {
    int i = 0;
    for (; i < 6; i++)
        if (board[a][b] == whitechess[i]) return true;
    return false;
}
void move() {
    board[c][d] = board[a][b];
    board[a][b] = ' ';
}
bool check_endpoint() {
    char chess = board[a][b];
    int vx = d - b;
    int vy = c - a;
    if (chess == 'P') {
        if (vx == 0 && vy == -1 && board[c][d] == ' ') return true;
        if (vx == 1 && vy == -1 && check_blackchess(c, d)) return true;
        if (vx == -1 && vy == -1 && check_blackchess(c, d)) return true;
        return false;
    }
    if (chess == 'K') {
        int dxy[8][2] = { 1, 1, 0, 1, -1, 1, 1, 0 , -1, 0, 1, -1, 0, -1, -1, -1 };
        int i = 0;
        for (; i < 8; i++) {
            if (vx == dxy[i][0] && vy == dxy[i][1]) return true;
        }
        return false;
    }
    if (chess == 'N') {
        int dxy[8][2] = { 2, 1, 2, -1, -2, 1, -2, -1, 1, 2, -1, 2, 1, -2, -1, -2 };
        int i = 0;
        for (; i < 8; i++) {
            if (vx == dxy[i][0] && vy == dxy[i][1]) return true;
        }
        return false;
    }
    if (chess == 'R') {
        if (vx != 0 && vy != 0 ) return false;
        if (vx == 0) {
            int i = a + 1;
            while (i < c) {
                if (board[i++][b] != ' ') return false;
            }
        }
        else {
            int i = b + 1;
            while (i < d) {
                if (board[a][i++] != ' ') return false;
            }
        }
        return true;
    }
    if (chess == 'B') {
        if (vx != vy) return false;
        int dxy[4][2] = { 1, 1, 1, -1, -1, 1, -1, -1 }, i = 0;
        for (; i < 4; i++) {
            if (vy / 2 == dxy[i][0] && vx / 2 == dxy[i][1]) {
                // To be continue;
            }
        }
        return true;
    }
    return false;
}



int main() {

    draw_board();
    printf("Please choose the chess position: \n");  // "White" go first. choosing the white chess
    while (1) {
        scanf_s("%d %d", &a, &b, 1);
        if (a >= 0 && a < 8 && b >= 0 && b < 8 && check_whitechess(a, b)) break;
        printf("Please enter the correct chess position\n");
    }
    printf("Please choose the end position: \n");
    while (1) {
        scanf_s("%d %d", &c, &d, 2);
        if (c >= 0 && c < 8 && d >= 0 && d < 8 && !check_whitechess(c, d) && check_endpoint()) break;
        printf("Please enter the correct end position\n");
    }
    move();
    draw_board();


    return 0;
}
