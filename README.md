# Guide Me

## Overview

**Guide Me** is a graphical user interface (GUI) application developed in C++ using the Qt framework. It enables users to discover all possible paths between a source city and a destination city within a specified budget. The system utilizes Breadth-First Search (BFS) and Depth-First Search (DFS) algorithms for pathfinding. Additionally, users can manage their accounts and modify the city's transportation network through an intuitive interface.

## Features

### User Management

- **Sign Up**: New users can create an account with a unique username and password.
- **Log In**: Existing users can access the system by logging in with their credentials.
- **Profile Editing**: Users can update their personal information, which is then saved to the "Users" file.

### Pathfinding

- **Input Parameters**: After logging in, users can input the source city, destination city, budget, and preferred search method (BFS or DFS).
- **Path Calculation**: The system calculates all possible paths between the source and destination cities that are within the specified budget.
- **Sorted Output**: Paths are displayed in ascending order based on total cost.
- **No Available Paths**: If no paths are found within the budget, the system informs the user accordingly.

### Transportation Network Editing

1. **Add New Path**:
   - Users can add a new transportation method by specifying the source city, destination city, method of transportation, and cost.
   - The new path is added to the city's transportation network.

2. **Update Existing Path**:
   - Users can view all transportation methods between two cities and update the method name, cost, or both.

3. **Delete Path**:
   - Users can view and select transportation methods between two cities to delete.
   - If all methods between two cities are deleted, the route is removed from the network.

**Note**: All changes to the transportation network are saved to the file upon exiting the program.

## Technologies Used

- **Programming Language**: C++
- **Framework**: Qt for GUI development
- **Data Structures**: Graphs for representing the city's transportation network
- **Algorithms**: BFS and DFS for pathfinding

### Project team contributors
Abanoub Saweris.
Yousef Osama.
Mario Maged.
Kenzy Adel.
Christine Medhat.
Mazen Mahmoud.
Micheal Nabil.
