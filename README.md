# SnakeMonGame-Phase-2

This repository contains a C++ implementation of a Snakes & Ladders game, developed using the Carnegie Mellon Graphics Library (CMU Graphics). The project delivers a standalone executable for interactive gameplay, created as an educational exercise in introductory computer programming.

## Project Overview

The SnakeMonGame-Phase-2 project provides a graphical rendition of the classic Snakes & Ladders board game, supporting single-player and turn-based multiplayer modes. Players navigate a numbered grid by rolling a virtual die, with snakes causing position setbacks and ladders enabling forward jumps. The game concludes when a player reaches the final square, incorporating randomized movement and positional strategy.

Key components:
- **Library**: Built with the Carnegie Mellon Graphics Library (CMU Graphics), a C++ framework for 2D graphics, event handling, and window management, independent of external graphical dependencies.
- **Game Mechanics**:
  1. Initialization of a fixed-size board with predefined snake and ladder positions.
  2. Pseudo-random die roll simulation for player movement.
  3. Logic for handling snake and ladder interactions, alongside turn-based progression.
  4. Real-time visualization of the board, player tokens, and game status.
- **Development Environment**: Structured as a Visual Studio solution, compiling to a Windows executable. The codebase employs object-oriented principles with distinct classes for board management, player state, and game control.
- **Context**: Developed as a course project in the first semester of the first year of Computer Engineering Department in Cairo University - Faculty of Engineering, demonstrating proficiency in C++ programming, graphical interfaces, and game logic implementation.
- 

## Building and Running

To compile and run the project:
1. Clone the repository:
   ```
   git clone https://github.com/TheFlyingEmp/SnakeMonGame-Phase-2.git
   cd SnakeMonGame-Phase-2
   ```
2. Open in Visual Studio (2019 or later):
   - Load `SnakeMonGame.vcxproj`.
3. Configure the CMU Graphics Library:
   - Download from the official CMU Graphics website [https://www.cs.cmu.edu/~cm-gfxpkg/about.html] and link headers/libraries as per documentation.
4. Build the project:
   - Select "Release" configuration and build (Ctrl+Shift+B).
5. Run the executable:
   - Launch `SnakeMonGame.exe` from the output directory (e.g., `x64/Release/`).
   - A graphical window will display the board and gameplay controls.

The project requires C++11 or higher and depends solely on CMU Graphics and standard C++ libraries.

## Usage

Upon launching:
1. The graphical interface renders the Snakes & Ladders board, marked with positions, snakes, and ladders.
2. Players select the number of participants (up to four) and initiate play via on-screen prompts.
3. Mouse clicks trigger die rolls for the current player, indicated by a highlighted token.
4. Movement is automatically adjusted for snake or ladder encounters.
5. The game announces the winner upon reaching the final square.

Interactions are managed via mouse input, with potential keyboard support for exiting (e.g., ESC).

## License

This project is licensed under the MIT License, permitting modification, distribution, and educational use with proper attribution.
