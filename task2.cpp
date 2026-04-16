#include <iostream>
using namespace std;

#define N 9

// Check if move is valid
bool isSafe(int grid[N][N], int row, int col, int num) {

    for(int x = 0; x < N; x++)
        if(grid[row][x] == num)
            return false;

    for(int x = 0; x < N; x++)
        if(grid[x][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Print board
void printGrid(int grid[N][N]) {
    cout << "\nSudoku Board:\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if completed
bool isComplete(int grid[N][N]) {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(grid[i][j] == 0)
                return false;
    return true;
}

int main() {

    int grid[N][N] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    int row, col, num;

    while(!isComplete(grid)) {
        printGrid(grid);

        cout << "\nEnter row (0-8), column (0-8), number (1-9): ";
        cin >> row >> col >> num;

        if(grid[row][col] != 0) {
            cout << "Cell already filled!\n";
            continue;
        }

        if(isSafe(grid, row, col, num)) {
            grid[row][col] = num;
        } else {
            cout << "Invalid move!\n";
        }
    }

    cout << "\n Sudoku Solved!\n";
    printGrid(grid);

    return 0;
}
