#include <iostream>
using namespace std;

#define N 9

void printGrid(int grid[N][N]) {
    cout << "\nSudoku Board:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}


bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++)
        if (grid[row][i] == num || grid[i][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool isComplete(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num = grid[i][j];
            if (num == 0) return false;

            grid[i][j] = 0;
            if (!isSafe(grid, i, j, num)) {
                grid[i][j] = num;
                return false;
            }
            grid[i][j] = num;
        }
    }
    return true;
}

int main() {

   
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    int original[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            original[i][j] = grid[i][j];

    int row, col, num;

    while (true) {
        printGrid(grid);

        cout << "\nEnter row col number (0-8 index) or -1 to exit: ";
        cin >> row;

        if (row == -1) break;

        cin >> col >> num;

        if (original[row][col] != 0) {
            cout << " Cannot change predefined values!\n";
            continue;
        }

        if (num < 1 || num > 9) {
            cout << " Enter number between 1-9!\n";
            continue;
        }

        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            cout << " Correct move!\n";
        } else {
            cout << " Wrong move!\n";
        }

        if (isComplete(grid)) {
            cout << "\n Congratulations! You solved the Sudoku!\n";
            printGrid(grid);
            break;
        }
    }

    return 0;
}
