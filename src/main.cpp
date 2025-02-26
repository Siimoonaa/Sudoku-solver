#include <iostream>
#include <vector>

using namespace std;

//function to see if a number num checks the rules of Sudoku at a position (x,y)
//returns true if so and false if not
bool validator(vector<vector<int>> &matrix, int x, int y, int num) {
    //checking the row
    for (int i = 0; i < 9; ++i) {
        if (matrix[x][i] == num)
            return false;
    }

    //checking the column
    for (int i = 0; i < 9; ++i) {
        if (matrix[i][y] == num)
            return false;
    }

    //checking the box
    int beginRow = x - x % 3;
    int beginColumn = y - y % 3;
    bool check = true;
    for (int i = beginRow; i < beginRow + 3; ++i) {
        for (int j = beginColumn; j < beginColumn + 3; ++j) {
            if (matrix[i][j] == num)
                check = false;
        }
    }

    return check;
}

//recursive function to solve the Sudoku
bool solver(vector<vector<int>> &matrix, int row, int column) {
    int n = 9;

    //checking to see if we got to the end of Sudoku
    if (row == n - 1 && column == n)
        return true;

    //checking to see if we got to the end of the row
    if (column == n) {
        column = 0;
        row++;
    }

    //checking if the cell has already a number in it
    if (matrix[row][column] != 0)
        solver(matrix, row, column + 1);

    for (int i = 1; i <= 9; ++i) {
        if (validator(matrix, row, column, i)) {
            matrix[row][column] = i;
            if (solver(matrix, row, column + 1))
                return true;
            matrix[row][column] = 0;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> testMatrix = {
            {7, 0, 9, 0, 5, 0, 1, 0, 3},
            {0, 4, 0, 1, 0, 6, 0, 9, 0},
            {1, 0, 2, 0, 9, 0, 0, 6, 8},
            {5, 0, 4, 0, 0, 1, 0, 0, 2},
            {0, 1, 0, 6, 0, 4, 0, 3, 0},
            {6, 0, 0, 5, 0, 9, 0, 1, 0},
            {0, 8, 0, 0, 1, 0, 0, 5, 0},
            {0, 7, 0, 3, 0, 5, 0, 0, 6},
            {0, 0, 0, 9, 6, 0, 3, 0, 1}
    };

    //calling the function that solves the Sudoku
    bool done = solver(testMatrix, 0, 0);

    //printing the solution
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << testMatrix[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}