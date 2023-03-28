#include <stdio.h>
#include <stdlib.h>

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
int player = 1;
int gameover = 0;
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
int check_blackchess(int a, int b) {
    int i = 0;
    for (; i < 6; i++)
        if (board[a][b] == blackchess[i]) return 1;
    return 0;
}
int check_whitechess(int a, int b) {
    int i = 0;
    for (; i < 6; i++)
        if (board[a][b] == whitechess[i]) return 1;
    return 0;
}
void move() {
    board[c][d] = board[a][b];
    board[a][b] = ' ';
}
void chess_change() {
    char cc;        
    printf("Choosing (B / R / Q / N)\n");
    scanf("%c", &cc, 1);
    if (cc == 'B' || cc == 'R' || cc == 'Q' || cc == 'N') {
        board[a][b] = cc;
    }
}
int check_endpoint() {
    char chess = board[a][b];
    int vx = d - b;
    int vy = c - a;
    if (chess == 'P') {
        if (vx == 0 && vy == -1 && board[c][d] == ' ') return 1;
        if (vx == 1 && vy == -1 && check_blackchess(c, d)) return 1;
        if (vx == -1 && vy == -1 && check_blackchess(c, d)) return 1;
        if (a == 6 && vx == 0 && vy == -2 && board[c][d] == ' ') return 1;
        return 0;
    }
    if (chess == 'p') {
        if (vx == 0 && vy == 1 && board[c][d] == ' ') return 1;
        if (vx == 1 && vy == 1 && check_whitechess(c, d)) return 1;
        if (vx == -1 && vy == 1 && check_whitechess(c, d)) return 1;
        if (a == 1 && vx == 0 && vy == 2 && board[c][d] == ' ') return 1;
        return 0;
    }
    if (chess == 'K' || chess == 'k') {
        int dxy[8][2] = { 1, 1, 0, 1, -1, 1, 1, 0 , -1, 0, 1, -1, 0, -1, -1, -1 };
        int i = 0;
        for (; i < 8; i++) {
            if (vx == dxy[i][0] && vy == dxy[i][1]) return 1;
        }
        return 0;
    }
    if (chess == 'N' || chess == 'n') {
        int dxy[8][2] = { 2, 1, 2, -1, -2, 1, -2, -1, 1, 2, -1, 2, 1, -2, -1, -2 };
        int i = 0;
        for (; i < 8; i++) {
            if (vx == dxy[i][0] && vy == dxy[i][1]) return 1;
        }
        return 0;
    }
    if (chess == 'R' || chess == 'r') {
        if (vx != 0 && vy != 0 ) return 0;
        if (vy > 0) {
            int i = a + 1;
            while (i < c) {
                if (board[i++][b] != ' ') return 0;
            }
        }
        else if (vx > 0){
            int i = b + 1;
            while (i < d) {
                if (board[a][i++] != ' ') return 0;
            }
        }
        else if (vy < 0) {
            int i = a - 1;
            while (i > c) {
                if (board[i--][b] != ' ') return 0;
            }
        }
        else {
            int i = b - 1;
            while (i > d) {
                if (board[a][i--] != ' ') return 0;
            }
        }
        return 1;
    }
    if (chess == 'B' || chess == 'b') {
        if (abs(vx) != abs(vy)) return 0;
        int dxy[4][2] = { 1, 1, 1, -1, -1, 1, -1, -1 }, i = 0;
        for (; i < 4; i++) {
            if (vy / 2 == dxy[i][0] && vx / 2 == dxy[i][1]) {
                int ny = a + dxy[i][0], nx = b + dxy[i][1];
                while (nx != d && ny != c) {
                    if (board[ny][nx] != ' ') return 0;
                    ny += dxy[i][0];
                    nx += dxy[i][1];
                }
                break;
            }
        }
        return 1;
    }
    if (chess == 'Q' || chess == 'q') {
        if (vx == 0 && vy != 0) {
            if (vy > 0) {
                int i = a + 1;
                while (i < c) {
                    if (board[i++][b] != ' ') return 0;
                }
                return 1;
            }
            else {
                int i = a - 1;
                while (i > c) {
                    if (board[i--][b] != ' ') return 0;
                }
                return 1;
            }
        }
        if (vx != 0 && vy == 0) {
            if (vx > 0) {
                int i = b + 1;
                while (i < d) {
                    if (board[a][i++] != ' ') return 0;
                }
                return 1;
            }
            else {
                int i = b - 1;
                while (i > d) {
                    if (board[a][i--] != ' ') return 0;
                }
                return 1;
            }
        }
        if (abs(vx) == abs(vy)) {
            int dxy[4][2] = { 1, 1, 1, -1, -1, 1, -1, -1 }, i = 0;
            for (; i < 4; i++) {
                if (vy / 2 == dxy[i][0] && vx / 2 == dxy[i][1]) {
                    int ny = a + dxy[i][0], nx = b + dxy[i][1];
                    while (nx != d && ny != c) {
                        if (board[ny][nx] != ' ') return 0;
                        ny += dxy[i][0];
                        nx += dxy[i][1];
                    }
                    return 1;
                }            
            }
        }

        return 0;
    }
    return 0;
}


int main() {
    while (!gameover) {
        draw_board();
        if (player) {       // "White" go first. choosing the white chess
            player = 0;
            printf("Please choose the \"WHITE\" chess position: \n");
            while (1) {
                scanf("%d %d", &a, &b, 1);
                if (a >= 0 && a < 8 && b >= 0 && b < 8 && check_whitechess(a, b)) break;
                printf("Warning!Please enter \"WHITE\" chess position:\n");
            }
            printf("Please choose the end position: \n");
            while (1) {
                scanf("%d %d", &c, &d, 2);
                if (c >= 0 && c < 8 && d >= 0 && d < 8 && !check_whitechess(c, d) && check_endpoint()) break;
                printf("Warning!Please enter the correct end position:\n");
            }
            if (board[c][d] == 'k') {
                gameover = 1;
                move();
                break;
            }
            if (board[a][b] == 'P' && c == 0) {
                char cc;
                printf("Choosing (B / R / Q / N)\n");
                while (1) {
                    scanf("%c", &cc, 1);
                    if (cc == 'B' || cc == 'R' || cc == 'Q' || cc == 'N') {
                        board[a][b] = cc;
                        break;
                    }
                }
            }
            move();
            continue;
        }
        else {
            player = 1;
            printf("Please choose the \"BLACK\" chess position: \n");
            while (1) {
                scanf("%d %d", &a, &b, 1);
                if (a >= 0 && a < 8 && b >= 0 && b < 8 && check_blackchess(a, b)) break;
                printf("Warning!Please enter \"BLACK\" chess position:\n");
            }
            printf("Please choose the end position: \n");
            while (1) {
                scanf("%d %d", &c, &d, 2);
                if (c >= 0 && c < 8 && d >= 0 && d < 8 && !check_blackchess(c, d) && check_endpoint()) break;
                printf("Warning!Please enter the correct end position:\n");
            }
            if (board[c][d] == 'K') {
                gameover = 1;
                move();
                break;
            }
            if (board[a][b] == 'p' && c == 7) {
                char cc;
                printf("Choosing (b / r / q / n)\n");
                while (1) {
                    scanf("%c", &cc, 1);
                    if (cc == 'b' || cc == 'r' || cc == 'q' || cc == 'n') {
                        board[a][b] = cc;
                        break;
                    }
                }
            }
            move();
            continue;
        }
    }
    draw_board();
    printf("GAMEOVER!!! winner ");
    if (player)
        printf("BLACK\n");
    else
        printf("WHITE\n");

    return 0;
}
