/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(!head) return 0; 
        
        ListNode* slow = head; 
        ListNode* fast = head->next;

        while(fast){
            if(slow == fast) return 1;
            slow = slow->next;
            if(fast->next) fast = fast->next->next;
            else return 0; 
        }

        return 0; 
    }
};