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
bool player = true;
bool gameover = false;
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
void chess_change() {
    char cc;        
    printf("Choosing (B / R / Q / N)\n");
    scanf("%c", &cc, 1);
    if (cc == 'B' || cc == 'R' || cc == 'Q' || cc == 'N') {
        board[a][b] = cc;
    }
}
bool check_endpoint() {
    char chess = board[a][b];
    int vx = d - b;
    int vy = c - a;
    if (chess == 'P') {
        if (vx == 0 && vy == -1 && board[c][d] == ' ') return true;
        if (vx == 1 && vy == -1 && check_blackchess(c, d)) return true;
        if (vx == -1 && vy == -1 && check_blackchess(c, d)) return true;
        if (a == 6 && vx == 0 && vy == -2 && board[c][d] == ' ') return true;
        return false;
    }
    if (chess == 'p') {
        if (vx == 0 && vy == 1 && board[c][d] == ' ') return true;
        if (vx == 1 && vy == 1 && check_whitechess(c, d)) return true;
        if (vx == -1 && vy == 1 && check_whitechess(c, d)) return true;
        if (a == 1 && vx == 0 && vy == 2 && board[c][d] == ' ') return true;
        return false;
    }
    if (chess == 'K' || chess == 'k') {
        int dxy[8][2] = { 1, 1, 0, 1, -1, 1, 1, 0 , -1, 0, 1, -1, 0, -1, -1, -1 };
        int i = 0;
        for (; i < 8; i++) {
            if (vx == dxy[i][0] && vy == dxy[i][1]) return true;
        }
        return false;
    }
    if (chess == 'N' || chess == 'n') {
        int dxy[8][2] = { 2, 1, 2, -1, -2, 1, -2, -1, 1, 2, -1, 2, 1, -2, -1, -2 };
        int i = 0;
        for (; i < 8; i++) {
            if (vx == dxy[i][0] && vy == dxy[i][1]) return true;
        }
        return false;
    }
    if (chess == 'R' || chess == 'r') {
        if (vx != 0 && vy != 0 ) return false;
        if (vy > 0) {
            int i = a + 1;
            while (i < c) {
                if (board[i++][b] != ' ') return false;
            }
        }
        else if (vx > 0){
            int i = b + 1;
            while (i < d) {
                if (board[a][i++] != ' ') return false;
            }
        }
        else if (vy < 0) {
            int i = a - 1;
            while (i > c) {
                if (board[i--][b] != ' ') return false;
            }
        }
        else {
            int i = b - 1;
            while (i > d) {
                if (board[a][i--] != ' ') return false;
            }
        }
        return true;
    }
    if (chess == 'B' || chess == 'b') {
        if (abs(vx) != abs(vy)) return false;
        int dxy[4][2] = { 1, 1, 1, -1, -1, 1, -1, -1 }, i = 0;
        for (; i < 4; i++) {
            if (vy / 2 == dxy[i][0] && vx / 2 == dxy[i][1]) {
                int ny = a + dxy[i][0], nx = b + dxy[i][1];
                while (nx != d && ny != c) {
                    if (board[ny][nx] != ' ') return false;
                    ny += dxy[i][0];
                    nx += dxy[i][1];
                }
                break;
            }
        }
        return true;
    }
    if (chess == 'Q' || chess == 'q') {
        if (vx == 0 && vy != 0) {
            if (vy > 0) {
                int i = a + 1;
                while (i < c) {
                    if (board[i++][b] != ' ') return false;
                }
                return true;
            }
            else {
                int i = a - 1;
                while (i > c) {
                    if (board[i--][b] != ' ') return false;
                }
                return true;
            }
        }
        if (vx != 0 && vy == 0) {
            if (vx > 0) {
                int i = b + 1;
                while (i < d) {
                    if (board[a][i++] != ' ') return false;
                }
                return true;
            }
            else {
                int i = b - 1;
                while (i > d) {
                    if (board[a][i--] != ' ') return false;
                }
                return true;
            }
        }
        if (abs(vx) == abs(vy)) {
            int dxy[4][2] = { 1, 1, 1, -1, -1, 1, -1, -1 }, i = 0;
            for (; i < 4; i++) {
                if (vy / 2 == dxy[i][0] && vx / 2 == dxy[i][1]) {
                    int ny = a + dxy[i][0], nx = b + dxy[i][1];
                    while (nx != d && ny != c) {
                        if (board[ny][nx] != ' ') return false;
                        ny += dxy[i][0];
                        nx += dxy[i][1];
                    }
                    return true;
                }            
            }
        }

        return false;
    }
    return false;
}


int main() {
    while (!gameover) {
        draw_board();
        if (player) {       // "White" go first. choosing the white chess
            player = false;
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
                gameover = true;
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
            player = true;
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
                gameover = true;
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

