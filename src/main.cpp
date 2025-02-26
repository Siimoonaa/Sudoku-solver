#include <iostream>
#include <vector>

using namespace std;

//function to see if a number num checks the rules of Sudoku at a position (x,y)
//returns true if so and false if not
bool validator(vector<vector<int>> &matrix , int x, int y, int num) {
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
            if (matrix[i][j]==num)
                check = false;
        }
    }

    return check;
}

int main() {
    vector<vector<int>> testMatrix ={
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,4,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
    };
//    bool result = validator(testMatrix,1,4,5);
//    cout<<result;

    //printing the solution
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
                cout<<testMatrix[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}