
# Settlers of Catan Ex4 in System Programming 2 Course at Ariel University

## Overview

This project is a simplified version of the popular board game, Settlers of Catan, for three players, developed using C++. The game allows players to collect resources, build structures, and compete to reach 10 victory points. It includes features such as a static game board, player management, and adherence to simplified Catan rules.

## Features

- **Static Game Board:** The game board is pre-defined with fixed resource tiles and dice numbers for easier management.
- **Player Management:** Players can manage their resources, place settlements, roads, and cities, and trade with other players.
- **Resource Collection:** Players collect resources based on dice rolls and the positions of their settlements and cities.
- **Building Structures:** Players can build roads, settlements, and upgrade settlements to cities.
- **Development Cards:** Players can buy and play development cards that provide various benefits.
- **Victory Points:** The first player to reach 10 victory points wins the game.

## Getting Started

1. **Clone the repository:**
   ```bash
   git clone https://github.com/MaorBer/CPP_EX3_CATAN
   cd Downloads/CPP_EX3_CATAN
   ```

2. **Build the project:**
   ```bash
   run make to start
   ```

## Functionality

### Board Class
- **Initialization:** The board is initialized with 19 predefined tiles, each with a specific resource type and dice number.
- **Adjacency Setup:** Each tile is assigned its adjacent tiles to manage the game logic for resource collection and building restrictions.

### Player Class
- **Resource Management:** Players can collect and spend resources (wood, brick, wheat, ore, and sheep).
- **Building Structures:** Functions for placing settlements, roads, and upgrading settlements to cities.
- **Trading:** Players can trade resources with each other.
- **Development Cards:** Players can buy and play development cards.

### Catan Class
- **Game Setup:** Initializes the game with three players and sets up the board.
- **Game Flow:** Manages the turn-based gameplay, including rolling dice, collecting resources, and building structures.
- **Win Condition:** Checks and announces the winner when a player reaches 10 victory points.

### Example Test Cases
- **Place Structures:** Tests for placing settlements, roads, and cities on the board.
- **Dice Roll:** Tests for rolling dice and ensuring correct resource distribution.
- **Trading:** Tests for trading resources between players.
- **Development Cards:** Tests for buying and playing development cards.
- **Victory Condition:** Tests for checking the victory condition.

## Author

This project was developed by Maor Berenstein.
Email: maorw9@gmail.com.