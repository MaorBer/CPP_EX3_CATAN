# Catan Game Implementation in C++

## Overview

This project is a digital implementation of the popular board game, Catan, developed using C++. The game allows players to collect resources, build structures, and compete to reach 10 victory points. It includes features such as an interactive game board, player management, development cards, and adherence to the official Catan rules.

## Features

- Interactive game board
- Player resource management
- Implementation of various development cards (e.g., Monopoly, Road Building, Year of Plenty, Knight, Victory Point)
- Game mechanics following the Catan rules

## Setup Instructions

### Prerequisites

- C++14 compatible compiler (e.g., g++)

### Installation

1. **Clone the repository:**

   \```bash
   git clone https://github.com/menashe12346/cpp_ex3.git
   cd cpp_ex3
   \```

2. **Build the project:**

   \```bash
   make
   \```

## Usage

1. **Run the game:**

   \```bash
   ./catan_game
   \```

2. **Gameplay:**

   - Follow the text-based prompts to play the game.
   - Interact with the game board to collect resources, build structures, and play development cards.

## Code Highlights

### Player Class Implementation

The `Player` class manages the resources and actions of each player in the game.

\```cpp
class Player {
public:
    int wood;
    int bricks;
    int wheat;
    int ore;
    int wool;

    // Constructor to initialize player resources
    Player();

    // Function to build a settlement
    void buildSettlement();

    // Function to build a city
    void buildCity();

    // Function to build a road
    void buildRoad();

    // Function to buy a development card
    void buyDevelopmentCard();

    // Other member functions
};
\```

### Board Initialization Logic

The `Board` class manages the game board and the tiles on it.

\```cpp
class Board {
public:
    // Function to initialize the board
    void initialize();

    // Function to display the board
    void displayBoard();

    // Function to place a settlement
    void placeSettlement(Player& player);

    // Function to place a city
    void placeCity(Player& player);

    // Function to place a road
    void placeRoad(Player& player);

    // Other member functions
};
\```

### DevelopmentCard Logic

The `DevelopmentCard` class is an abstract class that represents the various development cards in the game.

\```cpp
class DevelopmentCard {
public:
    virtual void playCard(Player &player) = 0;
};
\```

### Specific Development Cards

Each type of development card inherits from `DevelopmentCard`.

#### MonopolyCard

\```cpp
class MonopolyCard : public DevelopmentCard {
public:
    void playCard(Player &player) override;
};
\```

#### RoadBuildingCard

\```cpp
class RoadBuildingCard : public DevelopmentCard {
public:
    void playCard(Player &player) override;
};
\```

#### YearOfPlentyCard

\```cpp
class YearOfPlentyCard : public DevelopmentCard {
public:
    void playCard(Player &player) override;
};
\```

## Project Architecture

### Main Components

- **Board:** Manages the game board and tiles.
- **Tile:** Represents individual tiles with resources.
- **Player:** Manages player resources, settlements, and roads.
- **DevelopmentCard:** Handles various types of development cards.
- **City, Road, Settlement:** Represents different structures players can build.

## Game Mechanics

### Resources and Tiles

The game board consists of various tiles, each producing a specific resource:

- **Forest:** Produces wood
- **Hills:** Produce bricks
- **Pasture:** Produces wool
- **Fields:** Produce wheat
- **Mountains:** Produce ore
- **Desert:** Produces nothing

### Player Actions

Players can perform several actions:

- **Build Settlement:** Costs 1 brick, 1 wood, 1 wool, and 1 wheat. Settlements must be placed at least two roads away from other settlements.
- **Build City:** Costs 3 ore and 2 wheat. Cities replace settlements and yield double resources.
- **Build Road:** Costs 1 brick and 1 wood. Roads must connect to existing settlements, cities, or roads.
- **Buy Development Card:** Costs 1 ore, 1 wool, and 1 wheat. Development cards can be Monopoly, Road Building, Year of Plenty, Knight, or Victory Points.

### Development Cards

- **Monopoly:** Choose a resource, and all other players must give you all their cards of that resource.
- **Road Building:** Build two roads for free.
- **Year of Plenty:** Take any two resource cards from the bank.
- **Knight:** Move the robber and steal a resource card from another player.
- **Victory Points:** Add to the player's total victory points.

### Game Flow

1. **Initial Setup:** Each player starts with 2 settlements and 2 roads, and initial resources based on their settlements' locations.
2. **Turn Sequence:**
   - Roll dice to determine resource production.
   - Trade resources with other players.
   - Build roads, settlements, or cities, and buy development cards.
   - Play development cards.
3. **Winning the Game:** The game ends when a player reaches 10 victory points.

### Game Rules

   https://www.hakubia.com/wp-content/uploads/2021/01/%D7%A7%D7%98%D7%90%D7%9F.pdf