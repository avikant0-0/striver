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
    bool hasCycle(ListNode *head) {
        set<ListNode*> st;
        ListNode* curr = head; 

        while(curr){
            if(st.find(curr)!=st.end()) return 1;
            st.insert(curr);
            curr = curr->next; 
        }

        return 0; 
    }
};