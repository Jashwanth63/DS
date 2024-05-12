#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


class Solution {
public:
    //vector<string> sudoku{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<string> sudoku{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    bool canFill(vector<vector<string>>& board, int num, int row, int col, int n){
        //Check Row and Col
        for(int i=0; i<n; i++){
            if((board[row][i] == sudoku[num-1]) || (board[i][col] == sudoku[num-1])){
                return false;
            }
        }


        //Check 3 X 3 Grid
        int subgridrow = ((row)/sqrt(n)) * sqrt(n);
        int subgridcol = ((col)/sqrt(n)) * sqrt(n);

        for(int i=subgridrow; i<subgridrow+3; i++){
            for(int j=subgridcol; j<subgridcol+3; j++){
                if((board[i][j]) == sudoku[num-1]){
                    return false;
                }
            }
        }
        return true;
    }

    bool solver(vector<vector<string>>& board, int row, int col, int n){
        //Base Case, When all rows are filled, return 
        if(row==n){
            return true;
        }
        //When at end of a row, recur from next row
        if(col==n){
            cout<<"X";
            return solver(board, row+1, 0, n);
            
        }
        //When already filled, recur from next col
        if(board[row][col] != "."){
            return solver(board, row, col+1, n);
        }
                //Recursive, Try to fill (1->9) in the recurring grids
        for(int i=1; i<=9; i++){
            if(canFill(board, i, row, col, n)){
                board[row][col] = sudoku[i-1];
                bool filled = solver(board, row, col+1, n);
                if(filled){
                    return true;
                }
            }
        }
        board[row][col] = ".";
        return false;

    }
    void solveSudoku(vector<vector<string>>& board) {
        solver(board, 0, 0, 9);
        cout<<"B";
        for(auto row: board){
            for(auto col: row){
                cout<<col<<" ";
            }
            cout<<endl;
        } 
    }
};

int main(){
    vector<vector<string>> board = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
    Solution sol = Solution();
    sol.solveSudoku(board);
    return 0;
}