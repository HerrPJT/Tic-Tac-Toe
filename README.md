# Tic-Tac-Toe 
Tic-Tac-Toe Game in C++ Language

---

##  Table of Contents
* [Overview](#overview)
* [Features](#features)
* [Technologies Used](#technologies-used)
* [Installation](#installation)
* [How to Play](#how-to-play)
* [Game Rules](#game-rules)
  
---
## Overview
This repository contains a fully functional Tic-Tac-Toe game. 
It was built to demonstrate core programming principles such as array manipulation, win-condition algorithms, and turn-based logic.

##  Features
- **SinglePlayer:** Play against the computer in 4 difficulties(Elementary, Easy, Medium, Hard)
- **MultiPlayer Mode:** Play against a friend locally.
- **Dynamic Board:** Real-time updates of the 3x3 grid.
- **Smart Validation:** Prevents players from picking already occupied cells.
- **Win/Draw Detection:** Instant notification when a player wins or the game ends in a tie.
- **Save and Load Game:** Saves an ongoing game to be loaded later by the player
- **Statistics:** Show the victories, draws and defeats of the player

##  Technologies Used
- **Primary Language:** [C++]
- **Interface:** [Qt Creator]

##  Installation
1. **Clone the repository:**
   ```bash
   git clone [https://github.com/HerrPJT/Tic-Tac-Toe.git](https://github.com/HerrPJT/Tic-Tac-Toe.git)
2. Get a C++ IDE

## How to Play
- Launch the game using the instructions above.
- Player 1 is assigned X and Player 2/Computer is assigned O.
- Enter the number of the where you want to place your mark.
- The game will announce the winner or a draw automatically.
  
## Game Rules
- The game is played on a grid that's 3 squares by 3 squares.
- The first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner.
- When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.
