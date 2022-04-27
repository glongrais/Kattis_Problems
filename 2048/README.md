# 2048

## Original link

[2048 on Kattis](https://open.kattis.com/problems/2048)

## Principle 

### Description

2048 is a single-player puzzle game created by Gabriele Cirulli1. It is played on a 4 × 4 grid that contains integers ≥ 2 that are powers of 2. The player can use a keyboard arrow key (left/up/right/down) to move all the tiles simultaneously. Tiles slide as far as possible in the chosen direction until they are stopped by either another tile or the edge of the grid. If two tiles of the same number collide while moving, they will merge into a tile with the total value of the two tiles that collided. The resulting tile cannot merge with another tile again in the same move. Please observe this merging behavior carefully in all Sample Inputs and Outputs.  

### Input

The input is always a valid game state of a 2048 puzzle. The first four lines of input, that each contains four integers, describe the 16 integers in the 4 × 4 grid of 2048 puzzle. The 𝑗-th integer in the 𝑖-th line denotes the content of the cell located at the 𝑖-th row and the 𝑗-th cell. For this problem, all integers in the input will be either {0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}. Integer 0 means an empty cell.