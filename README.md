# Tic Tac Toe in C

[![C Badge](https://img.shields.io/badge/Language-C-blue)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux-green)](https://github.com/)

A two-player interactive Tic Tac Toe game built in C. Players alternate turns placing X and O on a 3x3 grid. The game detects wins (three in a row) and draw conditions. Play multiple rounds with the option to continue or quit.

## How to Play

1. Run the program
2. Players take turns entering their move
3. Enter row and column numbers (both 1-3) to place your mark
4. First player to get three marks in a row (horizontal, vertical, or diagonal) wins
5. If all cells are filled with no winner, it's a draw
6. After each game, choose to play again or quit

**Game Rules:**
- Player X always goes first
- Players alternate between X and O
- A cell can only be marked once
- Win conditions: 3 in a row (horizontal, vertical, or diagonal)
- Draw: All 9 cells filled with no winner

## Prerequisites

- **GCC Compiler** (GNU Compiler Collection)
- **Windows:** MinGW or any C compiler
- **macOS:** Xcode Command Line Tools or Homebrew GCC
- **Linux:** GCC (usually pre-installed)
- **Basic knowledge of C** to understand the code

## How to Compile and Run

### On Linux:

```bash
gcc tictactoe.c -o tictactoe
./tictactoe
```

### On macOS:

```bash
gcc tictactoe.c -o tictactoe
./tictactoe
```

### On Windows (MinGW):

```bash
gcc tictactoe.c -o tictactoe.exe
tictactoe.exe
```

### Using Makefile (Optional - All Platforms):

Create a file named `Makefile` in your project directory:

```
CC = gcc
TARGET = tictactoe

all: $(TARGET)

$(TARGET): tictactoe.c
	$(CC) -o $(TARGET) tictactoe.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
```

Then run:

```bash
make
make run
make clean
```

## Sample Output

```
========== TIC TAC TOE ==========

    1   2   3  
  -------------
1|   |   |   |
  -------------
2|   |   |   |
  -------------
3|   |   |   |
  -------------

Player X, enter move (row col: 1-3 1-3): 2 2

========== TIC TAC TOE ==========

    1   2   3  
  -------------
1|   |   |   |
  -------------
2|   | X |   |
  -------------
3|   |   |   |
  -------------

Player O, enter move (row col: 1-3 1-3): 1 1

========== TIC TAC TOE ==========

    1   2   3  
  -------------
1| O |   |   |
  -------------
2|   | X |   |
  -------------
3|   |   |   |
  -------------

Player X, enter move (row col: 1-3 1-3): 3 3

========== TIC TAC TOE ==========

    1   2   3  
  -------------
1| O |   |   |
  -------------
2|   | X |   |
  -------------
3|   |   | X |
  -------------

Player O, enter move (row col: 1-3 1-3): 3 1

========== TIC TAC TOE ==========

    1   2   3  
  -------------
1| O |   |   |
  -------------
2|   | X |   |
  -------------
3| O |   | X |
  -------------

Player X, enter move (row col: 1-3 1-3): 1 2

========== TIC TAC TOE ==========

    1   2   3  
  -------------
1| O | X |   |
  -------------
2|   | X |   |
  -------------
3| O |   | X |
  -------------

Player X wins!
Enter C/c to play again and Q/q to quit the game: q
Selected Q/q Exiting the game.
Thank you for playing. Goodbye.
```

## About the Project

- **Type:** Two-player console game
- **Language:** C (Standard C89/C99)
- **Lines of Code:** ~140
- **Time to Complete:** 45-60 minutes for beginners
- **Difficulty:** Beginner to Intermediate
- **No External Libraries:** Uses only standard C library (stdio.h)
- **Board:** 3x3 grid with dynamic display
- **Players:** Human vs Human (AI opponent planned for future versions)

## Code Structure

### Project Files

```
tic-tac-toe-c/
│
└── tictactoe.c       # Main program file
```

Single file project with no external dependencies.

## How Each Function Works

### 1. `initBoard()`
- **Purpose:** Initialize the game board
- **What it does:**
  - Loops through all 9 cells (3x3 grid)
  - Sets each cell to empty space character `' '`
  - Called at the start of each new game
- **Returns:** Nothing (void)

### 2. `printBoard()`
- **Purpose:** Display the current board state
- **What it does:**
  - Prints the board with row and column numbers (1-3)
  - Shows borders using `+`, `-`, and `|` characters
  - Displays the current marks (X, O, or empty space) in each cell
  - Called after each player's move so they can see the updated board
- **Returns:** Nothing (void)

### 3. `checkWin()`
- **Purpose:** Check if the current player has won
- **What it does:**
  - Checks all 3 rows for three matching marks in a row
  - Checks all 3 columns for three matching marks in a row
  - Checks both diagonals (top-left to bottom-right and top-right to bottom-left)
  - Compares each cell to `currentPlayer` (X or O)
- **Returns:** 1 if player wins, 0 if no win

### 4. `isDraw()`
- **Purpose:** Check if the game is a draw
- **What it does:**
  - Loops through all 9 cells
  - If any cell is empty (space character), game continues
  - If all cells are filled and no winner exists, it's a draw
- **Returns:** 1 if board is full (draw), 0 if cells remain empty

### 5. `main()`
- **Purpose:** Control the overall game flow
- **What it does:**
  - Initializes the board at game start
  - Displays the board
  - Gets player input (row and column)
  - Validates input (checks if numbers are 1-3 and cell is empty)
  - Updates the board with the player's mark
  - Checks for win or draw conditions
  - Switches between players (X and O)
  - Asks player if they want to continue or quit after each game
- **Returns:** 0 to exit the program

## Code Flow

```
START
  |
  v
INITIALIZE BOARD (All cells empty)
  |
  v
SET PLAYER TO 'X'
  |
  v
+-------------------------------------------+
| GAME LOOP (while game not won/drawn)      |
|                                           |
|  1. DISPLAY BOARD                         |
|  |                                        |
|  v                                        |
|  GET PLAYER INPUT (row, col)              |
|  |                                        |
|  v                                        |
|  VALIDATE MOVE                            |
|  | (Check: 1-3 range, cell empty)         |
|  | NO -> Ask again                        |
|  | YES -> Continue                        |
|  |                                        |
|  v                                        |
|  UPDATE BOARD (Place X or O)              |
|  |                                        |
|  v                                        |
|  CHECK WIN                                |
|  | YES -> Display board + "Player wins"   |
|  |        Break loop                      |
|  | NO -> Continue                         |
|  |                                        |
|  v                                        |
|  CHECK DRAW                               |
|  | YES -> Display board + "It's a draw"   |
|  |        Break loop                      |
|  | NO -> Continue                         |
|  |                                        |
|  v                                        |
|  SWITCH PLAYER (X to O, O to X)           |
|  |                                        |
|  +-- Loop back to DISPLAY BOARD           |
|                                           |
+-------------------------------------------+
  |
  v
ASK: PLAY AGAIN? (C/c or Q/q)
  |
  +-- If C/c -> Go back to INITIALIZE BOARD
  |
  +-- If Q/q -> EXIT PROGRAM
  |
  v
END
```

## Learning Outcomes

By studying and building this project, you will learn:

### 1. 2D Arrays
- How to create and use 2D arrays in C
- Accessing array elements with two indices `board[row][col]`
- Iterating through 2D arrays with nested loops
- Using arrays to represent a game board or grid

### 2. Functions and Modularity
- Breaking complex programs into smaller functions
- Function parameters and return values
- Using functions to organize code logically
- Passing values between functions
- Void functions (functions that return nothing)

### 3. Input Validation
- Validating user input with `scanf()`
- Checking if input meets conditions (range 1-3)
- Detecting when a cell is already occupied
- Clearing the input buffer with `while(getchar() != '\n')`
- Handling invalid input gracefully

### 4. Conditional Logic
- Using `if-else` statements for multiple conditions
- Comparing characters (checking X or O)
- Logical operators (AND `&&`, OR `||`)
- Nested if statements for complex logic
- Ternary operator `?` `:` for switching players

### 5. Loops and Control Flow
- Nested loops (for loops within for loops)
- While loops for game rounds and input validation
- Breaking out of loops with `break` statement
- Continue statement to skip to next iteration
- Controlling program flow with conditions

### 6. Character Handling
- Working with character variables
- Comparing characters
- Using space character `' '` to represent empty cells
- Printing characters in formatted output

### 7. Game Logic
- Implementing win detection (rows, columns, diagonals)
- Checking draw conditions
- Managing game state (current player, board state)
- Turn-based player alternation
- Game loops and restart logic

## Future Enhancements

Planned features for future versions:

- Play against computer AI (easy, medium, hard difficulty levels)
- Player name input and score tracking
- Best of series (play multiple games, track wins)
- Undo move functionality
- Replay game history
- Improved UI with colors or graphics
- Network/online multiplayer

## Project Details

- **Single File:** All code in one .c file for simplicity
- **No Dependencies:** Uses only standard C library
- **Input Method:** Command-line interface
- **Game State:** Maintained in global variables (board, currentPlayer)
- **Turn System:** Alternates between players X and O
- **Validation:** Validates all user input before processing

## License

This project is licensed under the MIT License.

## Author

Created as a learning project for understanding C fundamentals and game logic.

---

**Happy Coding!** 🎮
