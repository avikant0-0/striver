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

        if(!list1 || !list2) {
           if(!list1) return list2;
           else if(!list2) return list1; 
           else return nullptr; 
        }
        ListNode* temp; 
        if(list1->val > list2->val) swap(list1,list2);

        ListNode* st = list1;


        while(list1 && list2){
            if(list1 && list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                if(!list1 || !list2) break;
                if(list1 && list2 && list1->val > list2->val) swap(list1,list2);
            }
        }

        while(list2) {
            temp->next = list2;
            temp = list2; 
            list2 = list2->next; 
        }

        return st; 
    }
};