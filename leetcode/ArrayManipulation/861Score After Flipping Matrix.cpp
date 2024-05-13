/**
 * 
 *
 * 
 * 
 * 

Flip bits in row if row starts with 0 (1000 is bigger than 0111).

After iterating row-wise, iterate from second column (Because the first columns values have already been maximized in the first operation).

Now, count number of set bits for each column. If count<=row/2, flipping would maximize the result.

If you had [ [1,0,1,0], [1,1,1,0], [1,1,1,1] ] as your grid, the last column has a count of 1. 
Here, 1<=(row/2) where row=2 (Starting from 0, so three rows). The current values of each row is 10, 14 and 15 respectively. 
If we flipped the bits of the last column, we would end up with (10+1), (14+1), (15-1). 
We are adding 2 to the total and reducing 1, making the net gain 1 and hence maximizing it. 
Same applies to other columns as well (Except the first column because its value is already maximized).
Complexity

Time complexity: O(N*M)
Space complexity: O(M)

 *
 * 
 * 
 * 
 * 
 * 
 *  
 **/

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        bool changing = false;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if((j==0 && grid[i][j] == 0) || changing){
                    changing = true;
                    grid[i][j] = !grid[i][j];
                }
                else{
                    break;
                }
            }
            changing = false;
        }
        int half = rows/2;
    
        for(int j=1; j<cols; j++){
            int count =0;
            for(int i=0; i<rows; i++){
                if(grid[i][j] == 1) count++;        
            }
            if(count<=half) // if less than half the rows are 1, flipping would result in a bigger number, if not leave it be
            {
                for(int i=0; i<rows; i++){
                    grid[i][j] = !grid[i][j];
                }    
            }
            changing = false;
        }

        unsigned long sum =0;
        
        for(int i=0; i<rows; i++){
            string temp="";
            for(int j=0; j<cols; j++){
                temp += grid[i][j] + '0';
            }
            bitset<20> curr(temp);
            sum += curr.to_ulong();
        }

        return (int)sum;
        
    }
};