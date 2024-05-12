#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    
    bool canPlace(vector<string> board, int row, int col, int n){
        //Check vertical
        for(int i=row; i>=0;i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        //Check left diagonal
        int i = row;
        int j = col;
        while(i>=0 && j>=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }

        //Check Right Diagonal
        while(row>=0 && col>=n-1){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col++;
        }

        //Its safe
        return true;
    }

    void nqueens(vector<string> &board, vector<vector<string>> &ans, int i, int n){
        if(i==n){
            ans.push_back(board);
            return;
        }
        
        for(int col=0; col<n; col++){
            if(canPlace(board, i, col, n)){
                board[i][col] = 'Q';
               	nqueens(board, ans, i+1, n);
	            board[i][col] = '.';
            }
        }
        return;
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string s(n, '.');
        for(int i=0; i<n; i++){
        	board.push_back(s);
        }
        vector<vector<string>> ans;
        cout<<"C";
        nqueens(board, ans, 0, n);
        return ans;
    }
};


int main(){
	Solution sol = Solution();
	vector<vector<string>> ans = sol.solveNQueens(4);
	cout<<"B";
	for(auto solution: ans){
		for(auto row: solution){
			cout<<row;
		}
		cout<<endl;
	}

	return 0;
}