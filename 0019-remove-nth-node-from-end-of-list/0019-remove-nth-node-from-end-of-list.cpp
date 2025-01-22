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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = nullptr;
        ListNode* fast = nullptr;
        // ListNode* 

        int count = 0; 
        while(count < n){
            ++count;
            if(fast == nullptr){
                fast = head;
            }
            else fast = fast -> next; 
        }

        while(fast -> next != nullptr){
            if(slow == nullptr) slow = head; 
            else slow = slow->next; 
            fast = fast->next; 
        }

        if(slow ==  nullptr){
            ListNode* temp = head;
            head = head -> next; 
            delete temp; 
            return head;
        }

        ListNode* temp = slow -> next;
        slow->next = temp->next; 
        delete temp;
        return head; 

    }
};