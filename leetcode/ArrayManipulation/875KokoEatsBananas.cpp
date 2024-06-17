// I did it in my first try. I don't know how. 
// TODO: This is O(NlogK) where K is the max element in piles. N is the size of piles. For every binary searched K, find out how long it takes to eat all the bananas
// By looping through the array. Minimize K and return s

typedef long long ll;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e = INT_MIN;
        for(auto &x: piles) e = max(e, x);
        int possibleMin = INT_MAX;
        while(s<=e){
            int mid = s + (e-s)/2;
            ll hours = 0;
            
            for(int i=0; i<piles.size(); i++){
                hours += (ll)ceil((double)piles[i] / mid);
            }

            if(hours <= (ll)h){    
                possibleMin = min(possibleMin, mid);
                e = mid-1;
            }
            
            else{
                s = mid+1;
            }
        }
        return s;
    }
};