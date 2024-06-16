class Solution {
	public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int len = capital.size();
        vector<pair<int, int>> cap(len);
        for(int i=0; i<len; i++){
            cap[i].first = capital[i];
            cap[i].second = i; 
        }
        sort(cap.begin(), cap.end());
        // Can'tdo binary search to find left index. Because elements have to be added to the max heap. So linear search.
        int stop = 0;
        int i=0;
        
        priority_queue<int> maxHeap;
        while(stop < k){
            while(i<len && (cap[i].first <= w)){
                maxHeap.push(profits[cap[i].second]);
                i++;
            }
            if(maxHeap.size() > 0){
                int temp = maxHeap.top();
                w += temp;
                maxHeap.pop();
            }
            else{
                break;
            }
            stop++;

        }
        return w;
    }
};