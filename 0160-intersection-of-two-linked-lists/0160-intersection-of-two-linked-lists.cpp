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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int nA = 0, nB = 0;
        ListNode* currA = headA;
        ListNode* currB = headB;

        while(currA || currB){
            if(currA){
                nA++;
                currA = currA->next; 
            }
            if(currB){
                nB++;
                currB = currB->next;
            }
        }

        if(nA < nB){
             swap(headA,headB);
             swap(nA,nB);
        }


        currA = headA;
        for(int i = 0; i < nA - nB; i++) currA = currA->next;

        currB = headB;

        while(currA && currB){
            if(currA == currB) return currA; 
            currA = currA -> next; 
            currB = currB -> next; 
        }

        return nullptr; 
        
    }
};