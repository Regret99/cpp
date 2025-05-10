
in bin commands

mkdir -p bin
g++ main.cpp room_dec.cpp story_item.cpp utils.cpp -o bin/adventure
./bin/adventure

## temporary text
Creating a text adventure game in C++ can be a fun and rewarding project. Here’s a step-by-step guide along with resources to help you get started:

Step-by-Step Guide

Conceptualize Your Game
- Story and Setting: Define the plot, characters, and environment.
- Game Mechanics: Decide how the player will interact with the game (commands, inventory system, etc.).
Set Up Your Development Environment
- Install a C++ compiler (like GCC or MSVC).
- Choose an IDE or text editor (like Visual Studio, Code::Blocks, or Visual Studio Code).
Basic Structure
- Main Loop: Create a loop that handles user input and game updates.
- Input Handling: Use std::cin to capture player commands.
- Game State: Maintain a state to track the player’s location, inventory, and other attributes.
Design Your Game World
- Rooms/Locations: Define different areas with descriptions and possible actions.
- Items: Create objects that the player can interact with.
Implementing Game Logic
- Use functions to handle different commands (e.g., look, go, take).
- Create a parser to interpret player input.
Testing and Iteration
- Playtest your game frequently to find bugs and improve gameplay.
- Gather feedback and make adjustments.
Expand and Polish
- Add more features like save/load functionality, more complex puzzles, or a scoring system.
Recommended Resources

Books

"Creating Games in C++: A Step-by-Step Guide" by David P. L. Smith: This book provides a comprehensive guide to game development concepts, including text-based games.
"C++ Primer" by Stanley B. Lippman, Josée Lajoie, and Barbara E. Moo: A great resource to strengthen your C++ programming skills.
Online Tutorials

GeeksforGeeks C++: Offers numerous tutorials on C++ concepts that can be useful for game development. GeeksforGeeks C++ Tutorials.
Learn C++: A free resource that covers the basics of C++ programming. Learn C++.
Game Development Communities

Reddit: Subreddits like r/gamedev and r/learnprogramming can be great places to ask questions and share your progress.
Stack Overflow: A valuable resource for troubleshooting specific coding issues.

https://www.quora.com/How-would-I-make-a-C++-Text-Adventure-game-Guides-Books-Sites-ect

Start by defining a simple world with locations (rooms), objects, and NPCs. Implement a player character who can navigate between locations, pick up and use items, and interact with NPCs. Use classes to structure your game, such as Player, Room, and Item. Read and write data to files for saving progress. Keep it small at first—just a few rooms and simple interactions. Expand gradually with more mechanics like inventory management and quests.

