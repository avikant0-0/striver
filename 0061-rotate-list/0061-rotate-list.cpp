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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head) return head; 
        int len = 1;
        ListNode* curr = head;

        while(curr->next){
            ++len;
            curr = curr->next;
        }

        curr->next = head; 

        k = k % len ;
        k = len - k ;

        int t = 0 ;
        curr = head; 
        while( t <= k-1){
            if(t == k-1){
                ListNode *start = curr->next;
                curr->next = nullptr; 
                return start; 
            }
            curr = curr->next;
            ++t;
        }

        return nullptr;
    }
};