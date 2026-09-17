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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;


        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* list2 = slow->next;
        slow->next=NULL;
        ListNode* list1 = head;

        //reverse list2;
        ListNode* prev = NULL;
        ListNode* curr = list2;

        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        list2 = prev;
        // while(prev!=NULL){
        //     cout<<prev->val<<" ";
        //     prev=prev->next;
        // }

        while(list2!=NULL){
            ListNode*temp = list1->next;
            ListNode*temp2 = list2->next;
            list1->next = list2;
            list1=list1->next;
            list1->next = temp;
            list1=list1->next;
            list2 = temp2;
        }

        if(list2!=NULL){
            list1->next = list2;
        }

        return;
    }
};
