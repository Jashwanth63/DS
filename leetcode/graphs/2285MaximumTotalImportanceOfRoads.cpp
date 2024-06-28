typedef long long ll;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ll ans = 0;
        unordered_map<int, vector<int>> nodes;
        vector<pair<int, int>> neighbours(n);
        for(auto &x: roads){
            pair<int, int> edge;
            edge.first = x[0];
            edge.second = x[1];
            nodes[edge.first].push_back(edge.second);
            nodes[edge.second].push_back(edge.first);

            neighbours[edge.first].first = nodes[edge.first].size();
            neighbours[edge.first].second = edge.first;

            neighbours[edge.second].first = nodes[edge.second].size();
            neighbours[edge.second].second = edge.second;
        }
        
        for(int i=0; i<n; i++){
            if(neighbours[i].first == 0){
                neighbours[i].second = i+1;
            }
        }

        sort(neighbours.begin(), neighbours.end());
        unordered_map<int, int> assigned;
        int i=1;
        assigned[neighbours[0].second] = i;
         
        for(i=1; i<n; i++){
            assigned[neighbours[i].second] = assigned[neighbours[i-1].second] + 1;
        }
        
        for(auto &x: roads){
            cout<<assigned[x[0]]<<" "<<assigned[x[1]]<<endl;
            ans += assigned[x[0]] + assigned[x[1]];
        }
         
        return ans;
    }
};