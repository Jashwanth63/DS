class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int totalNodes = n;
        unordered_map<int, vector<pair<int, int>> > adj(n);
        int sourceNode = k;
        //Make adj list with map, key will be source, value will be the edges will associated weights.
        for(auto conn : times){
            // conn[0] = ui(source), conn[1] = vi(dest), conn[2] = latency
            adj[conn[0]].push_back(make_pair(conn[1], conn[2])); // 1 -> [(2,3), (3,4)]
        }

        set<pair<int, int>> minDist; ///First is distance, second is Node Number 
        vector<long> dist(totalNodes, LONG_MAX);

        dist[sourceNode-1] = 0;

        minDist.insert(make_pair(dist[sourceNode-1], sourceNode)); 

        while(!minDist.empty()){
            pair<int, int> front = *minDist.begin(); // get first node in set. this can be removed as min for this node has been found

            minDist.erase(minDist.begin());

            for(pair<int, int> edges : adj[front.second]){
                //swap(edges.first, edges.second);
                if((long)front.first + edges.second <  dist[edges.first-1]){
                    auto toErase  = make_pair(dist[edges.first-1], edges.first);
                    if(minDist.find(toErase) != minDist.end()){
                        // Remove that pair from the set, insert new pair for the node with the new minimum distance
                        minDist.erase(toErase);
                    }
                    int newDist = front.first + edges.second;
                    minDist.insert(make_pair(newDist, edges.first));
                    dist[edges.first-1] = newDist;
                }
            }
        }
        long totalTime = LONG_MIN;
        for(long distance : dist){
            totalTime = max(distance, totalTime);
        }

        return totalTime!=LONG_MAX ? (int)totalTime : -1;

    }
};