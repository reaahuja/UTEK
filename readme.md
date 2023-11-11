# UTEK
Programming
UTEK 2023 - Sustainable cities

This repository contains two C++ programs:

Graph Matrix Creator: A program that reads an input string representing directed graph links and generates an adjacency matrix.

Minimum Cost Path Finder: A program that calculates the minimum cost path between two intersections in a directed graph.

Table of Contents:

Graph Matrix Creator Overview

Graph Matrix Creator Usage
Graph Matrix Creator Compilation
Graph Matrix Creator Example
Graph Matrix Creator Contributing
Graph Matrix Creator License

Minimum Cost Path Finder Overview

Minimum Cost Path Finder Usage
Minimum Cost Path Finder Compilation
Minimum Cost Path Finder Example
Minimum Cost Path Finder Contributing
Minimum Cost Path Finder License

Graph Matrix Creator Overview:

The Graph Matrix Creator is a C++ program that reads an input string representing directed graph links and generates an adjacency matrix. The program uses a set of unique nodes extracted from the input to create the matrix, and it counts the occurrences of links between nodes.

Graph Matrix Creator Usage
To use the program:

Clone the repository or download the source code.
Compile the program using a C++ compiler.
Run the compiled executable.
Enter the input string when prompted.

Graph Matrix Creator Compilation
Compile the program using a C++ compiler. For example, using g++:
g++ graph_matrix_creator.cpp -o graph_matrix_creator

Graph Matrix Creator Example:
Suppose you have the following input string:
e->fn, dx->abc, dx->e, abc->ca, dx->fn, ca->fn
The program will output the adjacency matrix:

    a abc ca dx e fn
---------------------
a | 0   0  0  0  0  0
abc | 0   0  1  0  0  0
ca |  0   0  0  0  0  1
dx |  0   1  0  0  1  1
e  |   0   0  0  0  0  1
fn |  0   0  1  1  1  0

Graph Matrix Creator Contributing
Feel free to contribute to this project. You can fork the repository, make changes, and submit a pull request.

Graph Matrix Creator License
This project is licensed under the MIT License.

Minimum Cost Path Finder Overview:
The Minimum Cost Path Finder is a C++ program that calculates the minimum cost path between two intersections in a directed graph. The program employs Held-Karp algorithm to find the path with the minimum cost.

Minimum Cost Path Finder Usage:
To use the program:

Clone the repository or download the source code.
Compile the program using a C++ compiler.
Run the compiled executable.
Enter the starting and ending intersections when prompted.
Enter the directed graph links with associated costs.

Minimum Cost Path Finder Compilation:
Compile the program using a C++ compiler. For example, using g++:
g++ minimum_cost_path_finder.cpp -o minimum_cost_path_finder

Minimum Cost Path Finder Example:
Suppose you have the following input:
Starting intersection: a
Ending intersection: d
a->b ($4), b->d ($5), c->d ($3), d->a ($4), a->c ($4), d->a ($1), c->b ($1)
The program will output the minimum cost path:
Best path: a->c->b->d
Cost: $10

Minimum Cost Path Finder Contributing
Feel free to contribute to this project. You can fork the repository, make changes, and submit a pull request.

Minimum Cost Path Finder License
This project is licensed under the MIT License.
