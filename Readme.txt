Character Customization and Battle Simulation

Overview
This C++ program allows two players to create and customize characters for a 1v1 battle simulation. Players can give their characters names, choose a character type (Fire, Water, or Grass), and allocate attribute points to various stats, such as health, attack, defense, and speed. The characters' stats determine their performance in the battle simulation. Additionally, the program includes a set of related classes that contribute to the battle simulation:

Character: The base class for all characters.
Move: A class that represents character moves.
Attack: A class that represents character attacks, derived from Move.
PhysicalAttack: A class that models physical attacks.
MagicalAttack: A class that models magical attacks.
Movepool: A class that manages a character's available moves and attacks.

Getting Started
To run this program, follow these steps:
Ensure you have a C++ compiler installed on your system.
Download or clone the source code from the repository.
Compile the code using the C++ compiler.
Run the executable to start the character customization process and the battle simulation.
Character Customization
Naming
Players can choose names for their characters. Names must not be empty.

Character Type
Players can select one of the following character types:

Fire: Strong against Grass characters.
Grass: Strong against Water characters.
Water: Strong against Fire characters.
Stat Allocation
Players are allocated 600 points to distribute across six different stats. These stats include:

Health: Determines the character's health points.
Physical Attack: Determines the damage inflicted by physical attacks.
Magical Attack: Determines the damage inflicted by magical attacks.
Physical Defense: Determines the character's resistance to physical attacks.
Magical Defense: Determines the character's resistance to magical attacks.
Speed: Determines the character's initiative in battles.
Stats must be allocated points between 1 and 250.

Classes and Inheritance
Character
The Character class serves as the base class for all characters. It contains common character attributes and methods.

Move
The Move class represents character moves used during battles.

Attack
The Attack class represents character attacks and is derived from the Move class.

PhysicalAttack and MagicalAttack
These classes, derived from Attack, represent physical and magical attacks, respectively.

Movepool
The Movepool class manages a character's available moves and attacks, allowing for customization of a character's move set.

Gameplay
After customizing their characters, players can engage in a 1v1 battle simulation. Character attributes, moves, and attacks play a significant role in determining the outcome of battles.

Project Structure
Character.h: Header file containing the Character class definition.
Character.cpp: Implementation of the Character class methods.
Move.h: Header file for the Move class.
Move.cpp: Implementation of the Move class methods.
Attack.h: Header file for the Attack class.
Attack.cpp: Implementation of the Attack class methods.
PhysicalAttack.h: Header file for the PhysicalAttack class.
PhysicalAttack.cpp: Implementation of the PhysicalAttack class methods.
MagicalAttack.h: Header file for the MagicalAttack class.
MagicalAttack.cpp: Implementation of the MagicalAttack class methods.
Movepool.h: Header file for the Movepool class.
Movepool.cpp: Implementation of the Movepool class methods.
main.cpp: The main program that drives the character customization and battle simulation.

Usage
Run the program by compiling and executing main.cpp.
Follow the on-screen prompts to customize your character.
Allocate attribute points and choose moves to create your character's stats and moves.
Start the battle simulation with your customized characters.

Contributors
This project was created by Arnav Kapoor, Galvin Huang, Asad Ismail. Feel free to contribute, make improvements, or report any issues through GitHub.