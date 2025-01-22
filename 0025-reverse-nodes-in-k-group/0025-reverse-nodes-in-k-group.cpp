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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;

        while(curr){
            ++n;
            curr = curr->next;
        }

        if(n <= 1){
            return head; 
        }

        int reversals = n / k;
        ListNode* dummy = new ListNode(-1);
        ListNode* d = dummy; 

        ListNode* prev = nullptr;
        curr = head; 
        ListNode* next = curr->next;

        int flag = 0; 
        ListNode* originalNode; 

        for(int i = 0; i < reversals; i++){
            originalNode = curr; 
            for(int j = 0; j < k  ; j++){
                curr ->next = prev;
                prev = curr;
                curr = next;
                if(next) next = next->next;
            }
            d->next = prev; 
            d = originalNode; 
            flag = 1;
        }

        d->next = curr;

        return dummy->next; 
    }
};