# Showdown

## Project Objective
This project originated from the need to learn C++ and Object-Oriented Analysis (OOA). The goal is to deepen the understanding of these concepts through practical application and to implement the learned knowledge in a real-world project.

## Technologies and Skills Practiced
- Object-Oriented Analysis (OOA) using the Astah tool.
- Programming in the C++ language.
- Developing with the Visual Studio IDE.

## Functionality of the Project
The project is a Showdown poker card game with the following features:

### Player Composition
- Accommodates up to four players, which can be a mix of human players and AI players.
- Interaction for human players is through a Command Line Interface (CLI).

### Deck and Cards
- Utilizes a standard deck of 52 playing cards.
- Each card has a rank and a suit, following traditional poker rules.

### Gameplay Mechanics
- Players are named P1 through P4 and can enter their names.
- The game starts with shuffling the deck and players drawing 13 cards each.
- Players take turns to play cards, exchange hands, and score points.

### Card Rankings
- Cards are ranked from 2 to A, in ascending order of value.
- Suits are Clubs, Diamonds, Hearts, and Spades.

### Determining the Winner
- The game is played over 13 rounds, and the player with the highest score wins.

## Installation and Running Guide

### Prerequisites
Ensure you have a C++ compiler installed on your system.

### Getting the Project
Download the project files from the GitHub repository.

### Project Structure
- The `src` folder contains the source code.
- The `documents` folder contains additional project documentation.

### Running the Application
To run the project, execute the following steps:

1. Navigate to the `src` directory where the `main.cpp` file is located.
2. Compile the code using the following command (example for `g++`):
   ```
   g++ main.cpp -o game
   ```
3. Run the executable:
   - On Windows:
     ```
     game.exe
     ```
   - On Unix-like systems:
     ```
     ./game
     ```

Follow the CLI prompts to interact with the game.