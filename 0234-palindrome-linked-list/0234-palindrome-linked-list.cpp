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

        ListNode *slow = head, *fast = head;

        while(true){
            if(fast -> next == NULL || fast -> next -> next == NULL){
                break;
            }
            slow = slow->next;
            fast = fast->next->next; 
        }

        ListNode* prev = nullptr,*curr = slow->next, *next = (curr ? curr->next : nullptr) ; 
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = next; 
            if(next) next = next->next; 
        }
        slow->next = prev;

     

        ListNode* d1 = head, *d2 = slow->next;

        while(d1 && d2){
            if(d1->val != d2->val) return false;
            d1 = d1->next;
            d2 = d2->next;
        }

        return true; 
    }
};