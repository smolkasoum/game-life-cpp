# Game of Life

A C++ implementation of the classic cellular automaton "Conway's Game of Life".

## Description

This project simulates the evolution of a cellular automaton where each cell can be in one of two states:
- **Alive** (`*`)
- **Dead** (`.`)

Generations evolve according to the following rules:
1. Any live cell with fewer than two live neighbors dies (underpopulation)
2. Any live cell with more than three live neighbors dies (overpopulation)
3. Any live cell with two or three live neighbors lives on to the next generation
4. Any dead cell with exactly three live neighbors becomes a live cell (reproduction)

## Features

- Customizable grid size
- Two initialization modes: manual and automatic
- Configurable number of generations
- Real-time evolution visualization
- Console clearing between generations

## Requirements

- C++ compiler with C++11 support
- Windows OS (uses `windows.h` for `Sleep()` function)

## Compilation and Execution

```bash
g++ -o game_life game_life.cpp
./game_life
