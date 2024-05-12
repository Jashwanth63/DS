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
    bool isPalindrome(ListNode* head) {
        ListNode* start = head;
        ListNode* reversed = nullptr;
        int length=0;
        while(head!=nullptr || head->next!=nullptr){
            reversed = reverse(start->val, reversed);
            start = start->next;
            length++;
        }
        return checkPalindrome(head, reversed, length);
    }

    bool checkPalindrome(ListNode* head, ListNode* tail, int length){
        int count = 0;
        bool isPalindrome = false;
        if(length == 1){
            return true;
        }

        while(count<=((length/2))){
            if(head->val == tail->val){
                count++;
            }
            else{
                return isPalindrome;
            }
            head = head->next;
            tail = tail->next;

        }	

	    isPalindrome = true;
	    return isPalindrome;
    }

    ListNode* reverse(int val, ListNode* reversedHead){
        if(reversedHead == nullptr || reversedHead->next == nullptr){
            reversedHead = new ListNode(val);
            return reversedHead;
        }
        ListNode* newNode = new ListNode(val, reversedHead);
        reversedHead = newNode;

        return reversedHead;
    }
};