#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Structure to represent a cell in the labyrinth
struct Cell {
    int row, col;
    Cell(int r, int c) : row(r), col(c) {}
};

// Function to check if a given cell is within the boundaries of the labyrinth
bool isValidCell(int row, int col, int numRows, int numCols) {
    return (row >= 0 && row < numRows && col >= 0 && col < numCols);
}

// Function to check if a given cell is safe (contains '.')
bool isSafeCell(vector<vector<char>>& labyrinth, int row, int col) {
    return (labyrinth[row][col] == '.');
}

// Function to perform BFS to find the path to the safe boundary
bool findSafeBoundary(vector<vector<char>>& labyrinth, Cell start) {
    int numRows = labyrinth.size();
    int numCols = labyrinth[0].size();

    // Arrays to define the possible movements in 4 directions (up, down, left, right)
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Queue for BFS
    queue<Cell> q;

    // Mark the start cell as visited
    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
    visited[start.row][start.col] = true;

    // Enqueue the start cell
    q.push(start);

    // Perform BFS
    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();

        // Check if the current cell is at the safe boundary
        if (curr.row == 0 || curr.row == numRows - 1 || curr.col == 0 || curr.col == numCols - 1) {
            return true;
        }

        // Explore the neighboring cells
        for (int i = 0; i < 4; i++) {
            int newRow = curr.row + dr[i];
            int newCol = curr.col + dc[i];

            // Check if the neighboring cell is a valid and safe cell
            if (isValidCell(newRow, newCol, numRows, numCols) &&
                !visited[newRow][newCol] &&
                isSafeCell(labyrinth, newRow, newCol)) {
                
                // Mark the neighboring cell as visited and enqueue it
                visited[newRow][newCol] = true;
                q.push(Cell(newRow, newCol));
            }
        }
    }

    // If no safe boundary cell is found
    return false;
}

int main() {
    // Example labyrinth
    vector<vector<char>> labyrinth = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '#', '.', '.', '.', '#', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '.', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    int numRows = labyrinth.size();
    int numCols = labyrinth[0].size();

    // Find the starting cell (cell A)
    Cell start(-1, -1);
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (labyrinth[row][col] == 'A') {
                start = Cell(row, col);
                break;
            }
        }
        if (start.row != -1)
            break;
    }

    // Check if a path to the safe boundary exists
    bool pathExists = findSafeBoundary(labyrinth, start);

    if (pathExists) {
        cout << "A path to the safe boundary exists!" << endl;
    } else {
        cout << "No path to the safe boundary exists!" << endl;
    }

    return 0;
}
