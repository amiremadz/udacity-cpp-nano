"""
Created: 4-18-2020
Author: Michael Harris

Generated a random csv grid for the A* algorithm to try to find the optimum route.
"""
import pandas as pd
import numpy as np
import argparse
import os
import time

"""
Creating command line arguments for the user to pass.
User shall pass the rows and columns dimensions of the 2D vector space.
"""
parser = argparse.ArgumentParser(description='Give the size of rows and columns for the grid.csv\n')
parser.add_argument('rows', type=int, help='Rows in the grid.csv')
parser.add_argument('columns', type=int, help='Columns in the grid.csv')
parser.add_argument('difficulty', type=int, help='Grid difficulty setting')
args = parser.parse_args()

# Constants passed from user
ROWS = args.rows
COLS = args.columns
DIFFICULTY = args.difficulty


def create_random_grid(rows: int, cols: int, difficulty: int):
    """Params:

    - rows: number of rows in the grid
    - cols: number of columns in the grid
    - difficulty: range 1-10 with 1 being the easiest (default 2 if passed incorrectly)

    Creates a csv file comprising of a randomly generated
    2D vector comprising of only 0 and 1.

    Dimensions correspond the the rows and cols variables
    passed into the function.

    Probabilities a cell having either 0 or 1:

    - Cell having a value of 0 --> probability is 80%
    - Cell having a value of 1 --> probability is 20%

    This is so we can create a random csv file for our A* algorithm
    to read from that has a large chance of having a solvable grid space."""
    if difficulty not in range(2, 10):
        difficulty = 2
    df = pd.DataFrame(np.random.random_integers(0, 10, (rows, cols)))
    df = df.applymap(lambda x: 0 if x >= difficulty else 1)
    df.iloc[0, 0], df.iloc[-1, -1] = 0, 0  # this stops the upper left and lower right corners from being 1
    if not os.path.exists('grids'):
        os.makedirs('grids')
    df.to_csv(f'grids/grid.csv', header=None, index=False, line_terminator=',\n')
    # print(df)  # leave for debugging


if __name__ == '__main__':
    print('+---------------+')
    print('|   |   |   |   |')
    print('+---------------+')
    print('| Generating... |')
    print('+---------------+')
    print('|   |   |   |   |')
    print('+---------------+')
    create_random_grid(ROWS, COLS, DIFFICULTY)
    print(f'\n\nGrid with dimensions of {ROWS}x{COLS} has been created in the /grid directory as grid.csv\n\n')
