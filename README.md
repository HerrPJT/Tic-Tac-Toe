# Tic-Tac-Toe 
Tic-Tac-Toe Game in C++ Language

---

##  Table of Contents
* [Overview](#overview)
* [How to Play](#how-to-play)
* [Game Rules](#game-rules)
* [Features](#features)
* [Technical Architecture](#technical-architeture)
* [External Resources](#external resources)
  
  
---
### Overview
This repository contains a fully functional Tic-Tac-Toe game. 
It was built to demonstrate core programming principles such as array manipulation, win-condition algorithms, and turn-based logic.

### How to Play
- Launch the game using the instructions above.
- Player 1 is assigned X and Player 2/Computer is assigned O.
- Enter the number of the where you want to place your mark.
- The game will announce the winner or a draw automatically.

### Game Rules
- The game is played on a grid that's 3 squares by 3 squares.
- The first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner.
- When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.
  
### Features

## Game Modes
* **Human vs. Computer:** Play against an AI with multiple difficulty levels.
* **Human vs. Human:** Local multiplayer between two users.
* **Computer vs. Computer:** Automated matches between AI entities.

## AI Difficulty Levels
The computer opponent uses several logic layers to determine its moves:
* **Elementary:** Uses basic random moves via the `rand` function.
* **Easy:** Analyzes the board to win in the next move if possible.
* **Medium:** Plays to win or blocks the opponent's winning move (move cutting).
* **Advanced (Hard):** A learning AI that tracks wins and losses. It consults historical data to replicate winning moves or avoid past mistakes based on the current board state.

## Systems & Mechanics
* **Save/Load System:** Users can save their progress mid-game. Boards are saved with specific character mapping (e.g., spaces saved as 's') to ensure file reading compatibility.
* **Dynamic Top 10 Ranking:** Tracks player statistics (Wins, Draws, Losses). The system was evolved from a static array to a **Dynamic Linked List** for efficient memory management.
* **Move History:** The game records and displays the sequence of board states for every turn in a match.
* **Input Validation:** All user inputs are sanitized to prevent program crashes from improper use.

  
### Technical Architecture

## Class Structure
The project is built on an interconnected OOP architecture:
* **Board Class:** Manages the 3x3 grid and victory condition analysis.
* **User Class:** Handles player profiles, statistics, and file I/O for persistent player data.
* **Computer Class:** Contains difficulty algorithms and board simulation logic to predict future moves.
* **Ranking Class:** A "friend" of the User class; manages the leaderboard using a **Bubble Sort** algorithm.
* **Game Class:** Manages the high-level match state, including the ability to resume games using pointers.

## Requirements & Development
* **Language:** C++ 
* **Libraries:** `fstream` (File handling), `iostream`, and standard C++ utilities.
* **Memory Management:** Utilizes dynamic memory allocation for the ranking system.
* **Integrity:** This project was developed without the use of third-party source code or AI-generated logic, based on independent research of implementation algorithms.
 
## External Resources
* [GeeksforGeeks - Tic-Tac-Toe Implementation](https://www.geeksforgeeks.org/implementation-of-tic-tac-toe-game/) 
* [Guru99 - C++ File Handling](https://www.guru99.com/pt/cpp-file-read-write-open.html) 

  

