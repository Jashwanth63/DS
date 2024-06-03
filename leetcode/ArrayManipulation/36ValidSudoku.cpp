class Solution {
public:
    bool checkUp(vector<vector<char>>& board, int i, int j, int nrow, int ncol){
        char element = board[i][j];
        if(element == '.') return true;
        i--;
        while(i>=0){
            if(board[i--][j]==element) return false;
        }
        return true;
    }

    bool checkDown(vector<vector<char>>& board, int i, int j, int nrow, int ncol){
        char element = board[i][j];
        if(element == '.') return true;
        i++;
        while(i<nrow){
            if(board[i++][j] == element) return false;
        }
        return true;
    }

    bool checkRight(vector<vector<char>>& board, int i, int j, int nrow, int ncol){
        char element = board[i][j];
        if(element == '.') return true;
        j++;
        while(j<ncol){
            if(board[i][j++] == element) return false;
        }
        return true;
    }

    bool checkLeft(vector<vector<char>>& board, int i, int j, int nrow, int ncol){
        char element = board[i][j];
        if(element == '.') return true;
        j--;
        while(j>=0){
            if(board[i][j--] == element) return false;
        }
        return true;
    }
    
    bool checkBox(vector<vector<char>>& board, int i, int j, int nrow, int ncol){
        char element = board[i][j];
        if(element == '.') return true;
        int startRow = (i/3)*3;
        int startCol = (j/3)*3;
        for(int x=startRow; x<startRow+3; x++){
            for(int y=startCol; y<startCol+3; y++){
                if(x!=i && y!=j && board[x][y]==element) return false;
            }
        }
        return true;
    }
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int nrow = 9;
        int ncol = 9;
        for(int i=0; i<nrow; i++){
            for(int j=0; j<ncol; j++){
                if(checkUp(board, i, j, nrow, ncol) && checkDown(board, i, j, nrow, ncol) && checkLeft(board, i, j, nrow, ncol) && checkRight(board, i, j, nrow, ncol) && checkBox(board, i, j, nrow, ncol)) continue;
                else return false;
            }
        }

        return true;

    }

};
