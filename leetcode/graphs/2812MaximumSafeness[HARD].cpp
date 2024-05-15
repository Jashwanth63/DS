class Solution {
public:
    bool bfsKing(vector<vector<int>> &safeness, int len, int mid, int dx[], int dy[]){
        if(safeness[0][0] < mid) return false;
        vector<vector<bool>> visited(len, vector<bool>(len, false));
        queue<pair<pair<int, int>, int>> cell;
        int i=0;
        int j=0;
        visited[0][0] = true;
        cell.push(make_pair(make_pair(i, j), safeness[0][0]));
        while(!cell.empty()){
            pair<pair<int, int>, int> curr = cell.front();
            cell.pop();
            if(curr.first.first == len-1 && curr.first.second == len-1) return true;
            for(int x=0; x<4; x++){
                int newX = curr.first.first + dx[x];
                int newY = curr.first.second + dy[x];
                if(newX>=0 && newY>=0 && newX<len && newY<len){
                    if(!visited[newX][newY] && safeness[newX][newY]>=mid){
                        cell.push(make_pair(make_pair(newX, newY), safeness[newX][newY]));
                        visited[newX][newY] = true;
                    } 
                }
            }

        }
        return false;
    }

    void bfs(vector<vector<int>> &grid, vector<vector<int>> &safeness, int i, int j, int len, int dx[], int dy[]){
        queue<pair< pair<int, int>, int> > bfsQueue; //( (x, y), safeness )
        vector<vector<bool>> visited(len, vector<bool>(len, false));
        bfsQueue.push(make_pair(make_pair(i, j), safeness[i][j]));
        visited[i][j] = true;
        while(!bfsQueue.empty()){
            pair<int, int> location = bfsQueue.front().first;
            int prevSafeness = bfsQueue.front().second;
            bfsQueue.pop();

            for(int x=0; x<4; x++){
                int newX = location.first + dx[x];
                int newY = location.second + dy[x];
                if(newX<len && newY<len && newX>=0 && newY>=0){
                    if(!visited[newX][newY] && safeness[newX][newY]!=0){
                        visited[newX][newY] = true;
                        safeness[newX][newY] = min(safeness[newX][newY], prevSafeness+1); //Manhatten Distance
                        bfsQueue.push(make_pair(make_pair(newX, newY), safeness[newX][newY]));
                    }
                    
                }
            }
        }
    }
    
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int len = grid.size();
        if(grid[0][0] == 1 || grid[len-1][len-1] == 1) return 0;
        vector<vector<int>> safeness(len, vector<int>(len, INT_MAX));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        queue<pair<int, int>> curr;
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                if(grid[i][j] == 1){
                    curr.push(make_pair(i, j));
                    safeness[i][j] = 0;
                }
            }
        }
        while(!curr.empty()){
            pair<int, int> loc = curr.front();
            int i=loc.first;
            int j=loc.second;
            curr.pop();
            bfs(grid, safeness, i, j, len, dx, dy);
        }
        


        int start = 0;
        int end = len+1;
        int ans=0;
        while(start <= end){
            int mid = (start+end)/2;
            if(bfsKing(safeness, len, mid, dx, dy))
            {
                ans = mid;
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
                
        }
        

        //Four Ways now.
        //1. Find path from 0, to n-1 using DFS, add safety of every path, for max path find smallest |V| in that path and return.
        //2. Binary search from [0, max(grid[0][0], grid[n-1][n-1])], on all safety[i][j] > mid till convergence 
        //3. Dijkstra's Algo
        //4. Union-find?
        
        /**
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                cout<<safeness[i][j]<<" ";
            }
            cout<<endl;
        }
        **/
        return ans;
    }
};