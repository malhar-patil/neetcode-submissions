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
        ListNode* ans = new ListNode();
        ListNode* temp = ans;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                ListNode* tempList = list1->next;
                list1->next=NULL;
                temp->next = list1;
                temp = temp->next;
                list1 = tempList;
            }
            else{
                ListNode* tempList = list2->next;
                list2->next=NULL;
                temp->next = list2;
                temp = temp->next;
                list2 = tempList;
            }
        }

        if(list1 != NULL){
            temp->next = list1;
        }
        if(list2 != NULL){
            temp->next = list2;
        }

        return ans->next;
    }
};
