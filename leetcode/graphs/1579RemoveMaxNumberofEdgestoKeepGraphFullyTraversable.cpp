class Solution {
public:
    static bool comparator(vector<int> &a, vector<int> &b){
        return a[0] > b[0];
    }

    int findParent(vector<int> &dsu, int node){
        if(dsu[node] == -1) return node;
        return findParent(dsu, dsu[node]);
    }

    void makeGraph(vector<int> &dsu, vector<int> &edge, unordered_map<int, int> &counts, int type){
        int s1 = findParent(dsu, edge[1]);
        int s2 = findParent(dsu, edge[2]);
        if(s1 != s2){
            counts[type]++;
            dsu[s2] = s1;
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> dsu(n+1, -1);
        vector<int> dsuCopy1;
        vector<int> dsuCopy2;
        int count = 0;
        int len = edges.size();
        sort(edges.begin(), edges.end(), comparator);
        unordered_map<int, int> counts;
        counts[1]=counts[2]=counts[3]=0;
        for(int i=0; i<len; i++){
            if(edges[i][0] == 1){
                if(dsuCopy1.size() == 0) dsuCopy1 = dsu;
                makeGraph(dsuCopy1, edges[i], counts, edges[i][0]);
            }
            else if(edges[i][0] == 2){
                if(dsuCopy2.size() == 0) dsuCopy2 = dsu;
                makeGraph(dsuCopy2, edges[i], counts, edges[i][0]);
            } 
            else{
                makeGraph(dsu, edges[i], counts, edges[i][0]);
            }            
        }

        if( ((counts[3]+counts[1]) != n-1) || ((counts[3]+counts[2]) != n-1) ) return -1;
        return len - (counts[3] + counts[1] + counts[2]);

    }
};