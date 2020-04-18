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
User shall pass the width and length of the 2D vector space.
"""
parser = argparse.ArgumentParser(description='Give the width and height of the grid.csv\n')
parser.add_argument('width', type=int, help='Width of the grid.csv')
parser.add_argument('height', type=int, help='Height of the grid.csv')
args = parser.parse_args()

# Constants passed from user
W = args.width
H = args.height


def create_random_grid(w: int, h: int):
    """Creates a csv file comprising of a randomly generated
    2D vector comprising of only 0 and 1.

    Probabilities a cell having either 0 or 1:

    - Cell having a value of 0 --> probability is 80%
    - Cell having a value of 1 --> probability is 20%

    This is so we can create a random csv file for our A* algorithm
    to read from that has a large chance of having a solvable grid space."""
    df = pd.DataFrame(np.random.random_integers(0, 10, (w, h)))
    df = df.applymap(lambda x: 0 if x >= 2 else 1)
    if not os.path.exists('grids'):
        os.makedirs('grids')
    df.to_csv(f'grids/grid-{w}-{h}.csv', header=None, index=False)
    # print(df)  # leave for debugging


if __name__ == '__main__':
    print('+---------------+')
    print('|   |   |   |   |')
    print('+---------------+')
    print('| Generating... |')
    print('+---------------+')
    print('|   |   |   |   |')
    print('+---------------+')
    create_random_grid(W, H)
    time.sleep(2)
    print(f'\n\nGrid with dimensions of {W}x{H} has been created in the /grid directory as grid-{W}-{H}.csv\n\n')
