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
        int count = 0;
        ListNode* curr = head;

        while(curr){
            ++count;
            curr = curr->next;
        }

        count = count - n ; 

        if(count == 0){
            ListNode* temp = head;
            head = head->next; 
            delete temp;
            return head; 
        }

        curr = head;

        while(true){
            if(count == 1){
                ListNode* temp = curr -> next;
                curr->next = temp->next;
                delete temp;  

                break; 
            }
            curr = curr->next; 
            count--; 
        }

        return head; 
    }
};