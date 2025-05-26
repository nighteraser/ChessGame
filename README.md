# ChessGame

A simple terminal-based chess game implemented in C.

## File
- `main.c`: Contains the source code of the game.

## How to Compile and Run

1. **Compile:**

   Use `gcc` to compile the source file:

   ```bash
   gcc main.c -o chess
   ```
2. **Run the Game**
    ```bash
    ./chess
    ```


## How to play
### The game starts with a standard chessboard:
```
\ 0 1 2 3 4 5 6 7
0 r n b q k b n r
1 p p p p p p p p
2
3
4
5
6 P P P P P P P P
7 R N B Q K B N R
```
- Uppercase letters (`P`, `R`, `N`, `B`, `Q`, `K`) are WHITE pieces.
- Lowercase letters (`p`, `r`, `n`, `b`, `q`, `k`) are BLACK pieces.
- Rows and columns are labeled from 0 to 7.
- The game is turn-based: White moves first.
### Move GameBoard:
1. The game will prompt you to select a piece to move:
    ```
    Please choose the "WHITE" chess position:
    > 0 1
    ```
2. Then it will ask for the destination:
    ```
    Please choose the end position:
    > 4 6
    ```
### After this move, the board updates like this:
```
\ 0 1 2 3 4 5 6 7
0 r n b q k b n r
1 p p p p p p p p
2
3
4             P
5
6 P P P P P P   P
7 R N B Q K B N R
```
### Next Turn: BLACK
```
Please choose the "BLACK" chess position:
0 1
Please choose the end position:
2 2
```
Updated board:
```
\ 0 1 2 3 4 5 6 7
0 r   b q k b n r
1 p p p p p p p p
2     n
3       
4             P
5
6 P P P P P P   P
7 R N B Q K B N R
```
### Invalid Move Example
If you try to move an invalid piece (e.g. wrong color), you'll see:
```
Warning! Please enter "WHITE" chess position:
```
### Game Over
```
GAMEOVER!!! winner "WHITE"
```
