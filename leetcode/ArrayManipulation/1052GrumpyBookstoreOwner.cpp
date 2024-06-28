class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int len = customers.size();
        vector<int> grumpy2(len-minutes+1, 0);
        int sum = 0;
        vector<int> prefix(len, 0);
        for(int i=0; i<len; i++){
            sum += !grumpy[i] ? customers[i] : 0;
            prefix[i] = sum;
        }
        sum = 0;
        // Grumpy 2 (Window calculation)
        for(int i=0; i<minutes; i++){
            sum += customers[i];
        }
        grumpy2[0] = sum;
        for(int i=minutes; i<len; i++){
            sum -= customers[i-minutes];
            sum += customers[i];
            grumpy2[i-minutes+1] = sum;
        }
        //Grumpy 2 calc end
        prefix.insert(prefix.begin(), 0); // Insert 0 at beginning of prefix to avoid -1 index errors
        int last = prefix[prefix.size()-1];
        int maxSum = INT_MIN;
        for(int i=1; i<=grumpy2.size(); i++){
            int sumBefore = prefix[i-1];
            int sumAfter = last - prefix[i+minutes-1]; 
            maxSum = max(maxSum, sumBefore+grumpy2[i-1]+sumAfter);
        }
        return maxSum;
    }
};