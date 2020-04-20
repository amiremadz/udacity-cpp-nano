"""
Main file to run the main.cpp file and the random grid generator file
"""

import subprocess
import argparse

parser = argparse.ArgumentParser(description='Give the size of rows and columns for the grid.csv\n')
parser.add_argument('rows', type=int, help='Rows in the grid.csv')
parser.add_argument('columns', type=int, help='Columns in the grid.csv')
parser.add_argument('difficulty', type=int, help='Grid difficulty setting')
args = parser.parse_args()

# Constants passed from user
ROWS = args.rows
COLS = args.columns
DIFFICULTY = args.difficulty


def main(rows: int, cols: int, difficulty: int):
    subprocess.run(["python", "random_grid.py", str(rows), str(cols), str(difficulty)])
    subprocess.run(["clang++", "-std=c++17", "main.cpp", "-o", "grid.search"])
    subprocess.run(['./grid.search'])


if __name__ == "__main__":
    main(ROWS, COLS, DIFFICULTY)
