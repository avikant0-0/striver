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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode newHead(0);
        ListNode* newHead_d = &newHead;

        while(list1 && list2){
            if(list1 -> val <= list2->val ) {
                newHead_d->next = list1; 
                list1 = list1->next;  
                newHead_d = newHead_d->next; 
            }
            else {
                newHead_d->next = list2; 
                list2 = list2->next; 
                newHead_d = newHead_d->next; 
            }
        }

        while(list1){
            newHead_d->next = list1; 
            list1 = list1->next;  
            newHead_d = newHead_d->next; 
        }
        while(list2){
            newHead_d->next = list2; 
            list2 = list2->next; 
            newHead_d = newHead_d->next; 
        }

        // newHead = newHead.next;
        return newHead.next; 
    }
};