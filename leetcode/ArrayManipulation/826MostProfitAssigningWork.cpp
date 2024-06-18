// Method 1
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        //ranges::sort(worker); // Can do this with min heap
        priority_queue<int, vector<int>, greater<int> > workerMinHeap;
        int maxWorker = INT_MIN;
        for(int i=0; i<worker.size(); i++){
            maxWorker = max(worker[i], maxWorker);
            workerMinHeap.push(worker[i]);
        }
        int len = difficulty.size();
        vector<pair<int, int>> diffProfit(len);
        for(int i=0; i<len; i++){
            diffProfit[i].first = difficulty[i];
            diffProfit[i].second = profit[i];
        }
        ranges::sort(diffProfit);

        int totalProfit = 0;
        if(diffProfit[0].first > maxWorker) return 0;
        int possibleMax = INT_MIN;
        int possibleMaxIndex = 0;
        while(!workerMinHeap.empty()){
            int top = workerMinHeap.top();
            workerMinHeap.pop();
            for(int j=possibleMaxIndex; j<len; j++){
                if(diffProfit[j].first > top){
                    possibleMaxIndex = j;
                    break;
                }
                possibleMax = max(possibleMax, diffProfit[j].second);
                //cout<<possibleMax;
            }
            if(possibleMax != INT_MIN) totalProfit += possibleMax;
            
        }
        return totalProfit;
    }
};

//Method 2
class Solution {
// There is an optimal solution for this, Current Complexity, O(nlogn + mlogm)
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        ranges::sort(worker); // Can do this with min heap as well. 
        //priority_queue<int, vector<int>, greater<int> > workerMinHeap;
        // int maxWorker = INT_MIN;
        // for(int i=0; i<worker.size(); i++){
        //     maxWorker = max(worker[i], maxWorker);
        //     workerMinHeap.push(worker[i]);
        // }
        int len = difficulty.size();
        vector<pair<int, int>> diffProfit(len);
        for(int i=0; i<len; i++){
            diffProfit[i].first = difficulty[i];
            diffProfit[i].second = profit[i];
        }
        ranges::sort(diffProfit);

        int totalProfit = 0;
        if(diffProfit[0].first > worker[worker.size()-1]) return 0;
        int possibleMax = INT_MIN;
        int possibleMaxIndex = 0;
        for(int i=0; i<worker.size(); i++){
            for(int j=possibleMaxIndex; j<len; j++){
                if(diffProfit[j].first > worker[i]){
                    possibleMaxIndex = j;
                    break;
                }
                possibleMax = max(possibleMax, diffProfit[j].second);
            }
            if(possibleMax != INT_MIN) totalProfit += possibleMax;
            
        }
        return totalProfit;
    }
};