#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int count;
    bool isSafe(vector<string> &arr, int row, int col, int n){
        
        //Vertical
        for(int i=row-1; i>=0; i--){
            if(arr[i][col] == 'Q'){
                return false;
            }
        }
    
        int i = row-1;
        int j = col-1;

        //Left Diagonal
        while(i>=0 && j>=0){

            if(arr[i][j] == 'Q'){
                return false;
            }
            --i;
            --j;
        }
        col = col+1;
        row = row-1;
        //Right Diagonal
        while(row>=0 && col<=n-1){
            if(arr[row][col] == 'Q'){
                return false;
            }
            row--;
            col++;
        }
        return true;
    }
    
    bool nqueens(vector<string> &arr, int &count, int i, int n){
        if(i==n){
            count++;
            return false;
        }
        for(int col=0; col<n; col++){
            if(isSafe(arr, i, col, n)){
                arr[i][col] = 'Q';
                bool hasBeenPlaced = nqueens(arr, count, i+1, n);

                if(hasBeenPlaced){
                    return true;
                }
                arr[i][col] = '.';
            }
        }
        return false;
    }
    int totalNQueens(int n) {
        int count=0;
        vector<string> board;
        string s(n, '.');
        for(int i=0; i<n; i++){
            board.push_back(s);
        }
        nqueens(board, count, 0, n);
        return count;
    }
};

int main(){
    Solution sol = Solution();
    int ans = sol.totalNQueens(4);
    cout<<ans;
    

    return 0;
}