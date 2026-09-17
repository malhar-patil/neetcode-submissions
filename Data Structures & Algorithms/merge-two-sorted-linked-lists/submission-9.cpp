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
        ListNode* ans = new ListNode(-1);
        ListNode* iter = ans;

        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                ListNode*temp = list1->next;
                iter->next = list1;
                list1=temp;
            }
            else{
                ListNode*temp = list2->next;
                iter->next = list2;
                list2=temp; 
            }
            iter=iter->next;
        }

        if(list1 != NULL){
            iter->next = list1;
        }

        if(list2 != NULL){
            iter->next = list2;
        }

        return ans->next;
    }
};
