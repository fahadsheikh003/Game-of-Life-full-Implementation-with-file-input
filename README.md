# Game-of-Life-full-Implementation-with-file-input

# Problem:
Game of Life (or just “Life”) is not really a game. There’s no winning or losing or destroying your opponent mentally and spiritually. Life is a “cellular automaton” - a system of cells that live on a grid, where they live, die and evolve according to the rules that govern their world. 

Life’s simple, elegant rules give rise to astonishingly complex emergent behavior. It is played on a 2-D grid Each square in the grid contains a cell, and each cell starts the game as either “alive” or “dead”. Play proceeds in rounds. During each round, each cell looks at its 8 immediate neighbors and counts up the number of them that are currently alive. 

Make a type char 30 x 30 2D grid. Randomly assign active and dead cells. Active cells will have value ‘*’ and dead cell will have value ‘ ’.

![image](https://user-images.githubusercontent.com/87650614/151595688-dda895eb-070c-4410-8683-9822da556546.png)

In Above diagram Blue cell is the current cell whereas Red cells are its neighboring cells
The cell then updates its own liveness according to 4 rules:
  1. Any live cell with 0 or 1 live neighbors becomes dead, because of underpopulation
  2. Any live cell with 2 or 3 live neighbors stays alive, because its neighborhood is just right
  3. Any live cell with more than 3 live neighbors becomes dead, because of overpopulation
  4. Any dead cell with exactly 3 live neighbors becomes alive, by reproduction
  
Run your code for infinite rounds and observe the pattern changing 
And that’s all there is to Life. These 4 rules give rise to some unbelievably complex and beautiful patterns, and an equally unbelievable quantity of analysis by Life devotees intent on discovering new ones.

# Explanation of Implementation:
I asked user if s/he wants to load a file (detail of active cells) or randomly initialize grid (60% active cells) and passed the grid in the function of GameofLife. In GameofLife function, I created another grid of dimension 30x30 and stored the result of previous grid in it after applying the rules of game according to the coordinates of active cell. After storing result in new grid, I printed new grid and stored the content of new grid in the old one in order to repeat the process.
