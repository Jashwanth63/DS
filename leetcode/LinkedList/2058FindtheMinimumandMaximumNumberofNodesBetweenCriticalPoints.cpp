/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ios_base::sync_with_stdio(false);
        vector<int> threes(3, -1);
        vector<int> indices;
        int MINIMUM = INT_MAX;
        int i = 0;
        while(head!= nullptr && i<3){
            if(i<3){
                threes[i] = head->val;
            }
            i++;
            head = head->next;
        }

        while(head!= nullptr){
            if(threes[1] < threes[0] && threes[1] < threes[2]){
                indices.push_back(i-2);
            }
            if(threes[1] > threes[0] && threes[1] > threes[2]){
                indices.push_back(i-2);
            }
            
            threes[0] = threes[1];
            threes[1] = threes[2];
            threes[2] = head->val;    
            i++;
            head = head->next;

            if(indices.size() >= 2){
                MINIMUM = min(MINIMUM, indices[indices.size()-1]-indices[indices.size()-2]); 
            }
        }
        if(threes[1] < threes[0] && threes[1] < threes[2]){
            indices.push_back(i-2);
            if(indices.size() >= 2){
                MINIMUM = min(MINIMUM, indices[indices.size()-1]-indices[indices.size()-2]); 
            }
        }

        if(threes[1] > threes[0] && threes[1] > threes[2]){
            indices.push_back(i-2);
            if(indices.size() >= 2){
                MINIMUM = min(MINIMUM, indices[indices.size()-1]-indices[indices.size()-2]); 
            }
        }
        int len = indices.size();
        if(i<3 || len<2) return {-1, -1};
        return {MINIMUM, indices[len-1] - indices[0]};
    }
};