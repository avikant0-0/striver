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
        ListNode* currA = headA;
        ListNode* currB = headB;


        while(true){
            if(currA != currB){
                currA = (currA ? currA->next : headB);
                currB = (currB ? currB->next : headA);
            }
            else {
                return currA;
            }
        }
        return nullptr; 
        
    }
};