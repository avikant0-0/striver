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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        ListNode *slow=head,*fast=head;
        while(true){
            if(fast->next == nullptr || fast->next->next == nullptr){
                return nullptr; 
            }
            slow = slow->next; 
            fast = fast->next->next; 

            if(slow == fast) break; 
        }

        fast = head;

        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }

        return slow; 
    }
};